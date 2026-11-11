# Aula 05 — `if` e `while` (e como viver sem `for`)

⏱️ ~6 minutos · Arquivos: [`tabuada.c`](tabuada.c), [`grade.c`](grade.c)

## A ideia central

C tem `if`, `else`, `while`, `for`, `do...while` e `switch`. A **Norma da 42 proíbe** `for`, `do...while`, `switch`, `goto` e o ternário (`? :`). Sobra `if`, `else` e `while`.

Por que proibir? Para padronizar e forçar você a escrever o laço "por extenso". Com `while`, a inicialização, a condição e o incremento ficam visíveis em linhas separadas, e fica mais fácil de corrigir na peer evaluation.

## Sintaxe do `if`

```c
if (n < 0)
	write(1, "N", 1);
else if (n == 0)
	write(1, "Z", 1);
else
	write(1, "P", 1);
```

- Os parênteses na condição são **obrigatórios** (da linguagem).
- Sem chaves, o `if` controla **só a próxima instrução**. Com mais de uma, use `{ }`.

> ⚠️ Pegadinha clássica:
> ```c
> if (x > 0)
> 	a = 1;
> 	b = 2;      /* NÃO está dentro do if! A indentação engana. */
> ```

## Sintaxe do `while`

```c
while (condicao)
{
	...
}
```

## Convertendo qualquer `for` em `while`

Um `for` tem 3 partes. Você só redistribui:

```c
/* com for (proibido na 42) */
for (i = 0; i < 10; i++)
{
	corpo;
}

/* com while (Norma) */
i = 0;                  /* 1. inicialização: antes */
while (i < 10)          /* 2. condição: no while */
{
	corpo;
	i++;                /* 3. incremento: última linha do corpo */
}
```

> ⚠️ O erro mais comum: esquecer o `i++`. Resultado: **loop infinito**. Se seu programa "travou", aperte `Ctrl+C` e procure o incremento que faltou.

Veja [`tabuada.c`](tabuada.c):

```bash
cc -Wall -Wextra -Werror tabuada.c ../util/ft_util.c && ./a.out
```

## Laços aninhados

Com `while`, lembre de **reiniciar** a variável do laço de dentro a cada volta do laço de fora. Veja [`grade.c`](grade.c):

```c
l = 0;
while (l < linhas)
{
	c = 0;              /* ← reinicia aqui, dentro do laço de fora */
	while (c < colunas)
	{
		...
		c++;
	}
	l++;
}
```

Se o `c = 0;` ficasse antes do primeiro `while`, só a primeira linha seria desenhada. No `for` isso era automático; no `while` é responsabilidade sua.

```bash
cc -Wall -Wextra -Werror grade.c ../util/ft_util.c && ./a.out
```

```
#.#.#.#.
.#.#.#.#
#.#.#.#.
.#.#.#.#
```

## E o `switch` e o ternário?

Troque por `if / else if / else`. Sempre dá.

```c
/* ternário (proibido) */
sinal = (n < 0) ? -1 : 1;

/* Norma */
if (n < 0)
	sinal = -1;
else
	sinal = 1;
```

## Limite de 25 linhas

Com o `while` "gastando" mais linhas, as funções crescem. Quando passar de 25 linhas, **separe em funções auxiliares**. Foi o que fizemos em `tabuada.c` com `linha_da_tabuada`.

## É normal estranhar

Parece um retrocesso abrir mão do `for`. Em uma semana você vai escrever `while` no automático. E a habilidade de quebrar funções em pedaços menores, forçada pelo limite de 25 linhas, é útil para sempre.

## Mini-exercício

Escreva com `while` um programa que imprime os números pares de 0 a 20, separados por espaço. Depois, um que desenha um triângulo de `*` com 5 linhas (1 estrela na primeira, 5 na última).

## Perguntas de fixação

1. Quais estruturas de controle a Norma permite?
2. Converta para `while`: `for (i = 10; i > 0; i -= 2) f(i);`
3. Qual o erro mais comum ao converter `for` em `while`?
4. Num laço aninhado com `while`, onde fica a reinicialização do contador interno?
5. Sem chaves, quantas instruções o `if` controla?

<details>
<summary>Respostas</summary>

1. `if`, `else` (e `else if`) e `while`.
2.
```c
i = 10;
while (i > 0)
{
	f(i);
	i -= 2;
}
```
3. Esquecer o incremento, o que gera loop infinito.
4. Dentro do laço externo, logo antes do laço interno.
5. Só uma (a próxima instrução).

Mini-exercício (as duas partes num arquivo):
```c
#include "../util/ft_util.h"

void	pares(void)
{
	int	i;

	i = 0;
	while (i <= 20)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		i += 2;
	}
	ft_putchar('\n');
}

void	triangulo(int linhas)
{
	int	l;
	int	c;

	l = 1;
	while (l <= linhas)
	{
		c = 0;
		while (c < l)
		{
			ft_putchar('*');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}

int	main(void)
{
	pares();
	triangulo(5);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror arquivo.c ../util/ft_util.c && ./a.out
```

No triângulo, o laço de dentro vai até `l` (o número da linha): a linha 1 tem 1 estrela, a linha 5 tem 5.

</details>
