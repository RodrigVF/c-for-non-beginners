# Resposta — c01/ex02: ft_ultimate_div_mod

## Solução

```c
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	quociente;
	int	resto;

	quociente = *a / *b;
	resto = *a % *b;
	*a = quociente;
	*b = resto;
}
```

Arquivo: [`ft_ultimate_div_mod.c`](ft_ultimate_div_mod.c) (com o cabeçalho da 42 no topo)

## Raciocínio

Os dois resultados vão para as **mesmas** variáveis que são as entradas. Se escrever em `*a` primeiro, o valor original some:

```c
*a = *a / *b;    /* *a agora é 4 */
*b = *a % *b;    /* 4 % 10 = 4  ← ERRADO, devia ser 42 % 10 = 2 */
```

Solução: calcular tudo primeiro em variáveis locais, depois escrever.

## Erros comuns

- A ordem acima (sobrescrever antes de usar).
- Usar só uma variável temporária e trocar a ordem errada. Duas variáveis deixam tudo explícito.

## Casos extremos

- `*b == 0`: não precisa tratar (divisão por zero).
- Negativos: mesmas regras do `ft_div_mod`.

## Como testar

```bash
./run.sh ft_ultimate_div_mod
```
