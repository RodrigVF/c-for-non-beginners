# C05 — Programas com argumentos

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: aula [14 (`argc` e `argv`)](../../01-exemplos/14-argc-argv/).

Regras deste módulo:
- Aqui você entrega um **programa**: o arquivo **tem `main`**, com o protótipo `int	main(int argc, char **argv)`.
- Compilação com `cc -Wall -Wextra -Werror`, Norma, só as *allowed functions* (nada de `printf`).
- Cada linha impressa termina com `\n`.
- Teste com `./run.sh <nome>`: o teste compila o seu arquivo sozinho e o executa com vários argumentos.

Teste também à mão, sempre:

```bash
cc -Wall -Wextra -Werror ft_show_args.c -o ft_show_args
./ft_show_args Ola "Piscine 42"
```

---

## Exercise 00: ft_show_name 🟢

```
Exercise 00: ft_show_name
Turn-in directory : ex00/
Files to turn in  : ft_show_name.c
Allowed functions : write
```

Escreva um programa que mostre o próprio nome (exatamente como foi chamado), seguido de `\n`. Os argumentos, se houver, são ignorados.

```
$> ./ft_show_name
./ft_show_name
$> ./ft_show_name um dois
./ft_show_name
```

<details>
<summary>Dica</summary>

O nome está em `argv[0]`. Como `argc` não é usado, o compilador vai reclamar: veja a aula 14.

</details>

---

## Exercise 01: ft_show_args 🟢

```
Exercise 01: ft_show_args
Turn-in directory : ex01/
Files to turn in  : ft_show_args.c
Allowed functions : write
```

Escreva um programa que mostre cada argumento recebido, um por linha, na ordem em que foram passados. O nome do programa **não** é mostrado. Sem argumentos, não mostra nada.

```
$> ./ft_show_args Ola "Piscine 42" ""
Ola
Piscine 42

$> ./ft_show_args
$>
```

(O argumento vazio `""` gera uma linha vazia.)

<details>
<summary>Dica</summary>

Comece o índice em `1`. Uma função auxiliar que escreve uma string e o `\n` deixa a `main` curta.

</details>

---

## Exercise 02: ft_rev_args 🟢

```
Exercise 02: ft_rev_args
Turn-in directory : ex02/
Files to turn in  : ft_rev_args.c
Allowed functions : write
```

Escreva um programa que mostre os argumentos **em ordem inversa**, um por linha. O nome do programa não é mostrado.

```
$> ./ft_rev_args 1 2 3
3
2
1
```

<details>
<summary>Dica</summary>

Comece em `argc - 1` e pare **antes** de chegar ao `0`.

</details>

---

## Exercise 03: ft_sort_args 🟡

```
Exercise 03: ft_sort_args
Turn-in directory : ex03/
Files to turn in  : ft_sort_args.c
Allowed functions : write
```

Escreva um programa que mostre os argumentos **em ordem crescente da tabela ASCII** (a mesma ordem do `strcmp`), um por linha. O nome do programa não é mostrado.

```
$> ./ft_sort_args b a C aa
C
a
aa
b
```

`C` vem antes de `a` porque, na tabela ASCII, as maiúsculas (65 a 90) vêm antes das minúsculas (97 a 122).

<details>
<summary>Dica 1</summary>

Você já tem o `ft_strcmp` (c02). Um algoritmo simples de ordenação, como o *bubble sort*, resolve: percorra a lista trocando vizinhos fora de ordem até passar uma vez inteira sem trocas.

</details>

<details>
<summary>Dica 2</summary>

Não precisa copiar strings: troque os **ponteiros** dentro do `argv`. E `argv + 1` é uma lista que já começa no primeiro argumento de verdade.

</details>
