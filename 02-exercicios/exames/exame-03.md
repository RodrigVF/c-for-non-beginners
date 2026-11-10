# Exame 03 — simulação (45 minutos)

> Recriação. Regras de exame reais: confirme com a 42SP. Sem consulta, na ordem.

| Nível | Exercício | Tempo sugerido |
|---|---|---|
| 0 | `ft_power` 🟡 | 5 min |
| 1 | `ft_strdup` 🟡 | 8 min |
| 2 | `ft_atoi` 🔴 | 12 min |
| 3 | `ft_strjoin` 🔴 | 20 min |

---

## Nível 0

```
Assignment name   : ft_power
Expected files    : ft_power.c
Allowed functions : nenhuma
```

Escreva uma função **recursiva** que devolva `nb` elevado a `power`. Se `power < 0`, devolva `0`. `0` elevado a `0` é `1`.

```c
int	ft_power(int nb, int power);
```

---

## Nível 1

```
Assignment name   : ft_strdup
Expected files    : ft_strdup.c
Allowed functions : malloc
```

Reproduza o comportamento de `strdup`: devolva uma cópia alocada de `src`, ou `NULL` se a alocação falhar.

```c
char	*ft_strdup(char *src);
```

---

## Nível 2

```
Assignment name   : ft_atoi
Expected files    : ft_atoi.c
Allowed functions : nenhuma
```

Escreva uma função que converta o começo da string `str` num `int`, seguindo estas regras **nesta ordem**:

1. Ignore espaços em branco iniciais: `' '`, `'\t'`, `'\n'`, `'\v'`, `'\f'`, `'\r'`.
2. Leia **qualquer quantidade** de sinais `+` e `-`. O resultado é negativo se o número de `-` for **ímpar**.
3. Leia os dígitos seguintes e pare no primeiro caractere que não for dígito.

Se não houver dígitos, devolva `0`. O resultado deve estar correto para todos os valores que cabem num `int`, inclusive `-2147483648`. Valores fora do intervalo de `int` não serão testados.

```c
int	ft_atoi(char *str);
```

```
"42"            →   42
"   -42"        →   -42
" \t +17abc"    →   17
"--+-5"         →   -5      (três sinais -)
"+-+-12"        →   12      (dois sinais -)
" 1 2"          →   1
"- 3"           →   0       (espaço depois do sinal: não há dígitos)
"abc"           →   0
```

> Atenção: estas regras de sinais são deste exercício. A `atoi` da biblioteca padrão aceita só **um** sinal.

---

## Nível 3

```
Assignment name   : ft_strjoin
Expected files    : ft_strjoin.c
Allowed functions : malloc
```

Junte as `size` strings de `strs` numa nova string alocada, com `sep` entre elas. Se `size <= 0`, devolva uma string vazia alocada.

```c
char	*ft_strjoin(int size, char **strs, char *sep);
```

```
{"Ola", "Piscine", "42"}, sep ", "   →   "Ola, Piscine, 42"
```

---

Ao terminar:

```bash
./run.sh ft_power
./run.sh ft_strdup
./run.sh ft_atoi
./run.sh ft_strjoin
```
