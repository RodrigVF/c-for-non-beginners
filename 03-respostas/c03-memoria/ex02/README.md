# Resposta — c03/ex02: ft_strjoin

## Solução

```c
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	if (size <= 0)
		return (0);
	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

char	*ft_append(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*fim;
	int		i;

	res = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (res == NULL)
		return (NULL);
	fim = res;
	i = 0;
	while (i < size)
	{
		fim = ft_append(fim, strs[i]);
		if (i < size - 1)
			fim = ft_append(fim, sep);
		i++;
	}
	*fim = '\0';
	return (res);
}
```

Arquivo: [`ft_strjoin.c`](ft_strjoin.c) (com o cabeçalho da 42 no topo)

## Raciocínio

O problema tem duas fases, e cada uma vira uma função (para caber nas 25 linhas):

**Fase 1 — quanto alocar** (`ft_total_len`):

```
soma dos tamanhos de strs[0..size-1]
+ tamanho de sep × (size - 1)        ← separadores só ENTRE as strings
+ 1                                  ← o '\0' (somado na chamada do malloc)
```

Para `size <= 0`, devolve `0`; o `malloc` aloca 1 byte e a função devolve `""`, que pode receber `free`.

**Fase 2 — copiar** (`ft_append`):

`ft_append` copia uma string para `dest` e **devolve o ponteiro para onde parou**. Assim, cada cópia continua de onde a anterior terminou, sem recalcular tamanhos:

```
res
 ↓
[O][l][a][,][ ][P][i][s][c][i][n][e][\0]
          ↑ fim depois de "Ola"
                ↑ fim depois de ", "
                                     ↑ fim no final → *fim = '\0'
```

O `if (i < size - 1)` evita o separador depois da última string.

## Erros comuns

- Esquecer o `+ 1` do `'\0'`.
- Contar `size` separadores em vez de `size - 1`.
- `size == 0` devolvendo `NULL` ou um literal `""`: o subject pede uma string **alocada** (quem chama vai dar `free`; `free` num literal quebra o programa).
- Usar `ft_strcat` em laço: funciona, mas cada chamada percorre `res` desde o começo (fica lento com muitas strings). E exige `res[0] = '\0'` antes.
- Passar de 5 funções ou 25 linhas no arquivo.

## Casos extremos

- `size = 1` → só a primeira string, sem separador.
- `sep = ""` → strings coladas.
- Strings vazias no meio (`{"Ola", "Piscine", ""}` com `"+"`) → `"Ola+Piscine+"`.

## Conferindo leaks

```bash
./run.sh ft_strjoin
```

Manualmente:

```bash
cc -Wall -Wextra -Werror -g minha-versao/c03/ex02/ft_strjoin.c testes/ft_strjoin/main.c -o t
valgrind --leak-check=full ./t
```
