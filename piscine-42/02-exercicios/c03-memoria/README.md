# C03 — Alocação de memória

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aula [09](../../01-exemplos/09-malloc/).

Mesmas regras gerais do C00. Além disso:
- Sempre verifique o retorno do `malloc`.
- Quem chama a sua função é responsável pelo `free` (os testes fazem isso).
- O `run.sh` roda o `valgrind`: qualquer leak ou acesso inválido conta como erro.

---

## Exercise 00: ft_strdup 🟡

```
Exercise 00: ft_strdup
Turn-in directory : ex00/
Files to turn in  : ft_strdup.c
Allowed functions : malloc
```

Reproduza o comportamento da função `strdup` (`man 3 strdup`): aloque memória suficiente para uma cópia de `src`, copie e devolva o endereço da cópia. Se a alocação falhar, devolva `NULL`.

```c
char	*ft_strdup(char *src);
```

```
char *c = ft_strdup("Ola");   →   c contém "Ola", c != endereço do literal
free(c);
```

<details>
<summary>Dica</summary>

Tamanho + 1. Por quê? (Aula 09.)

</details>

---

## Exercise 01: ft_range 🟡

```
Exercise 01: ft_range
Turn-in directory : ex01/
Files to turn in  : ft_range.c
Allowed functions : malloc
```

Escreva uma função que devolva um array de `int` alocado com todos os valores de `min` (incluído) até `max` (excluído). Se `min >= max`, devolva `NULL`.

```c
int	*ft_range(int min, int max);
```

```
ft_range(0, 5)    →   {0, 1, 2, 3, 4}
ft_range(-3, 3)   →   {-3, -2, -1, 0, 1, 2}
ft_range(5, 5)    →   NULL
```

<details>
<summary>Dica</summary>

Quantos elementos? `max - min`. Quantos **bytes**? Multiplique por `sizeof(int)`. Cuidado com `max - min` para valores extremos (ex.: `min = -2147483648`): faça a conta em `long`.

</details>

---

## Exercise 02: ft_strjoin 🔴

```
Exercise 02: ft_strjoin
Turn-in directory : ex02/
Files to turn in  : ft_strjoin.c
Allowed functions : malloc
```

Escreva uma função que junte as `size` strings do array `strs` numa única string nova, alocada, colocando `sep` **entre** elas (não antes da primeira, nem depois da última).

Se `size` for `0` (ou negativo), devolva uma string vazia **alocada** (que possa receber `free`).

```c
char	*ft_strjoin(int size, char **strs, char *sep);
```

```
strs = {"Ola", "Piscine", "42"}
ft_strjoin(3, strs, ", ")   →   "Ola, Piscine, 42"
ft_strjoin(1, strs, ", ")   →   "Ola"
ft_strjoin(0, strs, ", ")   →   ""
```

<details>
<summary>Dica 1</summary>

Duas fases: (1) calcule o tamanho total (soma dos tamanhos + `sep` × (`size` − 1) + 1 para o `'\0'`); (2) aloque e copie.

</details>

<details>
<summary>Dica 2 (Norma)</summary>

Vai passar de 25 linhas se fizer tudo numa função. Crie auxiliares: `ft_strlen`, uma que calcula o tamanho total e uma que copia uma string e devolve onde parou. Máximo de 5 funções no arquivo.

</details>
