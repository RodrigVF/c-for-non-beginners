# Exame 02 — simulação (40 minutos)

> Recriação. Regras de exame reais: confirme com a 42SP. Sem consulta, na ordem.

| Nível | Exercício | Tempo sugerido |
|---|---|---|
| 0 | `ft_str_is_alpha` 🟢 | 5 min |
| 1 | `ft_strcmp` 🟡 | 8 min |
| 2 | `ft_putnbr` 🔴 | 12 min |
| 3 | `ft_range` 🟡 | 15 min |

---

## Nível 0

```
Assignment name   : ft_str_is_alpha
Expected files    : ft_str_is_alpha.c
Allowed functions : nenhuma
```

Escreva uma função que devolva `1` se a string contém **apenas** letras (`a` a `z` ou `A` a `Z`), e `0` caso contrário. A string vazia devolve `1`.

```c
int	ft_str_is_alpha(char *str);
```

```
"abc"      →   1
"ABCdef"   →   1
""         →   1
"abc1"     →   0
"a b"      →   0
```

---

## Nível 1

```
Assignment name   : ft_strcmp
Expected files    : ft_strcmp.c
Allowed functions : nenhuma
```

Reproduza o comportamento de `strcmp`: devolva negativo, zero ou positivo conforme `s1` seja menor, igual ou maior que `s2`, comparando os caracteres como `unsigned char`.

```c
int	ft_strcmp(char *s1, char *s2);
```

---

## Nível 2

```
Assignment name   : ft_putnbr
Expected files    : ft_putnbr.c
Allowed functions : write
```

Escreva uma função que mostre o inteiro recebido, para todos os valores possíveis de `int`.

```c
void	ft_putnbr(int nb);
```

```
-2147483648   →   -2147483648
0             →   0
```

---

## Nível 3

```
Assignment name   : ft_range
Expected files    : ft_range.c
Allowed functions : malloc
```

Devolva um array alocado com os inteiros de `min` (incluído) a `max` (excluído). Se `min >= max`, devolva `NULL`.

```c
int	*ft_range(int min, int max);
```

---

Ao terminar:

```bash
./run.sh ft_str_is_alpha
./run.sh ft_strcmp
./run.sh ft_putnbr
./run.sh ft_range
```
