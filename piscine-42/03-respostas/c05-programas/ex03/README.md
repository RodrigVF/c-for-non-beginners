# Resposta — c05/ex03: ft_sort_args

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort(char **tab, int size)
{
	int		i;
	int		trocou;
	char	*tmp;

	trocou = 1;
	while (trocou)
	{
		trocou = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				trocou = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
	return (0);
}
```

Arquivo: [`ft_sort_args.c`](ft_sort_args.c) (com o cabeçalho da 42 no topo)

## Raciocínio

São três passos, e cada um virou uma função (assim cada função fica dentro das 25 linhas):

1. **Comparar** (`ft_strcmp`): igual ao exercício do c02, comparando como `unsigned char`.
2. **Ordenar** (`ft_sort`): *bubble sort*. Percorre a lista trocando vizinhos fora de ordem e repete enquanto tiver havido alguma troca na passada.
3. **Imprimir** (`ft_putendl`): um argumento por linha.

O truque está em `ft_sort(argv + 1, argc - 1)`: `argv + 1` é o endereço do segundo elemento, então a função recebe uma lista que já começa no primeiro argumento de verdade e não mexe no nome do programa.

As trocas mudam só os **ponteiros**, nunca as strings:

```
antes:  [ "b" ][ "a" ][ "C" ]
troca:  [ "a" ][ "b" ][ "C" ]   ← "b" > "a"
troca:  [ "a" ][ "C" ][ "b" ]   ← "b" > "C"
troca:  [ "C" ][ "a" ][ "b" ]   ← "a" > "C" (passada seguinte)
```

## Erros comuns

- Ordenar `argv` inteiro (a partir do `0`): o nome do programa entra na ordenação e pode aparecer no meio da saída.
- Trocar os **caracteres** das strings em vez dos ponteiros: dá muito mais trabalho, e strings de tamanhos diferentes se corrompem.
- Achar que `"C"` vem depois de `"a"`: na tabela ASCII, todas as maiúsculas vêm antes das minúsculas.
- Passar de 5 funções por arquivo ou 25 linhas por função.

## Casos extremos

- Sem argumentos: `ft_sort` recebe tamanho `0`, o laço de dentro não roda e nada é impresso.
- Argumentos repetidos aparecem repetidos.
- Argumento vazio (`""`) é o "menor" de todos e sai primeiro.

## Para ir além

O *bubble sort* é lento para listas grandes, mas para argumentos de linha de comando é mais do que suficiente, e é fácil de escrever sem erro no exame.

## Como testar

```bash
./run.sh ft_sort_args
```
