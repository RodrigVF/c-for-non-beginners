# Aula 01 — Anatomia de um programa em C

⏱️ ~7 minutos · Arquivos: [`ola.c`](ola.c), [`saida.c`](saida.c)

## A ideia central

Em Python ou JavaScript, você escreve o código e um programa (o interpretador) lê e executa linha por linha.

Em C, **não existe ninguém lendo seu código na hora de rodar**. Um compilador traduz tudo para linguagem de máquina **antes**, e o que roda é esse arquivo binário. Por isso C é tão "formal": o compilador precisa saber tudo com antecedência.

> 💡 Analogia: Python é um intérprete simultâneo numa palestra. C é um tradutor que recebe o livro inteiro, traduz, e entrega o livro pronto. Se uma frase não faz sentido, ele devolve o livro sem traduzir nada.

## O menor programa útil

```c
#include <unistd.h>

int	main(void)
{
	write(1, "Ola, Piscine!\n", 14);
	return (0);
}
```

Vamos linha por linha.

### `#include <unistd.h>`

Traz para o seu arquivo as **declarações** de funções do sistema, entre elas `write`.
Sem isso, o compilador não sabe que `write` existe nem quais parâmetros recebe.
(O `#` indica que é uma instrução para o **pré-processador**, que você vai ver na aula 02.)

### `int	main(void)`

- `main` é **onde o programa começa**. Sempre. Não tem como escolher outro nome.
- `int` antes do nome: a função **devolve um inteiro**. Em C, todo tipo é declarado.
- `(void)`: a função **não recebe parâmetros**. Em C, `()` vazio tem um significado antigo e ambíguo; `(void)` deixa explícito.
- Aquele espaço entre `int` e `main` é um **tab**. É exigência da Norma da 42, não da linguagem.

### `{ }` — o bloco

Chaves delimitam o corpo da função. Indentação em C **não tem significado** (diferente de Python). A Norma exige indentação só para legibilidade.

### `;` — fim de instrução

Cada instrução termina com `;`. Por quê? Porque C ignora quebras de linha: para o compilador, o arquivo é uma sequência de símbolos. O `;` é o "ponto final" da frase.

### `write(1, "Ola, Piscine!\n", 14);`

`write` é uma chamada direta ao sistema operacional (uma *syscall*):

| Parâmetro | Significado |
|---|---|
| `1` | onde escrever: `0` = entrada, `1` = saída padrão (stdout), `2` = saída de erro (stderr) |
| `"Ola..."` | o endereço onde os bytes começam |
| `14` | **quantos bytes** escrever |

Repare: você precisa dizer quantos bytes. `write` não sabe onde o texto termina. Isso é bem C: nada é automático.

### `return (0);`

O valor que `main` devolve vira o **código de saída** do programa. Por convenção:
- `0` = deu tudo certo
- qualquer outro valor = algo deu errado

Os parênteses em `return (0)` são exigência da Norma. Para a linguagem, `return 0;` também vale.

## Testando: compilar e rodar

```bash
cc -Wall -Wextra -Werror ola.c
./a.out
```

- `cc` é o compilador. Sem `-o nome`, ele gera um arquivo chamado `a.out`.
- `./a.out`: o `./` diz "o arquivo desta pasta". O shell não procura programas na pasta atual por segurança.
- `-Wall -Wextra -Werror`: liga avisos e **transforma todo aviso em erro**. É como a 42 compila. Acostume-se desde já.

Para dar nome ao executável:

```bash
cc -Wall -Wextra -Werror ola.c -o ola
./ola
```

## O código de saída com `echo $?`

```bash
cc -Wall -Wextra -Werror saida.c -o saida
./saida
echo $?
```

Saída:
```
Vou sair com o codigo 42. Rode: echo $?
42
```

`$?` é uma variável do shell que guarda o código de saída do **último** comando. Se você rodar `echo $?` duas vezes, a segunda mostra `0` (o código do primeiro `echo`).

> 💡 Por que isso importa? Scripts e a Moulinette podem olhar esse código. E quando seu programa quebra com *segmentation fault*, `echo $?` mostra `139`.

## Desenho: do arquivo ao processo

```
 ola.c (texto)          a.out (binário)          processo rodando
┌──────────────┐  cc   ┌──────────────┐  ./a.out  ┌──────────────┐
│ int main ... │ ────> │ 0101 1100... │ ───────>  │ main() roda  │
└──────────────┘       └──────────────┘           │ return (0)   │──> $? = 0
                                                  └──────────────┘
```

## Um aviso sobre os trechos de código das aulas

A partir da próxima aula, alguns trechos terão comentários `/* ... */` dentro das funções, para explicar o que cada linha faz. A Norma **proíbe** comentários dentro de funções: nos seus exercícios, não faça isso. Os arquivos `.c` das aulas seguem a regra.

## É normal estranhar

- "Por que preciso contar os bytes no `write`?" Porque em C quase nada é automático. Isso vai ficar natural quando você escrever `ft_putstr`.
- "Por que tantas regras de espaço e tab?" Metade é a linguagem, metade é a Norma da 42. Nas aulas, eu aviso qual é qual.

## Mini-exercício

Escreva `meu_nome.c`, que imprime seu nome e uma quebra de linha e termina com código de saída `7`. Compile com as flags e confirme com `echo $?`.

## Perguntas de fixação

1. O que acontece se você trocar o `14` do `write` por `5`?
2. Por que `main` é declarada com `int` antes do nome?
3. Qual a diferença entre `write(1, ...)` e `write(2, ...)`?
4. Depois de rodar `./a.out` e depois `ls`, o que `echo $?` mostra?
5. Por que precisamos de `./` antes de `a.out`?

<details>
<summary>Respostas</summary>

1. Só os 5 primeiros bytes são escritos: `Ola, ` (sem quebra de linha).
2. Porque `main` devolve um inteiro (o código de saída) e, em C, o tipo de retorno de toda função precisa ser declarado.
3. `1` é a saída padrão (stdout), `2` é a saída de erro (stderr). No terminal as duas aparecem, mas são canais diferentes: `./a.out > arquivo` só redireciona o `1`.
4. O código de saída do `ls` (normalmente `0`), porque `$?` guarda o código do **último** comando.
5. Porque o shell só procura programas nas pastas listadas em `$PATH`, e a pasta atual não está lá por segurança.

Mini-exercício:
```c
#include <unistd.h>

int	main(void)
{
	write(1, "Seu Nome\n", 9);
	return (7);
}
```

Conte os bytes: `Seu Nome` tem 8 caracteres, mais o `\n` dá 9. Depois de `./a.out`, `echo $?` mostra `7`.

</details>
