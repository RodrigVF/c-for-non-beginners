# Resposta — c06/ex01: ft_putnbr_base

## Solução

```c
#include <unistd.h>

int	ft_base_valida(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_escreve_base(long n, char *base, int tamanho)
{
	if (n >= tamanho)
		ft_escreve_base(n / tamanho, base, tamanho);
	write(1, &base[n % tamanho], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		tamanho;
	long	n;

	tamanho = ft_base_valida(base);
	if (tamanho == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_escreve_base(n, base, tamanho);
}
```

Arquivo: [`ft_putnbr_base.c`](ft_putnbr_base.c) (com o cabeçalho da 42 no topo)

## Raciocínio

**1. Validar a base** (`ft_base_valida`): percorre a string. Para cada caractere, recusa `+` e `-` e procura repetições no resto da string. No fim, o índice `i` é o tamanho. Menos de 2 é inválido. A função devolve o tamanho, ou `0` se a base não serve: um valor só responde às duas perguntas.

**2. Escrever** (`ft_escreve_base`): o mesmo raciocínio do `ft_putnbr`, trocando `10` pelo tamanho da base:

```
255 na base "0123456789ABCDEF" (tamanho 16)
ft_escreve_base(255)
 ├─ ft_escreve_base(255 / 16 = 15)
 │    └─ escreve base[15 % 16] = 'F'
 └─ escreve base[255 % 16 = 15] = 'F'
→ "FF"
```

O dígito não vira caractere com `+ '0'`: ele é um **índice** na string da base (`base[n % tamanho]`). Por isso qualquer conjunto de símbolos funciona.

**3. Negativos e `INT_MIN`**: o número é copiado para um `long` antes de inverter o sinal. Assim `-(-2147483648)` cabe.

## Erros comuns

- Imprimir algo (ou o sinal `-`) antes de validar a base.
- Base com um caractere só: a divisão por 1 nunca chega a zero e a recursão não termina.
- Esquecer de recusar `+` e `-` (eles confundiriam a leitura do sinal).
- Inverter o sinal no próprio `int`: estoura com `INT_MIN`.

## Casos extremos

`0` (imprime o primeiro símbolo da base), `INT_MIN` e `INT_MAX` em várias bases, bases inválidas (`""`, `"0"`, `"0+1"`, `"01-"`, `"0120"`).

## Como testar

```bash
./run.sh ft_putnbr_base
```
