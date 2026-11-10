# Resposta — shell00/ex01: permissoes

## Solução

```sh
#!/bin/sh
touch publico.txt privado.txt script_vazio.sh
mkdir -p pasta
chmod 644 publico.txt
chmod 600 privado.txt
chmod 755 script_vazio.sh
chmod 750 pasta
```

Arquivo: [`permissoes.sh`](permissoes.sh)

## Raciocínio

1. `touch` cria os três arquivos de uma vez; `mkdir -p` cria a pasta (o `-p` não reclama se ela já existir).
2. Converta cada permissão:

| Alvo | Simbólico | Conta | Número |
|---|---|---|---|
| `publico.txt` | `rw-r--r--` | 6 4 4 | `644` |
| `privado.txt` | `rw-------` | 6 0 0 | `600` |
| `script_vazio.sh` | `rwxr-xr-x` | 7 5 5 | `755` |
| `pasta` | `rwxr-x---` | 7 5 0 | `750` |

3. Use `chmod` em todos. As permissões iniciais de um arquivo novo dependem do `umask` (geralmente `022`, que dá `644` para arquivos e `755` para pastas), e ele muda de máquina para máquina. Nunca confie nele.

## Erros comuns

- Confiar no padrão e não dar `chmod` em `publico.txt`: funciona na sua máquina, quebra em outra.
- Confundir a ordem: o primeiro dígito é o **dono**, depois grupo, depois outros.
- Esquecer que, em pasta, `x` é "poder entrar" (`cd`).

## Casos extremos

- Rodar duas vezes na mesma pasta: `touch` e `mkdir -p` não falham, e o `chmod` reaplica. O resultado é o mesmo.

## Como testar

```bash
./run.sh permissoes
```

O teste roda seu script numa pasta temporária vazia e confere cada permissão com `stat -c %a`.
