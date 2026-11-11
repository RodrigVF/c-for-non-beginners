# Aula 03 — Tipos e variáveis

⏱️ ~9 minutos · Arquivos: [`tamanhos.c`](tamanhos.c), [`char_numero.c`](char_numero.c)

## A ideia central

Em C, uma variável é **uma caixa de tamanho fixo na memória**. O tipo diz duas coisas:

1. **Quantos bytes** a caixa ocupa.
2. **Como interpretar** esses bytes.

Por que fixo? Porque o compilador precisa saber, **antes de rodar**, quanto espaço reservar e quais instruções de máquina usar. Não há um interpretador para descobrir isso depois.

```
int	idade;      →   [ ? ][ ? ][ ? ][ ? ]   4 bytes reservados
char	letra;      →   [ ? ]                  1 byte reservado
```

## Os tamanhos (no Linux 64 bits)

Rode:

```bash
cc -Wall -Wextra -Werror tamanhos.c ../util/ft_util.c && ./a.out
```

```
char  : 1 byte(s)
short : 2 byte(s)
int   : 4 byte(s)
long  : 8 byte(s)
float : 4 byte(s)
double: 8 byte(s)
char *: 8 byte(s)
int * : 8 byte(s)
```

`sizeof(tipo)` é um operador que devolve o tamanho em bytes, calculado na compilação.

Limites que você vai usar muito:

| Tipo | Faixa |
|---|---|
| `char` | -128 a 127 |
| `unsigned char` | 0 a 255 |
| `int` | -2147483648 a 2147483647 (`INT_MIN` e `INT_MAX`, em `<limits.h>`) |

> ⚠️ `INT_MIN` tem um a mais do que `INT_MAX`. Então `-INT_MIN` **não cabe** num `int`. Isso é a pegadinha clássica do `ft_putnbr`.

## `char` é um número

Não existe "tipo letra" em C. `char` é um inteiro de 1 byte. `'A'` é só uma forma bonita de escrever `65` (código ASCII).

```bash
cc -Wall -Wextra -Werror char_numero.c ../util/ft_util.c && ./a.out
```

```
'A' como numero: 65
'A' + 1 como letra: B
'7' - '0' = 7
'a' - 'A' = 32
char 127 + 1 = -128
```

Os truques que você vai usar em toda a Piscine:

| Expressão | Para quê |
|---|---|
| `c - '0'` | converter o caractere `'7'` no número `7` |
| `n + '0'` | converter o número `7` no caractere `'7'` |
| `c >= 'a' && c <= 'z'` | testar se é minúscula |
| `c - 32` (ou `c - 'a' + 'A'`) | minúscula para maiúscula |

Funciona porque na tabela ASCII os dígitos e as letras são **consecutivos**:

```
'0' '1' '2' ... '9'     'A' 'B' ... 'Z'     'a' 'b' ... 'z'
 48  49  50      57      65  66      90      97  98     122
```

Consulte a tabela completa com `man ascii`.

A última linha (`127 + 1 = -128`) mostra o **overflow**: a caixa de 1 byte "dá a volta", como um hodômetro de carro.

## Lixo: variáveis não inicializadas

Em Python, uma variável nasce com valor. Em C, **declarar só reserva a caixa**. O que estava naquela memória antes continua lá: o "lixo".

```c
int	total;

total = total + 1;    /* total começou com QUALQUER valor */
```

Por que C não zera para você? Porque zerar custa tempo, e C não faz nada que você não pediu. Com `-Wall`, o compilador geralmente avisa (`'total' is used uninitialized`), e com `-Werror` isso vira erro. Mas ele **não pega todos os casos**. Regra prática: **dê valor antes de ler**.

## Declaração na Norma

A Norma é bem rígida aqui:

```c
int	main(void)
{
	int		i;        /* declarações no início, uma por linha */
	char	c;        /* nomes alinhados com tab */
	                  /* linha em branco obrigatória */
	i = 0;            /* inicialização separada */
	c = 'a';
	...
}
```

Proibido pela Norma (mas válido em C):
```c
int	i = 0;           /* declarar e inicializar na mesma linha */
int	i, j;            /* duas variáveis na mesma linha */
```

## É normal estranhar

"Por que `char` aceita conta?" Porque, para o processador, tudo é número. A "letra" só aparece quando um programa (o terminal) desenha o símbolo daquele número. Pense em `char` como "inteiro pequeno que costumamos usar para texto".

## Mini-exercício

Escreva um programa que imprime o alfabeto maiúsculo usando uma variável `char` que começa em `'A'` e é incrementada (`c++`) até `'Z'`. Use `write(1, &c, 1)` para imprimir cada letra.

## Perguntas de fixação

1. O que significa dizer que os tipos em C são fixos?
2. Quanto vale `'9' - '0'`? E `'0' + 5` como caractere?
3. Por que `-(-2147483648)` é um problema num `int`?
4. O que tem dentro de uma variável `int` logo após `int x;`?
5. Por que `int i = 0;` é proibido na 42, se o C aceita?

<details>
<summary>Respostas</summary>

1. O tamanho e a interpretação de cada variável são decididos na compilação e nunca mudam enquanto o programa roda.
2. `9` (o número). `'5'` (o caractere de código 53).
3. Porque o resultado seria `2147483648`, maior que `INT_MAX` (`2147483647`). É overflow, e o resultado é indefinido.
4. Lixo: o valor que estava naquela região da memória antes. Não dá para prever.
5. É uma regra de estilo da Norma, para deixar as declarações separadas da lógica e padronizar o código. O C aceita normalmente.

Mini-exercício:
```c
#include <unistd.h>

int	main(void)
{
	char	c;

	c = 'A';
	while (c <= 'Z')
	{
		write(1, &c, 1);
		c++;
	}
	write(1, "\n", 1);
	return (0);
}
```

</details>
