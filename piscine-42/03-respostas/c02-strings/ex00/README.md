# Resposta — c02/ex00: ft_strcpy

## Solução

```c
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
```

Arquivo: [`ft_strcpy.c`](ft_strcpy.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Copia caractere por caractere enquanto `src[i]` não for `'\0'`.
2. O laço para **sem copiar** o `'\0'`. Por isso a linha `dest[i] = '\0';` depois.
3. Devolve `dest` (é o que a `strcpy` padrão faz; permite encadear: `ft_putstr(ft_strcpy(buf, "oi"))`).

## Erros comuns

- **Esquecer o `'\0'` final.** É o erro mais clássico. O teste deste repositório enche o buffer de `X` antes, para o erro aparecer: sem o `'\0'`, a saída vira `OlaXXXXXXXX...`.
- Devolver `src` ou não devolver nada.
- Testar com um literal como destino (`ft_strcpy("abc", "x")`): segfault, porque literais são só-leitura.

## Casos extremos

- `src` vazio: o laço não roda e `dest[0] = '\0'`. Correto.
- `dest` menor que `src`: estouro de buffer. A função não tem como saber o tamanho de `dest` (é por isso que existe `strlcpy`, que você pode encontrar mais adiante).
- `NULL`: segfault (igual à padrão).

## Como testar

```bash
./run.sh ft_strcpy
```
