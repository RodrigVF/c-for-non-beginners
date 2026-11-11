# Resposta — c00/ex06: ft_putnbr

## Solução

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
```

Arquivo: [`ft_putnbr.c`](ft_putnbr.c) (com o cabeçalho da 42 no topo)

## Raciocínio

**1. Separar dígitos.** `% 10` dá o último dígito, `/ 10` remove o último dígito (aula 04).

**2. Ordem.** Pegando `% 10` primeiro, os dígitos saem de trás para frente (`3`, `2`, `1`). A recursão resolve: imprime o "resto da esquerda" (`nb / 10`) **antes** do último dígito.

```
ft_putnbr(123)
 ├─ ft_putnbr(12)
 │   ├─ ft_putnbr(1)
 │   │    └─ escreve '1'
 │   └─ escreve '2'
 └─ escreve '3'
```

**3. Dígito para caractere.** `nb % 10 + '0'`: `3 + 48 = 51 = '3'`.

**4. Negativos.** Escreve `-` e trabalha com `-nb`.

**5. INT_MIN.** `-(-2147483648)` = `2147483648`, que **não cabe** num `int` (máximo `2147483647`). É overflow e comportamento indefinido. Por isso o caso é tratado antes, escrevendo a string pronta.

## Alternativa sem caso especial: usar `long`

```c
void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
```

Cuidado: aqui `ft_putnbr(n / 10)` recebe um `long` e converte para `int`. Funciona porque `n / 10` sempre cabe num `int`. A versão de [`01-exemplos/util/ft_util.c`](../../../01-exemplos/util/ft_util.c) usa essa ideia.

## Erros comuns

- Não tratar `INT_MIN`: imprime lixo como `-(` (o teste mostra exatamente isso).
- Imprimir `nb % 10` sem somar `'0'`: sai um caractere de controle.
- `if (nb > 10)` em vez de `>= 10`: `ft_putnbr(10)` imprime só `0`.
- Usar `printf` ou `itoa`: proibidos.

## Casos extremos testados

`0`, `7`, `-7`, `10`, `42`, `-42`, `100000`, `INT_MAX`, `INT_MIN`, `INT_MIN + 1`.

## Como testar

```bash
./run.sh ft_putnbr
```
