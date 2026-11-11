# Resposta — exame 04, nível 0: ft_last_arg

## Solução

```c
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (argv[argc - 1][i] != '\0')
			i++;
		write(1, argv[argc - 1], i);
	}
	write(1, "\n", 1);
	return (0);
}
```

Arquivo: [`ft_last_arg.c`](ft_last_arg.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. O último argumento está em `argv[argc - 1]`.
2. Só existe argumento se `argc > 1`. Sem argumentos, `argv[argc - 1]` seria `argv[0]`, o nome do programa, que **não** deve ser impresso.
3. O `\n` é impresso em todos os casos, por isso fica fora do `if`.

## Erros comuns

- Esquecer o `if (argc > 1)` e imprimir o nome do programa quando não há argumentos.
- Colocar o `\n` dentro do `if`: sem argumentos, a saída fica vazia em vez de uma linha vazia.

## Casos extremos

- Último argumento vazio (`./ft_last_arg x ""`): imprime só o `\n`.
- Um argumento só: ele mesmo é o último.

## Como testar

```bash
./run.sh ft_last_arg
```
