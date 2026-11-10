# Resposta — shell00/ex00: ola

## Solução

```sh
#!/bin/sh
echo "Ola, Piscine!"
```

Arquivo: [`ola.sh`](ola.sh)

E as permissões:

```bash
chmod 755 ola.sh
```

## Raciocínio

1. `#!/bin/sh` (o *shebang*) diz ao sistema que programa deve executar o arquivo quando você roda `./ola.sh`.
2. `echo` imprime o texto e já acrescenta a quebra de linha.
3. `rwxr-xr-x` → `rwx` = 4+2+1 = **7**, `r-x` = 4+0+1 = **5**, `r-x` = **5** → `755`.

## Erros comuns

- Esquecer o `chmod`: `./ola.sh` responde `Permission denied`.
- Texto diferente (`Olá`, sem vírgula, sem `!`, espaço sobrando). Correção automática compara **byte a byte**.
- Usar `echo -n` e perder a quebra de linha.
- Escrever o arquivo no Windows (fora do WSL): as quebras de linha viram `\r\n` e o shell reclama de `/bin/sh^M`. Crie os arquivos dentro do Linux.

## Como testar

```bash
./run.sh ola
ls -l minha-versao/shell00/ex00/ola.sh
```
