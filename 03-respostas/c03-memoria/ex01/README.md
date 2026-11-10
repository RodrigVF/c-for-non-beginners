# Resposta — c03/ex01: ft_range

## Solução

```c
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * ((long)max - min));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
```

Arquivo: [`ft_range.c`](ft_range.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Caso inválido primeiro: `min >= max` → `NULL` (antes de alocar, para não vazar).
2. Quantidade de elementos: `max - min`. Bytes: `sizeof(int) * quantidade`.
3. **Por que `(long)max - min`?** Com `min = -2147483648` e `max = 2147483647`, a conta `max - min` em `int` estoura. Convertendo um dos lados para `long` antes, a conta toda é feita em `long`.
4. Preenche avançando o próprio `min` até `max`, e `i` como índice do array. Assim não existe nenhuma conta `min + i` que possa estourar.

## Erros comuns

- `malloc(max - min)`: aloca **bytes**, não ints. 4 vezes menos que o necessário: `valgrind` mostra `Invalid write of size 4`.
- Incluir `max` (`while (min <= max)`): escreve um elemento além do bloco.
- Alocar antes de testar `min >= max`.

## Casos extremos

- `(5, 5)` e `(5, 0)` → `NULL`.
- `(5, 6)` → `{5}`.
- Valores perto de `INT_MIN` → o teste cobre `(-2147483648, -2147483645)`.

## Conferindo leaks

```bash
./run.sh ft_range
```

ou, manualmente:

```bash
cc -Wall -Wextra -Werror -g minha-versao/c03/ex01/ft_range.c testes/ft_range/main.c -o t
valgrind --leak-check=full ./t
```
