# C02 — Strings

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aulas [07](../../01-exemplos/07-arrays-strings/) e [08](../../01-exemplos/08-ponteiros/).

Mesmas regras gerais do C00. Em todos os exercícios, suponha que os ponteiros recebidos são válidos e que o destino tem espaço suficiente.

---

## Exercise 00: ft_strcpy 🟢

```
Exercise 00: ft_strcpy
Turn-in directory : ex00/
Files to turn in  : ft_strcpy.c
Allowed functions : nenhuma
```

Reproduza o comportamento da função `strcpy` (`man 3 strcpy`): copie `src` (incluindo o `'\0'`) para `dest` e devolva `dest`.

```c
char	*ft_strcpy(char *dest, char *src);
```

```
char buf[20];
ft_strcpy(buf, "Ola")   →   buf contém "Ola", retorno == buf
```

<details>
<summary>Dica</summary>

O laço para **antes** de copiar o `'\0'`. Não esqueça de colocá-lo depois.

</details>

---

## Exercise 01: ft_strcmp 🟡

```
Exercise 01: ft_strcmp
Turn-in directory : ex01/
Files to turn in  : ft_strcmp.c
Allowed functions : nenhuma
```

Reproduza o comportamento da função `strcmp` (`man 3 strcmp`): compare `s1` e `s2` caractere a caractere e devolva um número **negativo** se `s1` vem antes, **zero** se são iguais, **positivo** se `s1` vem depois. A comparação usa os caracteres como `unsigned char`.

```c
int	ft_strcmp(char *s1, char *s2);
```

```
ft_strcmp("abc", "abc")   →   0
ft_strcmp("abc", "abd")   →   negativo
ft_strcmp("abc", "ab")    →   positivo
ft_strcmp("", "a")        →   negativo
```

<details>
<summary>Dica</summary>

Avance enquanto os caracteres forem iguais e `s1` não tiver acabado. Quando parar, a diferença entre os dois caracteres atuais é a resposta.

</details>

---

## Exercise 02: ft_strrev 🟡

```
Exercise 02: ft_strrev
Turn-in directory : ex02/
Files to turn in  : ft_strrev.c
Allowed functions : nenhuma
```

Escreva uma função que inverta a string **no lugar** (alterando a própria string) e a devolva.

```c
char	*ft_strrev(char *str);
```

```
"abc"         →   "cba"
"abcd"        →   "dcba"
""            →   ""
```

<details>
<summary>Dica</summary>

Dois índices: um no começo, outro no último caractere (não no `'\0'`). Troque e aproxime os dois até se cruzarem. É o `ft_swap` aplicado a `char`.

</details>

---

## Exercise 03: ft_str_is_numeric 🟢

```
Exercise 03: ft_str_is_numeric
Turn-in directory : ex03/
Files to turn in  : ft_str_is_numeric.c
Allowed functions : nenhuma
```

Escreva uma função que devolva `1` se a string contém **apenas** dígitos (`'0'` a `'9'`), e `0` caso contrário. A string vazia devolve `1`.

```c
int	ft_str_is_numeric(char *str);
```

```
"123"   →   1
""      →   1
"12a"   →   0
"-1"    →   0
```

<details>
<summary>Dica</summary>

Assim que achar um caractere fora do intervalo, devolva `0`. Se o laço terminar, devolva `1`.

</details>

---

## Exercise 04: ft_strcat 🟡

```
Exercise 04: ft_strcat
Turn-in directory : ex04/
Files to turn in  : ft_strcat.c
Allowed functions : nenhuma
```

Reproduza o comportamento da função `strcat` (`man 3 strcat`): acrescente `src` no fim de `dest` (sobrescrevendo o `'\0'` de `dest`), termine com `'\0'` e devolva `dest`.

```c
char	*ft_strcat(char *dest, char *src);
```

```
char buf[20] contendo "Ola, ";
ft_strcat(buf, "Piscine")   →   buf contém "Ola, Piscine"
```

<details>
<summary>Dica</summary>

Primeiro ache o fim de `dest`. Depois é um `ft_strcpy` começando dali.

</details>
