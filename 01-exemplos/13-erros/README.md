# Aula 13 — Lendo erros do compilador e crashes

⏱️ ~9 minutos · Arquivos: pasta [`quebrados/`](quebrados/) (eles **não compilam ou quebram de propósito**)

## A ideia central

Mensagem de erro em C assusta, mas tem uma estrutura fixa. A primeira pergunta é sempre: **qual etapa reclamou?** (aula 02)

| Quem reclama | Cara da mensagem | Significa |
|---|---|---|
| Compilador | `arquivo.c:17:28: error: ...` | problema de sintaxe ou tipo **no seu arquivo** |
| Linker | `undefined reference to ...`, `ld returned 1 exit status` | uma peça está **faltando** na hora de juntar |
| Execução | `Segmentation fault`, `echo $?` = `139` | compilou, mas o programa acessou memória proibida |

## Anatomia de uma mensagem do compilador

```bash
cd quebrados
cc -Wall -Wextra -Werror falta_ponto_virgula.c
```

```
falta_ponto_virgula.c: In function 'main':
falta_ponto_virgula.c:17:28: error: expected ';' before 'return'
   17 |         write(1, "oi\n", 3)
      |                            ^
      |                            ;
   18 |         return (0);
```

- `falta_ponto_virgula.c:17:28` = **arquivo:linha:coluna**. No VS Code, `Ctrl+G` vai direto para a linha.
- `error:` + a descrição.
- O `^` aponta o lugar exato, e às vezes ele até sugere a correção (`;`).

> 💡 Regras de ouro:
> 1. **Leia o primeiro erro e ignore o resto.** Um erro costuma causar uma cascata de outros. Corrija o primeiro e compile de novo.
> 2. O erro às vezes aparece **na linha seguinte** ao problema real (como acima: o `;` faltou na 17, e ele percebeu ao ver o `return`).

## `implicit declaration of function`

```bash
cc -Wall -Wextra -Werror implicit_declaration.c
```

```
implicit_declaration.c:15:9: error: implicit declaration of function 'ft_putchar' [-Werror=implicit-function-declaration]
   15 |         ft_putchar('a');
cc1: all warnings being treated as errors
```

**Tradução:** "você chamou `ft_putchar`, mas eu nunca vi a declaração dela **até esta linha**."

Causas:
- A função está definida **depois** de quem chama e não tem protótipo (aula 02).
- Faltou um `#include` (por exemplo, usar `write` sem `#include <unistd.h>`, ou `malloc` sem `<stdlib.h>`).
- Erro de digitação no nome (`ft_putchr`).

`cc1: all warnings being treated as errors`: era um aviso, mas o `-Werror` transformou em erro.

## `undefined reference to`

```bash
cc -Wall -Wextra -Werror undefined_reference.c
```

```
/usr/bin/ld: /tmp/ccWV17VT.o: in function `main':
undefined_reference.c:(.text+0xe): undefined reference to `ft_putchar'
collect2: error: ld returned 1 exit status
```

`ld` é o linker. **Tradução:** "a declaração existe (o protótipo), mas a função de verdade não está em nenhum arquivo que você me passou."

Causas:
- Esqueceu de passar o arquivo `.c` da função no comando `cc`.
- Nome diferente entre o protótipo e a definição.
- `undefined reference to 'main'`: você compilou um arquivo de função **sozinho**, sem um `main.c`. Normal nos exercícios: compile junto com o seu teste.

O inverso também acontece: `multiple definition of 'main'` (ou de outra função) = a mesma função existe em dois arquivos.

## Avisos que viram erro com `-Werror`

```bash
cc -Wall -Wextra -Werror variavel_nao_usada.c
```

```
variavel_nao_usada.c:15:17: error: unused variable 'nao_uso' [-Werror=unused-variable]
```

Os mais comuns na Piscine:

| Mensagem | Causa |
|---|---|
| `unused variable 'x'` | declarou e não usou: apague |
| `unused parameter 'x'` | parâmetro não usado (`-Wextra`) |
| `'x' is used uninitialized` | leu antes de dar valor |
| `control reaches end of non-void function` | função `int` sem `return` em algum caminho |
| `suggest parentheses around assignment` | `=` no lugar de `==` |
| `comparison between pointer and integer` | ex.: `str[i] == "a"` (aspas duplas). Use `'a'` |

## `Segmentation fault`: compilou, mas quebrou

*Segmentation fault* (*segfault*) = o programa tentou acessar memória que não é dele, e o sistema o matou.

```bash
cc -Wall -Wextra -Werror segfault.c && ./a.out ; echo "codigo: $?"
```

```
vou tentar mudar um literal...
Segmentation fault (core dumped)
codigo: 139
```

```bash
cc -Wall -Wextra -Werror null.c && ./a.out ; echo "codigo: $?"
```

```
ft_strlen(NULL)...
Segmentation fault (core dumped)
codigo: 139
```

Causas clássicas:
1. Escrever num literal (`str = "abc"; str[0] = 'x';`).
2. Acessar `NULL` (`*p` com `p == NULL`; `ft_strlen(NULL)`).
3. Índice fora do array, ou string sem `'\0'` (o laço passa do fim).
4. Usar memória depois do `free`.
5. Recursão sem caso base (estouro da stack).

### Como achar a linha do segfault

Com `-g` e o `valgrind`:

```bash
cc -Wall -Wextra -Werror -g null.c && valgrind ./a.out
```

O `valgrind` mostra algo como `Invalid read of size 1 ... at ft_strlen (null.c:<linha>)` e `Address 0x0 is not stack'd, malloc'd or (recently) free'd`. **Address 0x0** = você acessou `NULL`.

Outra opção rápida: compilar com `-fsanitize=address -g`. O programa para no erro e mostra a linha.

## E o que a Moulinette faz com isso?

Se seu código não compila com as flags, ou dá segfault, aquele exercício é considerado errado. Por isso: **compile sempre com `-Wall -Wextra -Werror`**, desde o primeiro exercício.

## É normal estranhar

As mensagens parecem escritas para máquinas. Em poucos dias você vai bater o olho e reconhecer: "ah, implicit declaration, faltou include". Aqui vai um atalho: copie a parte em inglês do erro (sem nomes de arquivo) e procure no `man` ou nas suas anotações.

## Mini-exercício

Corrija os 6 arquivos de [`quebrados/`](quebrados/) **numa cópia** (não altere os originais), sem apagar a intenção de cada um, até todos compilarem com as flags e rodarem sem segfault.

## Perguntas de fixação

1. `undefined reference` vem do compilador ou do linker?
2. Qual a causa mais provável de `implicit declaration of function 'write'`?
3. O que significa o código de saída `139`?
4. Num erro `x.c:42:5`, o que são 42 e 5?
5. Por que corrigir só o primeiro erro e recompilar?

<details>
<summary>Respostas</summary>

1. Do linker (`ld`).
2. Faltou `#include <unistd.h>`.
3. O programa foi morto por *segmentation fault* (128 + sinal 11).
4. Linha 42, coluna 5.
5. Porque um erro costuma gerar vários outros em cascata; corrigido o primeiro, muitos dos seguintes somem.

</details>
