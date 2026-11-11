# Aula 14 — Programas com argumentos: `argc` e `argv`

⏱️ ~8 minutos · Arquivos: [`mostra_args.c`](mostra_args.c), [`eco.c`](eco.c)

## A ideia central

Até aqui, quase todo exercício era uma **função**: você entregava `ft_strlen.c`, e a correção usava uma `main` própria para testar.

Na Piscine também existem exercícios de **programa**: você entrega um arquivo **com a sua `main`**, e ele é executado no terminal com argumentos, assim:

```bash
./ft_show_args Ola "Piscine 42"
```

Para receber esses argumentos, a `main` ganha dois parâmetros:

```c
int	main(int argc, char **argv)
```

> 💡 Você já usou isso em outras linguagens: é o `sys.argv` do Python ou o `process.argv` do Node. A diferença é que em C chega tudo "cru": um número e uma lista de ponteiros.

## O que são `argc` e `argv`

- `argc` (*argument count*): **quantos** argumentos existem, **contando o nome do programa**.
- `argv` (*argument vector*): um array de strings. `argv[0]` é o nome do programa, `argv[1]` é o primeiro argumento de verdade, e assim por diante.
- `argv[argc]` é sempre `NULL`: a lista termina com um ponteiro nulo.

Para `./mostra_args ola "dois tres"`:

```
argc = 3

argv ──> [ ptr ][ ptr ][ ptr ][ NULL ]
           │      │      │
           │      │      └──> "dois tres\0"
           │      └─────────> "ola\0"
           └────────────────> "./mostra_args\0"
```

Por que `char **`? Cada argumento é uma string (`char *`), e `argv` aponta para o primeiro elemento de um array dessas strings: um ponteiro para ponteiro de `char` (aula 08).

Rode o exemplo:

```bash
cc -Wall -Wextra -Werror mostra_args.c ../util/ft_util.c -o mostra_args
./mostra_args ola "dois tres"
```

```
argc = 3
argv[0] = "./mostra_args"
argv[1] = "ola"
argv[2] = "dois tres"
argv[argc] = NULL (fim da lista)
```

## Quem separa os argumentos é o shell

Seu programa não recebe a linha digitada: ele recebe o que o **shell** já separou.

| Você digita | O programa recebe |
|---|---|
| `./prog a b c` | `argc = 4`: `"a"`, `"b"`, `"c"` |
| `./prog "a b" c` | `argc = 3`: `"a b"`, `"c"` (as aspas juntam) |
| `./prog ""` | `argc = 2`: uma string vazia |
| `./prog *.c` | os **nomes dos arquivos** `.c` da pasta (o shell expande o `*`) |

> ⚠️ O último caso pega muita gente: o `*` nunca chega ao seu programa. Se quiser passar o caractere `*`, use aspas: `./prog "*"`.

## Percorrendo os argumentos

O padrão é sempre o mesmo: começar em `1` (para pular o nome do programa) e ir até `argc - 1`.

```c
i = 1;
while (i < argc)
{
	ft_putendl(argv[i]);
	i++;
}
```

O exemplo [`eco.c`](eco.c) imita o comando `echo`. Ele também mostra a convenção de **código de saída**: quando falta argumento, o programa explica o uso e devolve `1` (erro), como na aula 01.

```bash
cc -Wall -Wextra -Werror eco.c ../util/ft_util.c -o eco
./eco Ola, Piscine 42
./eco ; echo "codigo: $?"
```

```
Ola, Piscine 42
uso: ./eco palavra [outras palavras...]
codigo: 1
```

## Armadilha: parâmetro não usado

Se o seu programa só usa `argv`, o `-Wextra` reclama do `argc` parado, e com `-Werror` isso vira erro:

```
error: unused parameter 'argc' [-Werror=unused-parameter]
```

Duas saídas:
- Usar o parâmetro de verdade (por exemplo, no `while (i < argc)`).
- Avisar ao compilador que é de propósito, com `(void)argc;` no começo da função.

E se o programa não usa nenhum dos dois, declare `int	main(void)`, como nas aulas anteriores.

## Pode mexer no `argv`?

Pode. As strings e o array de ponteiros de `argv` pertencem ao seu programa. Trocar a **ordem dos ponteiros** é um jeito simples de ordenar os argumentos sem copiar nenhuma string: é o que a resposta do `ft_sort_args` faz.

```
antes:  argv ──> [./prog][ "b" ][ "a" ]
depois: argv ──> [./prog][ "a" ][ "b" ]   ← só os ponteiros trocaram de lugar
```

## Função ou programa? Leia o subject

| | Exercício de **função** | Exercício de **programa** |
|---|---|---|
| O que você entrega | só a função (`ft_strlen.c`) | um `.c` **com `main`** |
| Quem chama | a `main` da correção | o terminal, com argumentos |
| Como testar | escreva um `main.c` à parte | compile sozinho e rode com argumentos |

Entregar `main` num exercício de função quebra a correção (aula 02). **Não** entregar `main` num exercício de programa também quebra. O subject sempre diz qual é o caso; o formato exato da Piscine, confirme com a 42SP.

## É normal estranhar

`char **argv` assusta no começo. Leia como "lista de strings", que é exatamente o que ele é. Com o desenho das setas acima, `argv[2][0]` deixa de ser mistério: é a primeira letra do segundo argumento.

## Mini-exercício

Escreva um programa `conta.c` que imprime quantos argumentos recebeu, **sem contar o nome do programa**, seguido de `\n`. Use `ft_putnbr` de [`../util/`](../util/ft_util.c).

```bash
./conta            → 0
./conta a "b c" d  → 3
```

## Perguntas de fixação

1. Em `./prog um dois`, quanto vale `argc`? E `argv[0]`?
2. O que vale `argv[argc]`?
3. Quantos argumentos o programa recebe em `./prog "a b" c`?
4. Por que `./prog *` pode receber dezenas de argumentos?
5. Como evitar o erro `unused parameter 'argc'` quando só `argv` é usado?

<details>
<summary>Respostas</summary>

1. `argc` vale `3`. `argv[0]` é `"./prog"`, o nome usado para chamar o programa.
2. `NULL`. A lista de argumentos sempre termina com um ponteiro nulo.
3. Dois (`argc` vale 3): `"a b"` e `"c"`. As aspas juntam as palavras num argumento só.
4. Porque o shell troca o `*` pelos nomes de todos os arquivos da pasta antes de chamar o programa.
5. Usando `argc` (por exemplo, no laço) ou escrevendo `(void)argc;` no início da `main`.

Mini-exercício:

```c
#include "../util/ft_util.h"

int	main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	ft_putchar('\n');
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror conta.c ../util/ft_util.c -o conta
```

</details>
