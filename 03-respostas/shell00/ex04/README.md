# Resposta — shell00/ex04: usuarios

## Solução

```sh
#!/bin/sh
grep ':/bin/bash$' | cut -d ':' -f 1 | sort
```

Arquivo: [`usuarios.sh`](usuarios.sh)

## Raciocínio

Um pipeline de 3 etapas, cada comando fazendo uma coisa:

```
entrada ──> grep (filtra linhas) ──> cut (pega a 1ª coluna) ──> sort (ordena) ──> saída
```

1. `grep ':/bin/bash$'`: linhas que **terminam** em `:/bin/bash`. O `:` antes garante que é o campo inteiro, e o `$` exclui `/bin/bash/falso`.
2. `cut -d ':' -f 1`: separa a linha por `:` (`-d`, delimitador) e pega o campo 1 (`-f`), o login.
3. `sort`: ordem alfabética.

## Erros comuns

- `grep bash`: pega `/bin/bash/falso`, `/usr/bin/rbash` e até um usuário chamado `bashir`.
- `grep '/bin/bash'` sem `$`: pega `/bin/bash/falso`.
- Ordenar antes de recortar: funciona por acaso aqui, mas ordenaria pela linha inteira, não pelo login.

## Casos extremos

- Nenhum usuário com bash: não imprime nada.
- Linha com espaços no campo `info`: não atrapalha, porque o separador é `:`.

## Como testar

```bash
./run.sh usuarios
grep ':/bin/bash$' /etc/passwd | cut -d ':' -f 1 | sort     # no seu sistema
```
