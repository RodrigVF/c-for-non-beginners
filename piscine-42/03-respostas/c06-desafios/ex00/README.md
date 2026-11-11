# Resposta — c06/ex00: ft_strncmp

## Solução

```c
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```

Arquivo: [`ft_strncmp.c`](ft_strncmp.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. É o `ft_strcmp` com um limite: o laço também para quando chega ao último caractere permitido (`i < n - 1`).
2. Por que `n - 1` e não `n`? O laço avança **enquanto** os caracteres são iguais. Parando em `n - 1`, a comparação final (`s1[i] - s2[i]`) ainda olha o `n`-ésimo caractere. Com `i < n`, a função compararia um caractere a mais.
3. `n == 0` é tratado antes: sem isso, `n - 1` com `n` sem sinal valeria `4294967295`, e a função compararia a string inteira.

```
ft_strncmp("abc", "abd", 2)
i=0: 'a' == 'a', i < 1 → avança
i=1: para (i < n - 1 é falso)
compara s1[1] - s2[1] = 'b' - 'b' = 0
```

## Erros comuns

- Esquecer o caso `n == 0` (o `unsigned int` "dá a volta").
- Usar `int` no contador e comparar com `unsigned int`: o `-Wextra` acusa `comparison of integer expressions of different signedness`.
- Comparar `n` caracteres a mais ou a menos (teste com `n` igual ao ponto em que as strings diferem).

## Casos extremos

`n` maior que as strings (para no `'\0'`), strings vazias, caracteres acima de 127 (por isso o `unsigned char`).

## Como testar

```bash
./run.sh ft_strncmp
```
