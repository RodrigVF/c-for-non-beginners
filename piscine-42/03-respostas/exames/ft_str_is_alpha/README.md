# Resposta — exame 02, nível 0: ft_str_is_alpha

## Solução

```c
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
```

Arquivo: [`ft_str_is_alpha.c`](ft_str_is_alpha.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Mesmo esqueleto do `ft_str_is_numeric`: procura **um** caractere inválido.
2. "É letra" = minúscula **ou** maiúscula. Nega-se a condição inteira com `!( ... )`.
3. A condição longa foi quebrada em duas linhas para respeitar as 80 colunas (a Norma pede a quebra com indentação extra).

## Erros comuns

- `str[i] < 'A' || str[i] > 'z'`: aceita os 6 símbolos que ficam **entre** `'Z'` (90) e `'a'` (97) na tabela ASCII: `[`, `]`, `^`, `_`, a barra invertida e o acento grave. O último caso do teste (com `@`, `[`, acento grave e `{`, os vizinhos das letras) existe para pegar isso.
- Esquecer as maiúsculas.

## Casos extremos

- `""` → 1. `"a b"` → 0 (espaço não é letra). `"Ola!"` → 0.

## Como testar

```bash
./run.sh ft_str_is_alpha
```
