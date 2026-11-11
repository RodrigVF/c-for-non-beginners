# Resposta — c02/ex02: ft_strrev

## Solução

```c
char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	while (str[j] != '\0')
		j++;
	j--;
	i = 0;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
```

Arquivo: [`ft_strrev.c`](ft_strrev.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Acha o tamanho, e coloca `j` no **último caractere** (`tamanho - 1`), não no `'\0'`.
2. Dois índices se aproximando, trocando os caracteres:

```
 i           j
[P][i][s][c][i][n][e]
 e ↔ P  →  i++, j--
    i     j
[e][i][s][c][i][n][P]
...até i >= j
```

3. Para em `i < j`: com tamanho ímpar, o do meio fica no lugar; com par, os índices se cruzam.

## Erros comuns

- `j` no `'\0'`: o `'\0'` vai para o começo e a string vira vazia.
- Percorrer até o fim (`i < tamanho`) em vez de até o meio: troca tudo duas vezes e a string volta ao original.
- Testar com literal (`ft_strrev("abc")`): segfault, literais não podem ser alterados. Use `char buf[...]`.
- Declarar `int i, j;` numa linha: Norma.

## Casos extremos

- `""`: `j` vira `-1`, `0 < -1` é falso, nada acontece. Correto.
- Um caractere: `i = 0`, `j = 0`, nada a trocar.

## Como testar

```bash
./run.sh ft_strrev
```
