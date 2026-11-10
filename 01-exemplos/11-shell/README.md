# Aula 11 — Terminal e shell

⏱️ ~10 minutos · Arquivo: [`treino.sh`](treino.sh) (cria uma pasta para treinar)

## Por que isso importa na Piscine

Na Piscine você trabalha **o tempo todo no terminal**: navega, cria pastas `ex00/`, compila, usa git. E há projetos inteiros de shell. Quanto mais rápido no terminal, mais tempo sobra para o C.

Prepare o terreno:

```bash
sh treino.sh
cd sandbox
```

## Navegar

| Comando | Faz | Exemplo |
|---|---|---|
| `pwd` | mostra onde você está | `pwd` |
| `ls` | lista arquivos | `ls -la` (`-l` detalhes, `-a` inclui ocultos) |
| `cd` | muda de pasta | `cd projeto/src`, `cd ..` (sobe), `cd ~` (home), `cd -` (volta à anterior) |

Caminhos: `.` é a pasta atual, `..` é a de cima, `~` é a sua home, `/` é a raiz. Use **Tab** para completar nomes: digite `cd pro` e aperte Tab.

## Criar, copiar, mover, apagar

| Comando | Faz |
|---|---|
| `mkdir ex00` | cria pasta (`mkdir -p a/b/c` cria o caminho todo) |
| `touch arquivo.c` | cria arquivo vazio (ou atualiza a data, se existir) |
| `cp origem destino` | copia (`cp -r` para pastas) |
| `mv origem destino` | move **ou renomeia** |
| `rm arquivo` | apaga (`rm -r pasta` para pastas) |
| `cat arquivo` | mostra o conteúdo |

> ⚠️ `rm` **não tem lixeira**. Apagou, perdeu. Cuidado redobrado com `rm -rf` e com `*`.

## Permissões e `chmod`

```bash
ls -l script.sh
```
```
-rw-r--r-- 1 voce voce 35 nov 10 10:00 script.sh
```

Leia os 10 primeiros caracteres assim:

```
 -    rw-     r--     r--
 │    │       │       └── outros (others)
 │    │       └────────── grupo (group)
 │    └────────────────── dono (user)
 └─────────────────────── tipo: - arquivo, d pasta, l link
```

`r` = ler, `w` = escrever, `x` = executar (para pastas, `x` = poder entrar).

### Notação numérica

Cada permissão tem um peso. Some os pesos de cada grupo:

```
r = 4    w = 2    x = 1

rwx = 4+2+1 = 7
rw- = 4+2+0 = 6
r-x = 4+0+1 = 5
r-- = 4+0+0 = 4
--- = 0
```

Então `chmod 754 arquivo` é:

```
  7     5     4
 rwx   r-x   r--
 dono  grupo outros
```

Os mais comuns:

| Número | Significado | Uso típico |
|---|---|---|
| `755` | `rwxr-xr-x` | scripts e pastas |
| `644` | `rw-r--r--` | arquivos comuns |
| `600` | `rw-------` | arquivos privados |
| `700` | `rwx------` | pasta privada |

Treine:

```bash
./script.sh           # Permission denied: não tem x
chmod 755 script.sh
./script.sh           # agora roda
```

Também existe a forma simbólica: `chmod +x script.sh`, `chmod g-w arquivo`, `chmod u=rw,go=r arquivo`.

> 💡 No WSL, arquivos dentro de `/mnt/c/...` (o disco do Windows) não guardam permissões direito. **Trabalhe dentro da home do Linux** (`~`), não em `/mnt/c`.

## `grep`: procurar texto

```bash
grep ERRO log.txt           # linhas que contêm ERRO
grep -c ERRO log.txt        # quantas linhas (count)
grep -v ERRO log.txt        # linhas que NÃO contêm (invert)
grep -i erro log.txt        # ignora maiúsculas/minúsculas
grep -n ERRO log.txt        # mostra o número da linha
grep -r ft_ projeto/        # procura recursivamente em pastas
grep '^INFO' log.txt        # ^ = começo da linha
grep 'timeout$' log.txt     # $ = fim da linha
```

## Redirecionamentos

Lembra dos canais da aula 01? `0` = entrada, `1` = saída, `2` = erros.

