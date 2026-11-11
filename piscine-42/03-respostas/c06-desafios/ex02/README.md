# Resposta — c06/ex02: ft_split

## Solução

```c
#include <stdlib.h>

int	ft_eh_sep(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_conta_palavras(char *str, char *charset)
{
	int	total;

	total = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && ft_eh_sep(*str, charset))
			str++;
		if (*str != '\0')
			total++;
		while (*str != '\0' && !ft_eh_sep(*str, charset))
			str++;
	}
	return (total);
}

char	*ft_copia_palavra(char *str, char *charset)
{
	char	*palavra;
	int		len;
	int		i;

	len = 0;
	while (str[len] != '\0' && !ft_eh_sep(str[len], charset))
		len++;
	palavra = malloc(sizeof(char) * (len + 1));
	if (palavra == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		palavra[i] = str[i];
		i++;
	}
	palavra[i] = '\0';
	return (palavra);
}

char	**ft_libera(char **tab, int ate)
{
	while (ate > 0)
	{
		ate--;
		free(tab[ate]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (ft_conta_palavras(str, charset) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!ft_eh_sep(*str, charset))
		{
			tab[i] = ft_copia_palavra(str, charset);
			if (tab[i] == NULL)
				return (ft_libera(tab, i));
			i++;
			while (*str != '\0' && !ft_eh_sep(*str, charset))
				str++;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
```

Arquivo: [`ft_split.c`](ft_split.c) (com o cabeçalho da 42 no topo)

## Raciocínio

O exercício tem cinco pequenas tarefas, uma por função (o máximo da Norma):

| Função | Faz |
|---|---|
| `ft_eh_sep` | diz se um caractere está no `charset` |
| `ft_conta_palavras` | conta as palavras, para saber o tamanho do array |
| `ft_copia_palavra` | aloca e copia uma palavra (como o `ft_strdup`, mas parando no separador) |
| `ft_libera` | se um `malloc` falhar no meio, libera tudo o que já foi alocado |
| `ft_split` | junta tudo |

Na memória, o resultado de `ft_split("Ola Piscine", " ")` fica assim:

```
tab ──> [ ptr ][ ptr ][ NULL ]        ← 1 malloc: (2 palavras + 1) ponteiros
          │      │
          │      └──> "Piscine\0"     ← 1 malloc por palavra
          └─────────> "Ola\0"
```

Por isso quem chama dá `free` em cada palavra **e** no array: são 3 blocos, então 3 `free`.

O laço principal anda pela string. Se o caractere não é separador, começou uma palavra: copia, avança `i` e pula até o fim da palavra. Se é separador, só avança. Assim, separadores repetidos, no começo ou no fim, nunca geram palavras vazias.

## Erros comuns

- Alocar o array sem o `+ 1` do `NULL` final: o `valgrind` acusa *invalid write*.
- `sizeof(char)` em vez de `sizeof(char *)` no array: aloca 8 vezes menos memória do que o necessário.
- Gerar palavras vazias com separadores seguidos (`"a,,b"`).
- Não liberar as palavras já alocadas quando um `malloc` falha no meio (leak no caminho de erro).
- Passar de 25 linhas no `ft_split`: separe a contagem e a cópia.

## Casos extremos

String vazia ou só separadores (devolve `{NULL}`), `charset` vazio (a string inteira é uma palavra), separadores no começo e no fim.

## Conferindo leaks

O `run.sh` roda o `valgrind` sozinho. Manualmente:

```bash
cc -Wall -Wextra -Werror -g minha-versao/c06/ex02/ft_split.c testes/ft_split/main.c -o t
valgrind --leak-check=full ./t
```

Procure `All heap blocks were freed -- no leaks are possible`.

## Como testar

```bash
./run.sh ft_split
```
