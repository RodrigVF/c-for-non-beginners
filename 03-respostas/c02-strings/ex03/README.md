# Resposta — c02/ex03: ft_str_is_numeric

## Solução

```c
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
```

Arquivo: [`ft_str_is_numeric.c`](ft_str_is_numeric.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. "Todos são dígitos" = "nenhum é não-dígito". Basta achar **um** fora do intervalo para devolver `0`.
2. Se o laço chegar ao `'\0'` sem achar nenhum, devolve `1`.
3. A string vazia não tem nenhum não-dígito, então devolve `1` (é o que o subject pede, e é a lógica do "para todo").

## Erros comuns

- Devolver `1` dentro do laço no primeiro dígito válido (`"1a"` daria `1`).
- `str[i] < 0 || str[i] > 9` (sem aspas): compara com os **números** 0 e 9, não com os caracteres.
- Usar `&&` na condição: `str[i] < '0' && str[i] > '9'` nunca é verdade.

## Casos extremos

- `""` → 1. `"-1"` → 0 (o sinal não é dígito). `" 1"` → 0. `"/:"` → 0 (os vizinhos de `'0'` e `'9'` na tabela ASCII).

## Como testar

```bash
./run.sh ft_str_is_numeric
```
