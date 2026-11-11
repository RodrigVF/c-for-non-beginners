# Resposta — c04/ex01: ft_power

## Solução

```c
int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
```

Arquivo: [`ft_power.c`](ft_power.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. `power < 0` → `0` (o subject define assim, já que o resultado não seria inteiro).
2. `power == 0` → `1`. Esse caso base cobre `0^0 = 1` também, sem `if` extra.
3. Caso geral: `nb^p = nb × nb^(p-1)`.

## Erros comuns

- Testar `nb == 0` antes e devolver `0`: erra `0^0`.
- Esquecer `power < 0`: recursão infinita (`-1`, `-2`, ...) e segfault.

## Casos extremos

- `(-2, 3)` → `-8` (o sinal sai naturalmente da multiplicação).
- `(0, 3)` → `0`. `(0, 0)` → `1`.

## Para ir além

Dá para fazer em menos chamadas com "exponenciação rápida": `nb^p = (nb^(p/2))^2`. Não é cobrado aqui.

## Como testar

```bash
./run.sh ft_power
```
