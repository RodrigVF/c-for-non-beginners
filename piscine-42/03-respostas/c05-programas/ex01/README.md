# Resposta — c05/ex01: ft_show_args

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

	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
	return (0);
}
```

Arquivo: [`ft_show_args.c`](ft_show_args.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. `argv[0]` é o nome do programa, então o laço começa em `1`.
2. Vai até `argc - 1` (`i < argc`). Também daria para parar quando `argv[i]` for `NULL`, porque `argv[argc]` é sempre `NULL`.
3. `ft_putendl` escreve a string e a quebra de linha. Separar essa função deixa a `main` curta e reaproveitável nos próximos exercícios.

## Erros comuns

- Começar em `0` e imprimir também o nome do programa.
- Usar `while (i <= argc)`: lê `argv[argc]`, que é `NULL`, e dá *segmentation fault*.
- Esquecer o `\n` depois de cada argumento.

## Casos extremos

- Sem argumentos: o laço não roda e nada é impresso.
- Argumento vazio (`""`): imprime uma linha vazia.
- Argumento com espaços (`"Piscine 42"`): chega como **um** argumento só e é impresso numa linha.

## Como testar

```bash
./run.sh ft_show_args
```
