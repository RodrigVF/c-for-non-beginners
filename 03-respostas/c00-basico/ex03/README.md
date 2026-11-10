# Resposta — c00/ex03: ft_is_negative

## Solução

```c
#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}
```

Arquivo: [`ft_is_negative.c`](ft_is_negative.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Uma string literal (`"N"`) já é um endereço (aula 07), então pode ir direto no `write`.
2. Zero não é negativo: a condição é `n < 0`, e o resto cai no `else`.

## Erros comuns

- `if (n <= 0)`: imprime `N` para zero.
- `write(1, 'N', 1)`: aspas simples são um `char` (um número), não um endereço. Não compila com as flags.
- Usar o ternário (`n < 0 ? ... : ...`): proibido pela Norma.

## Casos extremos

- `0` → `P`. `INT_MIN` → `N`. `INT_MAX` → `P`.

## Como testar

```bash
./run.sh ft_is_negative
```
