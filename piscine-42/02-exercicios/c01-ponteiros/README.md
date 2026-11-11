# C01 — Ponteiros

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aulas [06](../../01-exemplos/06-funcoes/) e [08](../../01-exemplos/08-ponteiros/).

Mesmas regras gerais do C00. **Desenhe caixas e setas no papel** antes de codar.

---

## Exercise 00: ft_swap 🟢

```
Exercise 00: ft_swap
Turn-in directory : ex00/
Files to turn in  : ft_swap.c
Allowed functions : nenhuma
```

Escreva uma função que troque os valores de dois inteiros cujos endereços são passados como parâmetros.

```c
void	ft_swap(int *a, int *b);
```

```
x = 1; y = 2;
ft_swap(&x, &y);
→ x vale 2, y vale 1
```

<details>
<summary>Dica</summary>

Você precisa de uma variável temporária. E lembre: `a` é o endereço; `*a` é o valor.

</details>

---

## Exercise 01: ft_div_mod 🟡

```
Exercise 01: ft_div_mod
Turn-in directory : ex01/
Files to turn in  : ft_div_mod.c
Allowed functions : nenhuma
```

Escreva uma função que divida `a` por `b`, guarde o quociente no `int` apontado por `div` e o resto no `int` apontado por `mod`. Não é preciso tratar `b == 0`.

```c
void	ft_div_mod(int a, int b, int *div, int *mod);
```

```
ft_div_mod(42, 10, &d, &m)   →   d = 4, m = 2
ft_div_mod(-7, 2, &d, &m)    →   d = -3, m = -1
```

<details>
<summary>Dica</summary>

É assim que uma função em C "devolve" dois valores: escrevendo nos endereços recebidos.

</details>

---

## Exercise 02: ft_ultimate_div_mod 🟡

```
Exercise 02: ft_ultimate_div_mod
Turn-in directory : ex02/
Files to turn in  : ft_ultimate_div_mod.c
Allowed functions : nenhuma
```

Escreva uma função que divida `*a` por `*b`. O quociente deve ser guardado em `*a` e o resto em `*b`. Não é preciso tratar `*b == 0`.

```c
void	ft_ultimate_div_mod(int *a, int *b);
```

```
a = 42; b = 10;
ft_ultimate_div_mod(&a, &b);
→ a vale 4, b vale 2
```

<details>
<summary>Dica</summary>

Se você fizer `*a = *a / *b;` primeiro, o valor original de `*a` some antes de calcular o resto. Guarde os resultados em variáveis antes de escrever.

</details>
