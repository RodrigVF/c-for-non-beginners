# Resposta — c00/ex05: ft_strlen

## Solução

```c
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
```

Arquivo: [`ft_strlen.c`](ft_strlen.c) (com o cabeçalho da 42 no topo)

## Raciocínio

```
str:   [ O ][ l ][ a ][\0]
índice:  0    1    2    3
                        ↑ o laço para aqui: i = 3 = tamanho
```

O índice onde está o `'\0'` é exatamente a quantidade de caracteres antes dele.

## Erros comuns

- Devolver `i + 1` ("contando o `\0`"): errado; `strlen` não conta.
- Começar `i` em 1.
- Esquecer `return (i);` ou escrever `return i;` (válido em C, mas a Norma exige parênteses).

## Casos extremos

- `""` → `0`.
- `"tem\0coisa"` → `3`: a string "acaba" no primeiro `'\0'`.
- `NULL` → segfault (igual à `strlen` padrão).

## Como testar

```bash
./run.sh ft_strlen
```
