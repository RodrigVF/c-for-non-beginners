# Aula 09 — `malloc`, `free`, leaks e `valgrind`

⏱️ ~10 minutos · Arquivos: [`dup.c`](dup.c), [`vazamento.c`](vazamento.c)

## A ideia central: C não tem garbage collector

Em Python, Java ou JS, você cria objetos e um **coletor de lixo** (*garbage collector*) apaga sozinho o que ninguém usa mais.

**C não tem isso.** Se você pede memória, você devolve. Se não devolver, ela fica ocupada até o programa terminar. Isso é um **leak** (vazamento de memória).

Por que C é assim? Porque o garbage collector custa tempo e imprevisibilidade (ele pausa o programa quando quer). C foi feita para sistemas operacionais e programas onde **você** decide tudo.

## Stack contra heap

Até agora, toda variável estava na **stack**: criada quando a função começa, destruída quando ela termina. Rápida e automática, mas com dois limites:

1. O tamanho precisa ser conhecido na compilação (`char buf[64]`).
2. Ela morre no fim da função.

E se você precisa de uma string cujo tamanho só sabe na hora de rodar? Ou de algo que sobreviva ao fim da função? Aí entra o **heap**.

```
┌──────────────────────────────────────┐ endereços altos
│ STACK  (variáveis locais)            │  automática: some no fim da função
│   main: c = 0x55...2a0 ──────┐       │
│                              │       │
│          ↓ cresce            │       │
│                              │       │
│          ↑ cresce            │       │
│ HEAP   (malloc / free)       ▼       │  manual: você pede e devolve
│   [V][i][v][o][ ][n][o]...[\0]       │
├──────────────────────────────────────┤
│ literais ("ola"), código             │  só leitura
└──────────────────────────────────────┘ endereços baixos
```

## `malloc`: pedir memória

```c
#include <stdlib.h>

char	*nova;

nova = malloc(sizeof(char) * (len + 1));
if (nova == NULL)
	return (NULL);
```

- `malloc(n)` reserva **n bytes** no heap e devolve o endereço do começo.
- A memória vem com **lixo** (não é zerada).
- Se não houver memória, devolve `NULL`. **Sempre teste.** A correção da 42 costuma cobrar isso.
- `sizeof(char) * (len + 1)`: o `+ 1` é para o `'\0'`. Esquecer o `+ 1` é o bug número 1 do `ft_strdup`.

Para ints: `malloc(sizeof(int) * quantidade)`. Nunca escreva `malloc(quantidade)` para ints: seria 1 byte por elemento.

## `free`: devolver

```c
free(nova);
```

- Devolve o bloco para o sistema. Depois disso, **não use mais** `nova` (o ponteiro ainda guarda o endereço, mas a memória não é mais sua: *use after free*).
- Só dê `free` em endereços que vieram de `malloc`. `free` em literal ou em array da stack quebra o programa.
- `free` duas vezes no mesmo bloco (*double free*) também quebra.
- `free(NULL)` é permitido e não faz nada.

Regra de ouro: **para cada `malloc`, exatamente um `free`.**

Quem dá o `free`? Quem recebeu o ponteiro. No `ft_strdup`, a função dá `malloc` e **quem chama** é responsável pelo `free`. Por isso os `main.c` deste repositório fazem `free` depois de cada teste.

## Exemplo correto: [`dup.c`](dup.c)

```bash
cc -Wall -Wextra -Werror dup.c ../util/ft_util.c && ./a.out
```

```
Vivo no heap
```

Repare que a função `copia` termina, mas a memória continua válida na `main`. Isso é impossível com um array local.

## Encontrando leaks com `valgrind`

`valgrind` roda seu programa "dentro" de um fiscal que anota cada `malloc` e `free`. Compile com `-g` para ele mostrar números de linha:

```bash
cc -Wall -Wextra -Werror -g vazamento.c ../util/ft_util.c -o vazamento
valgrind --leak-check=full ./vazamento
```

O final da saída:

```
==6911== 120 bytes in 3 blocks are definitely lost in loss record 1 of 1
==6911==    at 0x4846828: malloc (in /usr/libexec/valgrind/...)
==6911==    by 0x1091A7: main (vazamento.c:24)
==6911==
==6911== LEAK SUMMARY:
==6911==    definitely lost: 120 bytes in 3 blocks
```

Como ler:
- **definitely lost**: memória que ninguém mais aponta. Leak certo.
- `main (vazamento.c:24)`: a linha do `malloc` que vazou. Vá lá e descubra onde deveria ter um `free`.
- 120 bytes = 3 blocos × `sizeof(int) * 10`.

Agora o programa correto:

```bash
cc -Wall -Wextra -Werror -g dup.c ../util/ft_util.c -o dup
valgrind --leak-check=full ./dup
```

```
==6920== All heap blocks were freed -- no leaks are possible
==6920== ERROR SUMMARY: 0 errors from 0 contexts
```

`valgrind` também acusa escrita fora do bloco. Se você esquecer o `+ 1`:

```
Invalid write of size 1
   at ...: ft_strdup (ft_strdup.c:<linha do erro>)
Address 0x4a75043 is 0 bytes after a block of size 3 alloc'd
```

"0 bytes after a block of size 3" = você escreveu exatamente um byte depois do fim. Clássico `'\0'` sem espaço.

O [`run.sh`](../../run.sh) roda o `valgrind` sozinho nos exercícios que usam `malloc`.

## É normal estranhar

"Mas o sistema não libera tudo quando o programa termina?" Sim. Mas programas de verdade (servidores, jogos, o shell) rodam por horas, e um leak dentro de um laço come toda a memória. Na 42, leak é tratado como erro nos projetos com `malloc`. Crie o hábito agora.

## Mini-exercício

Corrija [`vazamento.c`](vazamento.c) para que o `valgrind` mostre `All heap blocks were freed`. Dica: o `free` deve ficar dentro do laço.

## Perguntas de fixação

1. Por que C não libera a memória do `malloc` sozinho?
2. Por que `ft_strdup` precisa de `len + 1` bytes?
3. O que fazer logo depois de chamar `malloc`?
4. Uma função pode devolver um array local (`char buf[10]`)? E um ponteiro vindo de `malloc`?
5. O que significa "definitely lost" no `valgrind`?

<details>
<summary>Respostas</summary>

1. Porque C não tem garbage collector: a linguagem entrega o controle total (e a responsabilidade) ao programador.
2. Um byte a mais para o `'\0'` que termina a string.
3. Testar se o retorno é `NULL` e, se for, tratar a falha (geralmente devolvendo `NULL`).
4. Array local: não, ele é destruído no `return`. Ponteiro de `malloc`: sim, o heap continua válido até alguém dar `free`.
5. Blocos alocados para os quais não existe mais nenhum ponteiro: impossível liberar. É leak com certeza.

</details>
