# Resposta — c05/ex02: ft_rev_args

## Solução

```c
#include <unistd.h>

void	ft_putendl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		ft_putendl(argv[i]);
		i--;
	}
	return (0);
}
```

Arquivo: [`ft_rev_args.c`](ft_rev_args.c) (com o cabeçalho da 42 no topo)

## Raciocínio

O mesmo do `ft_show_args`, com o laço ao contrário:

```
argv:  [0: ./ft_rev_args] [1: "1"] [2: "2"] [3: "3"]
                                              ↑ começa aqui (argc - 1)
                           ↑ último impresso (i > 0)
```

A condição `i > 0` para antes do índice `0`, que é o nome do programa.

## Erros comuns

- `while (i >= 0)`: imprime o nome do programa no fim (o teste mostra exatamente isso).
- Começar em `argc`: lê `argv[argc]`, que é `NULL`, e quebra.

## Casos extremos

- Sem argumentos: `i` começa em `0`, a condição é falsa e nada é impresso.

## Como testar

```bash
./run.sh ft_rev_args
```
