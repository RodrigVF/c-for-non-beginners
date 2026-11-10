# Resposta — c04/ex00: ft_factorial

## Solução

```c
int	ft_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	return (nb * ft_factorial(nb - 1));
}
```

Arquivo: [`ft_factorial.c`](ft_factorial.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Casos base primeiro: negativo → `0`; `0` e `1` → `1`.
2. Caso geral: `n! = n × (n-1)!`.

```
ft_factorial(4)
= 4 * ft_factorial(3)
= 4 * 3 * ft_factorial(2)
= 4 * 3 * 2 * ft_factorial(1)
= 4 * 3 * 2 * 1 = 24
```

## Erros comuns

- Sem o teste de negativo: `ft_factorial(-5)` chama `-6`, `-7`... até estourar a stack (segfault).
- Caso base só em `nb == 1`: `ft_factorial(0)` desce para os negativos.
- Usar `while` quando o subject pede recursão.

## Casos extremos

- `13!` não cabe num `int` (passa de `INT_MAX`). O subject diz que não precisa tratar; o teste vai até `12!` = `479001600`.

## Como testar

```bash
./run.sh ft_factorial
```
