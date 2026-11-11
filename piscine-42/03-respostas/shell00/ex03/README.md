# Resposta — shell00/ex03: lista_c

## Solução

```sh
#!/bin/sh
ls -1 | grep '\.c$' | sed 's/\.c$//'
```

Arquivo: [`lista_c.sh`](lista_c.sh)

## Raciocínio

1. `ls -1` lista a pasta atual, **um nome por linha** e já em ordem alfabética. Sem `-R`, não entra em subpastas.
2. `grep '\.c$'`: só linhas que terminam (`$`) em `.c`. O `\.` é um ponto literal; sem a barra, `.` casa com qualquer caractere.
3. `sed 's/\.c$//'`: substitui o `.c` do fim por nada.

As aspas simples impedem o shell de mexer no `\` e no `$` antes de o `grep` e o `sed` verem o texto.

## Erros comuns

- `grep .c`: casa `velho.c.bak`, `notas.txt`... qualquer coisa que tenha "um caractere seguido de c".
- `grep '\.c'` sem `$`: casa `velho.c.bak`.
- `ls *.c`: se não houver nenhum `.c`, o shell passa o texto `*.c` literalmente e o `ls` dá erro. E uma **pasta** chamada `algo.c` teria o conteúdo listado.
- `find . -name '*.c'`: entra em subpastas (precisaria de `-maxdepth 1`) e devolve `./main.c`, sem ordem garantida.

## Casos extremos

- Pasta sem arquivos `.c`: não imprime nada.
- A ordem do `ls` depende do idioma do sistema (`LC_ALL`). O teste fixa `LC_ALL=C` para ser previsível.

## Como testar

```bash
./run.sh lista_c
```
