# Resposta — exame 03, nível 2: ft_atoi

## Solução

```c
int	ft_atoi(char *str)
{
	int		i;
	int		sinal;
	long	resultado;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sinal = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -sinal;
		i++;
	}
	resultado = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = resultado * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(resultado * sinal));
}
```

Arquivo: [`ft_atoi.c`](ft_atoi.c) (com o cabeçalho da 42 no topo)

## Raciocínio

São três laços, um para cada regra do enunciado, **na ordem**:

1. **Espaços:** `' '` e os caracteres de `'\t'` (9) a `'\r'` (13), que são consecutivos na tabela ASCII: `\t \n \v \f \r`.
2. **Sinais:** cada `-` inverte o sinal (`sinal = -sinal`). Número ímpar de `-` → negativo.
3. **Dígitos:** a construção clássica `resultado = resultado * 10 + dígito`:

```
"427"
resultado = 0
'4': 0 * 10 + 4 = 4
'2': 4 * 10 + 2 = 42
'7': 42 * 10 + 7 = 427
```

**Por que `long`?** Para `"-2147483648"`, o valor sem sinal (`2147483648`) não cabe num `int`. Em `long` (8 bytes), cabe; multiplicado pelo sinal, vira `-2147483648`, que cabe no `int` de retorno.

## Erros comuns

- Aceitar espaços **depois** dos sinais (`"- 3"` deve dar `0`).
- Aceitar sinais depois dos espaços... e espaços de novo. A ordem é fixa: espaços → sinais → dígitos.
- Esquecer `'\v'` e `'\f'` na lista de espaços.
- `str[i] - 48` funciona, mas `str[i] - '0'` é mais claro.
- Acumular em `int`: `INT_MIN` estoura no último dígito.

## Casos extremos

`""` → 0, `"abc"` → 0, `"0042"` → 42, `" 1 2"` → 1, `"--+-5"` → -5, `"2147483647"`, `"-2147483648"`.

## Como testar

```bash
./run.sh ft_atoi
```