| Símbolo | Faz |
|---|---|
| `>` | manda a saída para um arquivo (**apaga** o conteúdo antigo) |
| `>>` | **acrescenta** no fim do arquivo |
| `<` | lê a entrada de um arquivo |
| `2>` | manda os erros para um arquivo |
| `2>&1` | manda os erros para onde está indo a saída |

```bash
ls > lista.txt
echo "nova linha" >> lista.txt
cc arquivo_que_nao_existe.c 2> erros.txt
```

## Pipes: `|`

O pipe liga a **saída** de um comando à **entrada** do próximo. É a ideia central do Unix: comandos pequenos, combinados.

```bash
cat nomes.txt | sort                  # ordena
cat nomes.txt | sort | uniq           # ordena e remove repetidos
grep ERRO log.txt | wc -l             # conta linhas com ERRO
ls -l | grep '\.c$'                   # só arquivos terminados em .c
cut -d ' ' -f 1 log.txt | sort | uniq -c   # conta por tipo
```

```
cat nomes.txt ──> sort ──> uniq ──> terminal
           (saída vira entrada)
```

Outros comandos que combinam bem: `wc -l` (conta linhas), `sort`, `uniq`, `head -n 3`, `tail -n 3`, `cut -d ':' -f 1` (recorta colunas), `tr`, `sed`.

## `man`: o manual

Sem internet na sua frente? `man` resolve. Ele é dividido em **seções**:

| Seção | Conteúdo | Exemplo |
|---|---|---|
| 1 | comandos do shell | `man 1 ls`, `man chmod` |
| 2 | chamadas de sistema (*syscalls*) | `man 2 write` |
| 3 | funções da biblioteca C | `man 3 malloc`, `man 3 strlen` |

Por que o número importa? Porque há nomes repetidos: `man printf` mostra o **comando** `printf` (seção 1); `man 3 printf` mostra a **função** C.

Dentro do `man`: `/palavra` busca, `n` vai para a próxima ocorrência, `q` sai.

> No Ubuntu/WSL, as seções 2 e 3 vêm no pacote `manpages-dev`. Se `man 2 write` disser que não existe, instale com `sudo apt install manpages-dev`.

## Scripts de shell

Um script é um arquivo de texto com comandos:

```sh
#!/bin/sh
echo "Ola"
ls -l | wc -l
```

- A primeira linha (*shebang*) diz qual programa executa o arquivo.
- Para rodar com `./script.sh`, ele precisa de permissão `x`. Sem ela, rode com `sh script.sh`.
- `$1`, `$2`... são os argumentos. `$#` é a quantidade. `$?` é o código de saída do último comando.

## É normal estranhar

Parece que o terminal é mais lento que clicar. Na primeira semana é. Depois de alguns dias usando Tab, setas para cima (histórico) e `Ctrl+R` (busca no histórico), ele fica muito mais rápido.

## Mini-exercício (na sandbox)

1. Crie `ex00/` e `ex01/` e mova `script.sh` para `ex00/`.
2. Deixe `ex00/script.sh` com permissão `rwxr-x---` (número?).
3. Com um único pipeline, mostre os nomes de `nomes.txt` sem repetição e ordenados.
4. Conte quantas linhas de `log.txt` **não** são `INFO`.
5. Salve a lista de arquivos `.c` de `projeto/src` num arquivo `fontes.txt`.

## Perguntas de fixação

1. Qual o número de `rw-r-----`?
2. Diferença entre `>` e `>>`?
3. O que `ls | wc -l` mostra?
4. Que seção do `man` documenta `malloc`? E `write`?
5. Por que `./script.sh` pode dar "Permission denied"?

<details>
<summary>Respostas</summary>

1. `640`.
2. `>` substitui o conteúdo do arquivo; `>>` acrescenta no fim.
3. O número de linhas da saída do `ls`, ou seja, quantos itens há na pasta.
4. `malloc`: seção 3 (biblioteca C). `write`: seção 2 (syscall).
5. Porque o arquivo não tem permissão de execução (`x`). Resolve com `chmod +x script.sh` (ou `chmod 755`).

Mini-exercício:
```bash
mkdir ex00 ex01
mv script.sh ex00/
chmod 750 ex00/script.sh
sort nomes.txt | uniq          # ou: sort -u nomes.txt
grep -v INFO log.txt | wc -l   # ou: grep -vc INFO log.txt
ls projeto/src | grep '\.c$' > fontes.txt
```

</details>
