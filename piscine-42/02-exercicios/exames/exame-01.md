# Exame 01 — simulação (30 minutos)

> Recriação. Regras de exame reais: confirme com a 42SP. Sem consulta, na ordem.

| Nível | Exercício | Tempo sugerido |
|---|---|---|
| 0 | `ft_print_reverse_alphabet` 🟢 | 5 min |
| 1 | `ft_strlen` 🟢 | 5 min |
| 2 | `ft_swap` 🟢 | 5 min |
| 3 | `ft_strrev` 🟡 | 15 min |

---

## Nível 0

```
Assignment name   : ft_print_reverse_alphabet
Expected files    : ft_print_reverse_alphabet.c
Allowed functions : write
```

Escreva uma função que mostre o alfabeto em minúsculas em ordem **decrescente**, numa única linha, a partir de `z`. Sem quebra de linha.

```c
void	ft_print_reverse_alphabet(void);
```

```
zyxwvutsrqponmlkjihgfedcba
```

---

## Nível 1

```
Assignment name   : ft_strlen
Expected files    : ft_strlen.c
Allowed functions : nenhuma
```

Escreva uma função que devolva o número de caracteres de uma string, sem contar o `'\0'`.

```c
int	ft_strlen(char *str);
```

---

## Nível 2

```
Assignment name   : ft_swap
Expected files    : ft_swap.c
Allowed functions : nenhuma
```

Escreva uma função que troque os valores de dois inteiros cujos endereços são recebidos.

```c
void	ft_swap(int *a, int *b);
```

---

## Nível 3

```
Assignment name   : ft_strrev
Expected files    : ft_strrev.c
Allowed functions : nenhuma
```

Escreva uma função que inverta a string recebida, no lugar, e devolva o próprio ponteiro.

```c
char	*ft_strrev(char *str);
```

```
"Piscine 42"   →   "24 enicsiP"
""             →   ""
```

---

Ao terminar:

```bash
./run.sh ft_print_reverse_alphabet
./run.sh ft_strlen
./run.sh ft_swap
./run.sh ft_strrev
```
