# Resposta — c00/ex02: ft_print_numbers

## Solução

```c
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}
```

Arquivo: [`ft_print_numbers.c`](ft_print_numbers.c) (com o cabeçalho da 42 no topo)

## Raciocínio

Idêntico ao alfabeto, mas de `'0'` (48) a `'9'` (57). O ponto do exercício é perceber a diferença entre o **caractere** `'0'` e o **número** `0`:

```
'0' → 48 → aparece "0" na tela
 0  →  0 → caractere nulo, invisível
```

## Erros comuns

- `c = 0; while (c <= 9)`: imprime 10 caracteres de controle invisíveis.
- Usar `int` para `c` com `write(1, &c, 1)`: funciona em máquinas *little-endian* (como a sua) por sorte, porque o byte menos significativo vem primeiro. Use `char`, que é o tipo certo.

## Como testar

```bash
./run.sh ft_print_numbers
```
