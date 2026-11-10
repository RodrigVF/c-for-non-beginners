# 01 — Exemplos (aulas)

Cada aula tem um `README.md` curto (5 a 10 minutos) e programas `.c` ao lado. Leia, **compile e rode** cada exemplo: ver a saída com seus olhos fixa muito mais do que só ler.

| # | Aula | Ideia |
|---|---|---|
| 01 | [Anatomia de um programa](01-anatomia/) | `main`, `write`, `return`, `echo $?` |
| 02 | [Compilação](02-compilacao/) | pré-processador, compilador, linker, protótipos |
| 03 | [Tipos e variáveis](03-tipos/) | tamanhos fixos, `char` é número, lixo |
| 04 | [Operadores e armadilhas](04-operadores/) | divisão inteira, `=` vs `==`, 0 é falso |
| 05 | [`if` e `while`](05-if-while/) | viver sem `for` |
| 06 | [Funções e escopo](06-funcoes/) | stack, passagem por valor |
| 07 | [Arrays e strings](07-arrays-strings/) | `'\0'`, literal vs array |
| 08 | [Ponteiros](08-ponteiros/) | `&`, `*`, referência, aritmética |
| 09 | [`malloc` e `free`](09-malloc/) | heap, leaks, `valgrind` |
| 10 | [Recursão](10-recursao/) | a pilha de chamadas |
| 11 | [Terminal e shell](11-shell/) | comandos, `chmod`, `grep`, pipes, `man` |
| 12 | [Git](12-git/) | clone, add, commit, push, `ex00/` |
| 13 | [Erros](13-erros/) | ler mensagens do `cc`, segfault |

## A pasta `util/`

A partir da aula 02, os exemplos usam funções de apoio (`ft_putchar`, `ft_putstr`, `ft_putendl`, `ft_putnbr`, `ft_putptr`) de [`util/ft_util.c`](util/ft_util.c), para não repetir código. Por isso o comando de compilação inclui esse arquivo:

```bash
cd 01-exemplos/03-tipos
cc -Wall -Wextra -Werror tamanhos.c ../util/ft_util.c && ./a.out
```

Todos os exemplos seguem a Norma (passam na `norminette`), exceto os de [`13-erros/quebrados/`](13-erros/quebrados/), que são errados de propósito.
