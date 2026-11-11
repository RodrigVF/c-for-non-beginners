# C04 — Recursão

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aula [10](../../01-exemplos/10-recursao/).

Mesmas regras gerais do C00. Nestes exercícios, a função **deve ser recursiva** (sem `while`).

---

## Exercise 00: ft_factorial 🟢

```
Exercise 00: ft_factorial
Turn-in directory : ex00/
Files to turn in  : ft_factorial.c
Allowed functions : nenhuma
```

Escreva uma função **recursiva** que devolva o fatorial de `nb`. Se `nb` for negativo, devolva `0`. O fatorial de `0` é `1`. Não é preciso tratar overflow (resultados maiores que `INT_MAX`).

```c
int	ft_factorial(int nb);
```

```
ft_factorial(5)    →   120
ft_factorial(0)    →   1
ft_factorial(-5)   →   0
```

<details>
<summary>Dica</summary>

Comece pelos casos base (negativo; 0 e 1). O caso geral é `nb * ft_factorial(nb - 1)`.

</details>

---

## Exercise 01: ft_power 🟡

```
Exercise 01: ft_power
Turn-in directory : ex01/
Files to turn in  : ft_power.c
Allowed functions : nenhuma
```

Escreva uma função **recursiva** que devolva `nb` elevado a `power`. Se `power` for negativo, devolva `0`. Por convenção, `0` elevado a `0` é `1`. Não é preciso tratar overflow.

```c
int	ft_power(int nb, int power);
```

```
ft_power(2, 10)   →   1024
ft_power(-2, 3)   →   -8
ft_power(0, 0)    →   1
ft_power(2, -1)   →   0
```

<details>
<summary>Dica</summary>

Qual é o caso base que resolve tanto `5^0` quanto `0^0`?

</details>
