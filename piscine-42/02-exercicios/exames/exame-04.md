# Exame 04 — simulação com programas (40 minutos)

> Recriação. Regras de exame reais: confirme com a 42SP. Sem consulta, na ordem.
> Antes: aula [14 (`argc` e `argv`)](../../01-exemplos/14-argc-argv/) e o módulo [c05](../c05-programas/).

Todos os exercícios deste simulado são **programas**: o arquivo entregue tem `main`.

| Nível | Exercício | Tempo sugerido |
|---|---|---|
| 0 | `ft_last_arg` 🟢 | 6 min |
| 1 | `ft_show_args` 🟢 | 6 min |
| 2 | `ft_rev_args` 🟢 | 8 min |
| 3 | `ft_sort_args` 🟡 | 20 min |

---

## Nível 0

```
Assignment name   : ft_last_arg
Expected files    : ft_last_arg.c
Allowed functions : write
```

Escreva um programa que mostre o **último** argumento recebido, seguido de `\n`. Sem argumentos, mostra só o `\n`.

```
$> ./ft_last_arg um dois tres
tres
$> ./ft_last_arg
$> ./ft_last_arg "Piscine 42"
Piscine 42
```

(Na segunda chamada, a saída é uma linha vazia.)

---

## Nível 1

```
Assignment name   : ft_show_args
Expected files    : ft_show_args.c
Allowed functions : write
```

Mostre cada argumento, um por linha, sem o nome do programa.

---

## Nível 2

```
Assignment name   : ft_rev_args
Expected files    : ft_rev_args.c
Allowed functions : write
```

Mostre os argumentos em ordem inversa, um por linha, sem o nome do programa.

---

## Nível 3

```
Assignment name   : ft_sort_args
Expected files    : ft_sort_args.c
Allowed functions : write
```

Mostre os argumentos em ordem ASCII crescente (a ordem do `strcmp`), um por linha, sem o nome do programa.

---

Ao terminar:

```bash
./run.sh ft_last_arg
./run.sh ft_show_args
./run.sh ft_rev_args
./run.sh ft_sort_args
```
