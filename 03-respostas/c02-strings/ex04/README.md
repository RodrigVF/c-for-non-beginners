# Resposta — c02/ex04: ft_strcat

## Solução

```c
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
```

Arquivo: [`ft_strcat.c`](ft_strcat.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. `i` anda até o `'\0'` de `dest`: é ali que `src` deve começar.
2. Copia `src` a partir de `dest[i]`, usando `j` para `src` e `i + j` para `dest`.
3. Termina com `'\0'` e devolve `dest`.

```
dest: [O][l][a][,][ ][\0][ ][ ]...
                     ↑ i = 5
dest: [O][l][a][,][ ][P][i][s][c][i][n][e][\0]
```

## Erros comuns

- Esquecer o `'\0'` final.
- Começar a copiar em `i + 1` (pula o `'\0'` e deixa ele no meio, então a string "acaba" antes).
- Usar só `i` e escrever `dest[i] = src[i]`: copia na posição errada.

## Casos extremos

- `src` vazio: `dest` não muda. `dest` vazio: vira cópia de `src`.
- `dest` sem espaço: estouro de buffer. A função não tem como saber (existe `strlcat` para isso).

## Como testar

```bash
./run.sh ft_strcat
```
