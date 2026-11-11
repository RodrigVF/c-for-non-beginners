# Resposta — c05/ex00: ft_show_name

## Solução

```c
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	i = 0;
	while (argv[0][i] != '\0')
		i++;
	write(1, argv[0], i);
	write(1, "\n", 1);
	return (0);
}
```

Arquivo: [`ft_show_name.c`](ft_show_name.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. O nome do programa, do jeito que foi digitado, está em `argv[0]`.
2. Mede a string com um laço até o `'\0'` e escreve tudo com um `write` só. Depois, o `\n`.
3. `argc` não é usado. Sem o `(void)argc;`, o `-Wextra` acusa `unused parameter 'argc'` e o `-Werror` transforma isso em erro.

## Erros comuns

- Esquecer o `(void)argc;` e o código não compilar com as flags.
- Imprimir `argv[1]` (o primeiro argumento) em vez de `argv[0]`.
- Esperar só o nome "limpo" (`ft_show_name`): o `argv[0]` é exatamente o que foi digitado, então vem com o `./`.

## Casos extremos

- Com argumentos: eles são ignorados, e a saída continua sendo o nome.
- Chamado por outro caminho (`../ex00/ft_show_name`): a saída muda junto, porque é o que está em `argv[0]`.

## Como testar

```bash
./run.sh ft_show_name
```
