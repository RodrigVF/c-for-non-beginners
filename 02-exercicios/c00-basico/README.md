# C00 — Primeiros passos em C

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aulas [01](../../01-exemplos/01-anatomia/) a [05](../../01-exemplos/05-if-while/).

Regras gerais (valem para todos os módulos de C):
- Compilação com `cc -Wall -Wextra -Werror`.
- O código segue a Norma (verifique com `norminette`).
- **Não entregue `main`.** Seu arquivo contém só a(s) função(ões).
- Use apenas as *allowed functions*. Nada de `printf`.
- Teste com `./run.sh <nome_da_funcao>`.

---

## Exercise 00: ft_putchar 🟢

```
Exercise 00: ft_putchar
Turn-in directory : ex00/
Files to turn in  : ft_putchar.c
Allowed functions : write
```

Escreva uma função que mostre o caractere recebido como parâmetro.

```c
void	ft_putchar(char c);
```

```
ft_putchar('4'); ft_putchar('2');   →   42
```

<details>
<summary>Dica</summary>

`write` precisa de um **endereço**, não do caractere. Como pegar o endereço de `c`? (Aula 08, operador `&`.)

</details>

---

## Exercise 01: ft_print_alphabet 🟢

```
Exercise 01: ft_print_alphabet
Turn-in directory : ex01/
Files to turn in  : ft_print_alphabet.c
Allowed functions : write
```

Escreva uma função que mostre o alfabeto em minúsculas, em ordem crescente, numa única linha, a partir de `a`. Sem quebra de linha no final.

```c
void	ft_print_alphabet(void);
```

```
abcdefghijklmnopqrstuvwxyz
```

<details>
<summary>Dica</summary>

`char` é número (aula 03). Uma variável que começa em `'a'` e vai até `'z'` com `++`.

</details>

---

## Exercise 02: ft_print_numbers 🟢

```
Exercise 02: ft_print_numbers
Turn-in directory : ex02/
Files to turn in  : ft_print_numbers.c
Allowed functions : write
```

Escreva uma função que mostre todos os dígitos, em ordem crescente, numa única linha. Sem quebra de linha.

```c
void	ft_print_numbers(void);
```

```
0123456789
```

<details>
<summary>Dica</summary>

Você quer imprimir o **caractere** `'0'` (código 48), não o número `0` (que é o caractere nulo, invisível).

</details>

---

## Exercise 03: ft_is_negative 🟢

```
Exercise 03: ft_is_negative
Turn-in directory : ex03/
Files to turn in  : ft_is_negative.c
Allowed functions : write
```

Escreva uma função que mostre `N` se o inteiro recebido for negativo, e `P` se for positivo **ou zero**.

```c
void	ft_is_negative(int n);
```

```
ft_is_negative(-3)   →   N
ft_is_negative(0)    →   P
ft_is_negative(42)   →   P
```

<details>
<summary>Dica</summary>

`write(1, "N", 1)`: uma string literal já é um endereço. Atenção ao zero.

</details>

---

## Exercise 04: ft_putstr 🟢

```
Exercise 04: ft_putstr
Turn-in directory : ex04/
Files to turn in  : ft_putstr.c
Allowed functions : write
```

Escreva uma função que mostre, um a um, os caracteres de uma string.

```c
void	ft_putstr(char *str);
```

```
ft_putstr("Ola, Piscine!")   →   Ola, Piscine!
ft_putstr("")                →   (nada)
```

<details>
<summary>Dica</summary>

Percorra até encontrar `'\0'` (aula 07). Desafio extra: faça com **um único** `write`, depois de descobrir o tamanho.

</details>

---

## Exercise 05: ft_strlen 🟢

```
Exercise 05: ft_strlen
Turn-in directory : ex05/
Files to turn in  : ft_strlen.c
Allowed functions : nenhuma
```

Escreva uma função que conte e devolva o número de caracteres de uma string (sem contar o `'\0'`).

```c
int	ft_strlen(char *str);
```

```
ft_strlen("")      →   0
ft_strlen("42")    →   2
ft_strlen("Ola")   →   3
```

<details>
<summary>Dica</summary>

É o mesmo laço do `ft_putstr`, sem o `write`. O índice onde está o `'\0'` é exatamente o tamanho.

</details>

---

## Exercise 06: ft_putnbr 🔴

```
Exercise 06: ft_putnbr
Turn-in directory : ex06/
Files to turn in  : ft_putnbr.c
Allowed functions : write
```

Escreva uma função que mostre o número inteiro recebido. A função deve funcionar para **todos** os valores de `int`, incluindo `-2147483648` e `2147483647`.

```c
void	ft_putnbr(int nb);
```

```
ft_putnbr(42)            →   42
ft_putnbr(-7)            →   -7
ft_putnbr(0)             →   0
ft_putnbr(-2147483648)   →   -2147483648
```

<details>
<summary>Dica 1</summary>

`nb % 10` é o último dígito; `nb / 10` é o número sem ele (aula 04). Os dígitos saem "de trás para frente": recursão (aula 10) resolve a ordem.

</details>

<details>
<summary>Dica 2 (INT_MIN)</summary>

Se `nb` for negativo, a ideia natural é imprimir `-` e fazer `nb = -nb`. Mas `-(-2147483648)` não cabe num `int` (aula 03). Trate esse caso à parte, ou copie o valor para um `long` antes de inverter.

</details>
