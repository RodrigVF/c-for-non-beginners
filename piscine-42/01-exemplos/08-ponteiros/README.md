# Aula 08 — Ponteiros

⏱️ ~10 minutos · Arquivos: [`enderecos.c`](enderecos.c), [`swap.c`](swap.c), [`aritmetica.c`](aritmetica.c)

> Esta é a aula mais importante. Se precisar, leia duas vezes. **Todo mundo** acha ponteiro confuso no começo.

## A ideia central

A memória é uma rua enorme de casas numeradas. Cada casa guarda **1 byte**. O número da casa é o **endereço**.

Um **ponteiro** é uma variável que guarda um endereço. Só isso.

```
endereço:  ...  0x...55c  0x...55d  0x...55e  0x...55f  ...   0x...560
               ┌─────────────────────────────────────────┐
               │              n = 42                     │   (int: 4 casas)
               └─────────────────────────────────────────┘
                   ↑
                   p guarda 0x...55c  ("o n mora aqui")
```

## Os dois operadores

| Operador | Lê-se | Faz |
|---|---|---|
| `&x` | "endereço de x" | dá o endereço onde `x` mora |
| `*p` | "o que está em p" | vai até o endereço guardado em `p` e acessa o valor |

E na **declaração**, `*` significa "isto é um ponteiro":

```c
int	n;
int	*p;     /* p é um ponteiro para int */

n = 42;
p = &n;     /* p recebe o endereço de n */
*p = 7;     /* vá até o endereço em p e escreva 7. Agora n vale 7 */
```

> ⚠️ O mesmo símbolo `*` tem dois papéis: na declaração (`int *p;`) diz o tipo; numa expressão (`*p = 7;`) acessa o conteúdo. Isso confunde todo mundo no começo.

```bash
cc -Wall -Wextra -Werror enderecos.c ../util/ft_util.c && ./a.out
```

```
n            = 42
&n           = 0x7ffd87c1f55c
p            = 0x7ffd87c1f55c
*p           = 42
apos *p = 7, n = 7
```

(Os endereços mudam a cada execução. Isso é normal: é uma proteção do sistema.)

## Por que o ponteiro tem tipo (`int *`, `char *`)?

Todo ponteiro guarda só um endereço (8 bytes). O tipo diz **o que tem lá**: quantos bytes ler com `*p` e como interpretar. `*p` com `int *` lê 4 bytes; com `char *`, 1 byte.

## Passagem "por referência" (é por valor de um endereço)

Lembra que na aula 06 a função recebia uma cópia? O truque é **copiar o endereço**. A cópia do endereço ainda aponta para a casa original.

```c
void	troca(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

troca(&x, &y);
```

```
 main                         troca
┌──────────┐               ┌──────────────┐
│ x = 1    │ <──────────── │ a = &x       │   *a = *b  → muda o x de verdade
│ y = 2    │ <──────────── │ b = &y       │
└──────────┘               └──────────────┘
```

```bash
cc -Wall -Wextra -Werror swap.c ../util/ft_util.c && ./a.out
```

```
depois de troca_errada(x, y): x=1 y=2
depois de troca(&x, &y):      x=2 y=1
```

É exatamente o exercício `ft_swap`. E é como uma função "devolve" vários valores: `ft_div_mod(a, b, &div, &mod)`.

## `NULL`: o ponteiro que não aponta para nada

`NULL` é o endereço `0`, reservado para dizer "não aponta para lugar nenhum". Acessar `*p` com `p == NULL` causa *segmentation fault*. Funções que podem falhar (como `malloc`) devolvem `NULL`.

## Aritmética de ponteiros

Somar `1` a um ponteiro avança **um elemento**, não um byte. O compilador multiplica pelo tamanho do tipo.

```bash
cc -Wall -Wextra -Werror aritmetica.c ../util/ft_util.c && ./a.out
```

```
p     = 0x7fffa0f616bc -> 10
p + 1 = 0x7fffa0f616c0 -> 20      ← +4 bytes (int)
p + 2 = 0x7fffa0f616c4 -> 30
s     = 0x561a0f975009 -> 97      ← 'a'
s + 1 = 0x561a0f97500a -> 98      ← +1 byte (char)
a b c
```

E aqui está o segredo dos arrays:

> **`tab[i]` é exatamente `*(tab + i)`.**

O colchete é só uma forma mais bonita de escrever aritmética de ponteiros. Por isso arrays e ponteiros parecem a mesma coisa.

Percorrer uma string movendo o ponteiro (estilo muito comum):

```c
while (*str != '\0')
{
	ft_putchar(*str);
	str++;           /* avança para o próximo char */
}
```

## Ponteiro para ponteiro (`int **`)

É só um ponteiro que guarda o endereço de outro ponteiro. Aparece em `char **strs` (array de strings) e em exercícios que encadeiam vários `*` (`int ***p`...). Leia de dentro para fora: `**p` é "o que está no endereço que está em p".

## Resumo visual

```
int	n;     n  = 42           (um int)
int	*p;    p  = &n           (endereço de n)
           *p = 42           (o valor lá: o próprio n)
           &p = endereço de p (p também mora em algum lugar!)
```

## É normal estranhar

Se você vem de Java/Python/JS, você **já usou** ponteiros sem saber: toda variável de objeto é um. A diferença é que C mostra o endereço e deixa você fazer contas com ele. Desenhar caixinhas e setas no papel resolve 90% das dúvidas. Faça isso em todo exercício de ponteiro.

## Mini-exercício

Escreva `void	ft_set_zero(int *n)` que zera a variável de quem chamou. Depois `void	ft_inc_all(int *tab, int size)` que soma 1 em cada elemento do array usando só aritmética de ponteiros (sem `[ ]`).

## Perguntas de fixação

1. O que guarda uma variável do tipo `int *`?
2. Após `p = &n; *p = 3;`, quanto vale `n`?
3. Se `p` é `int *` e vale `0x1000`, quanto vale `p + 2`?
4. Escreva `tab[3]` usando só `*` e `+`.
5. Por que `ft_swap` precisa receber ponteiros?

<details>
<summary>Respostas</summary>

1. Um endereço de memória onde há um `int`.
2. `3`.
3. `0x1008` (2 × 4 bytes).
4. `*(tab + 3)`.
5. Porque C passa argumentos por valor: com `int`, a função trocaria só cópias. Com os endereços, ela altera as variáveis originais.

Mini-exercício:
```c
#include "../util/ft_util.h"

void	ft_set_zero(int *n)
{
	*n = 0;
}

void	ft_inc_all(int *tab, int size)
{
	int	*fim;

	fim = tab + size;
	while (tab < fim)
	{
		*tab = *tab + 1;
		tab++;
	}
}

int	main(void)
{
	int	x;
	int	tab[3];

	x = 42;
	ft_set_zero(&x);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	ft_inc_all(tab, 3);
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(tab[0] + tab[1] + tab[2]);
	ft_putchar('\n');
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror arquivo.c ../util/ft_util.c && ./a.out
```

Saída: `0 9` (`x` foi zerado, e o array virou `{2, 3, 4}`). Em `ft_inc_all`, `fim` aponta para logo depois do último elemento, e `tab` avança até chegar nele.

</details>
