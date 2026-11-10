# Resposta — shell00/ex02: conta_erros

## Solução

```sh
#!/bin/sh
grep -c "ERRO"
```

Arquivo: [`conta_erros.sh`](conta_erros.sh)

## Raciocínio

1. Sem nome de arquivo, `grep` lê da **entrada padrão**. Então `cat log.txt | sh conta_erros.sh` entrega o texto ao `grep`.
2. `-c` (count) imprime **quantas linhas** casaram, em vez das linhas.
3. `grep` diferencia maiúsculas de minúsculas por padrão: `erro` não conta.

## Erros comuns

- `grep ERRO | wc -l`: também funciona, mas é um comando a mais (e `wc` não estava na lista de permitidos).
- `grep -i`: contaria `erro` minúsculo, o que o enunciado proíbe.
- Pensar que `-c` conta **ocorrências**: ele conta **linhas**. Uma linha com `ERRO ERRO` conta 1.

## Casos extremos

- Entrada vazia ou sem `ERRO`: `grep -c` imprime `0` (e sai com código `1`, que aqui não importa).

## Como testar

```bash
./run.sh conta_erros
printf "ERRO a\nINFO b\nERRO c\n" | sh minha-versao/shell00/ex02/conta_erros.sh
```
