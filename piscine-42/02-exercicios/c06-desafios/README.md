# C06 — Desafios

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: tudo até a aula [10](../../01-exemplos/10-recursao/). O ex02 usa `malloc` (aula [09](../../01-exemplos/09-malloc/)).

Exercícios mais difíceis, que juntam o que você viu nos outros módulos. Mesmas regras gerais do C00. Não tenha pressa: errar aqui é o normal.

---

## Exercise 00: ft_strncmp 🟡

```
Exercise 00: ft_strncmp
Turn-in directory : ex00/
Files to turn in  : ft_strncmp.c
Allowed functions : nenhuma
```

Reproduza o comportamento da função `strncmp` (`man 3 strncmp`): como o `ft_strcmp`, mas comparando **no máximo `n` caracteres**. Com `n == 0`, as strings são consideradas iguais.

```c
int	ft_strncmp(char *s1, char *s2, unsigned int n);
```

```
ft_strncmp("abc", "abd", 2)    →   0         (só "ab" é comparado)
ft_strncmp("abc", "abd", 3)    →   negativo
ft_strncmp("ab", "abc", 3)     →   negativo  ('\0' < 'c')
ft_strncmp("abc", "xyz", 0)    →   0
```

<details>
<summary>Dica</summary>

Parta do seu `ft_strcmp` e acrescente uma condição ao laço. Cuidado com `n == 0` e com o tipo `unsigned int`: `n - 1` com `n` valendo `0` não dá `-1`.

</details>

---

## Exercise 01: ft_putnbr_base 🔴

```
Exercise 01: ft_putnbr_base
Turn-in directory : ex01/
Files to turn in  : ft_putnbr_base.c
Allowed functions : write
```

Escreva uma função que mostre o número `nbr` escrito na base dada pela string `base`. O tamanho da string é a base, e cada caractere é um "dígito": `"01"` é binário, `"0123456789ABCDEF"` é hexadecimal, `"poneyvif"` é octal com outros símbolos.

A função não mostra nada se a base for **inválida**:
- tem menos de 2 caracteres;
- tem algum caractere repetido;
- contém `+` ou `-`.

```c
void	ft_putnbr_base(int nbr, char *base);
```

```
ft_putnbr_base(255, "0123456789ABCDEF")   →   FF
ft_putnbr_base(-42, "01")                 →   -101010
ft_putnbr_base(10, "poneyvif")            →   on
ft_putnbr_base(42, "0120")                →   (nada: '0' repetido)
```

Deve funcionar para todos os valores de `int`, inclusive `INT_MIN`.

<details>
<summary>Dica 1</summary>

É o `ft_putnbr` com `10` trocado pelo tamanho da base, e `'0' + dígito` trocado por `base[dígito]`.

</details>

<details>
<summary>Dica 2</summary>

Separe em funções: uma valida a base e devolve o tamanho (ou `0` se for inválida), outra escreve o número recursivamente. Para o `INT_MIN`, trabalhe com `long`.

</details>

---

## Exercise 02: ft_split 🔴

```
Exercise 02: ft_split
Turn-in directory : ex02/
Files to turn in  : ft_split.c
Allowed functions : malloc, free
```

Escreva uma função que quebre a string `str` em palavras, usando como separador **qualquer** caractere presente em `charset`. A função devolve um array de strings, alocado com `malloc`, terminado por um ponteiro `NULL`. Separadores seguidos, no começo ou no fim não geram palavras vazias.

```c
char	**ft_split(char *str, char *charset);
```

```
ft_split("  Ola  Piscine 42 ", " ")   →   {"Ola", "Piscine", "42", NULL}
ft_split("a,b;;c", ",;")              →   {"a", "b", "c", NULL}
ft_split("    ", " ")                 →   {NULL}
```

Quem chama dá `free` em cada palavra e depois no array. O teste confere leaks com o `valgrind`.

<details>
<summary>Dica 1</summary>

Três etapas: (1) contar as palavras para saber o tamanho do array (+1 para o `NULL`); (2) para cada palavra, medir e copiar com `malloc` (como no `ft_strdup`); (3) colocar o `NULL` no fim.

</details>

<details>
<summary>Dica 2 (Norma)</summary>

Uma função `ft_eh_sep(char c, char *charset)` que diz se `c` é separador simplifica todo o resto. São 5 funções no máximo: planeje antes de escrever.

</details>
