# Shell00 — Permissões, scripts e pipes

> Recriação no estilo da Piscine (não é o subject oficial).
> Antes: leia a [aula 11](../../01-exemplos/11-shell/).

Regras gerais deste módulo:
- Cada script começa com `#!/bin/sh`.
- O script lê da entrada padrão quando o enunciado diz isso. Não peça nomes de arquivo como argumento, a menos que o enunciado peça.
- Teste com `./run.sh <nome>` (por exemplo, `./run.sh ola`).

---

## Exercise 00: ola 🟢

```
Exercise 00: ola
Turn-in directory : ex00/
Files to turn in  : ola.sh
Allowed functions : echo
```

Crie um script `ola.sh` que imprima exatamente:

```
Ola, Piscine!
```

seguido de uma quebra de linha. O arquivo deve ter as permissões `rwxr-xr-x`.

```
$> ./ola.sh
Ola, Piscine!
$> ls -l ola.sh
-rwxr-xr-x 1 seu_login seu_login 32 nov 10 10:00 ola.sh
```

<details>
<summary>Dica</summary>

Qual o número de `rwxr-xr-x`? Some 4 (r), 2 (w) e 1 (x) em cada grupo de três.

</details>

---

## Exercise 01: permissoes 🟢

```
Exercise 01: permissoes
Turn-in directory : ex01/
Files to turn in  : permissoes.sh
Allowed functions : touch, mkdir, chmod
```

Crie um script que, ao ser executado com `sh permissoes.sh` numa pasta vazia, crie nela:

| Nome | Tipo | Permissões |
|---|---|---|
| `publico.txt` | arquivo | `rw-r--r--` |
| `privado.txt` | arquivo | `rw-------` |
| `script_vazio.sh` | arquivo | `rwxr-xr-x` |
| `pasta` | diretório | `rwxr-x---` |

```
$> sh permissoes.sh
$> ls -l
drwxr-x--- 2 seu_login seu_login 4096 nov 10 10:00 pasta
-rw------- 1 seu_login seu_login    0 nov 10 10:00 privado.txt
-rw-r--r-- 1 seu_login seu_login    0 nov 10 10:00 publico.txt
-rwxr-xr-x 1 seu_login seu_login    0 nov 10 10:00 script_vazio.sh
```

<details>
<summary>Dica</summary>

`touch` aceita vários nomes de uma vez. Lembre que as permissões iniciais dependem do `umask` do sistema; por isso use `chmod` em **todos**, inclusive nos que parecem já estar certos.

</details>

---

## Exercise 02: conta_erros 🟡

```
Exercise 02: conta_erros
Turn-in directory : ex02/
Files to turn in  : conta_erros.sh
Allowed functions : grep
```

Crie um script que leia um texto da **entrada padrão** e imprima quantas linhas contêm a palavra `ERRO` (exatamente em maiúsculas, em qualquer posição da linha). Se nenhuma linha contiver, imprima `0`.

```
$> cat log.txt
INFO inicio
ERRO disco cheio
erro minusculo nao conta
INFO ERRO no meio conta
$> cat log.txt | sh conta_erros.sh
2
$> echo "tudo certo" | sh conta_erros.sh
0
```

<details>
<summary>Dica</summary>

`grep` lê da entrada padrão quando você não passa nenhum arquivo. Veja as opções de contagem em `man grep`.

</details>

---

## Exercise 03: lista_c 🟡

```
Exercise 03: lista_c
Turn-in directory : ex03/
Files to turn in  : lista_c.sh
Allowed functions : ls, grep, sed, cut, sort, find
```

Crie um script que liste, um por linha e em ordem alfabética, os nomes dos arquivos **da pasta atual** (sem entrar em subpastas) que terminam em `.c`, **sem** a extensão `.c`.

```
$> ls
ft.h  ft_putchar.c  ft_strlen.c  main.c  notas.txt  sub  velho.c.bak
$> sh lista_c.sh
ft_putchar
ft_strlen
main
```

`velho.c.bak` **não** termina em `.c`. O conteúdo de `sub/` não deve aparecer.

<details>
<summary>Dica</summary>

Em `grep`, o `.` significa "qualquer caractere" e o `$` significa "fim da linha". Para um ponto literal, use `\.`. Para remover um trecho do fim, procure o comando `s/.../.../` do `sed`.

</details>

---

## Exercise 04: usuarios 🔴

```
Exercise 04: usuarios
Turn-in directory : ex04/
Files to turn in  : usuarios.sh
Allowed functions : grep, cut, sort
```

O script recebe pela entrada padrão linhas no formato do arquivo `/etc/passwd`:

```
login:x:uid:gid:info:home:shell
```

Imprima, um por linha e em ordem alfabética, o **login** de cada usuário cujo shell é **exatamente** `/bin/bash`.

```
$> cat contas.txt
root:x:0:0:root:/root:/bin/bash
zelia:x:1002:1002::/home/zelia:/bin/bash
ana:x:1001:1001::/home/ana:/bin/bash
bruno:x:1003:1003::/home/bruno:/bin/zsh
carla:x:1004:1004::/home/carla:/bin/bash/falso
$> cat contas.txt | sh usuarios.sh
ana
root
zelia
```

`carla` não aparece: o shell dela não é exatamente `/bin/bash`.

<details>
<summary>Dica</summary>

Três comandos ligados por pipes: um filtra as linhas (atenção ao fim da linha), outro recorta a primeira coluna (o separador é `:`), o último ordena.

</details>
