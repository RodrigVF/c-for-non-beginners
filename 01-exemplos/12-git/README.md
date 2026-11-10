# Aula 12 — Git básico no fluxo da 42

⏱️ ~7 minutos

## Por que git na Piscine

Na 42, a entrega é feita por **git**: cada projeto tem um repositório, e o que conta para a correção é o que está **no repositório, enviado com `push`**. Arquivo só no seu computador não existe para a correção.

> Os detalhes de como os repositórios são criados e onde você pega a URL (pela intranet da 42) podem variar. Confirme com a 42SP.

## O ciclo em 4 comandos

```
  sua pasta           área de preparo          histórico local         servidor
(working dir) ──add──> (staging) ──commit──> (repositório .git) ──push──> (remoto)
```

```bash
git clone <url-do-repositorio> c00     # 1. baixa o repositório (uma vez)
cd c00
mkdir ex00
# ... escreve ex00/ft_putchar.c ...
git add ex00/ft_putchar.c              # 2. escolhe o que vai no commit
git commit -m "ex00: ft_putchar"       # 3. grava uma "foto" local
git push                               # 4. envia para o servidor
```

> 💡 Analogia: `add` é colocar coisas na caixa, `commit` é fechar e etiquetar a caixa, `push` é mandar a caixa pelo correio. Sem `push`, a caixa está fechada na sua casa.

Comandos para se localizar:

```bash
git status          # o que mudou, o que está no staging
git log --oneline   # histórico de commits
git diff            # o que mudou e ainda não foi para o staging
```

Rode `git status` **antes de cada commit e depois de cada push**. É o comando mais útil.

## Estrutura de entrega

Os subjects pedem uma pasta por exercício, com nomes exatos:

```
c00/                        ← raiz do repositório
├── ex00/
│   └── ft_putchar.c
├── ex01/
│   └── ft_print_alphabet.c
└── ex02/
    └── ft_print_numbers.c
```

Cuidados que reprovam por bobeira:

- **Nome exato** da pasta e do arquivo (`ex00`, não `Ex00` nem `ex0`; `ft_putchar.c`, não `putchar.c`).
- **Só os arquivos pedidos.** Nada de `a.out`, `main.c`, `.vscode/`, `teste.txt`. Um `.gitignore` não resolve tudo; prefira nunca dar `git add` neles. Evite `git add .` sem olhar o `git status`.
- **Sem `main`** nos arquivos de função (aula 02).
- **Norma** em tudo que é entregue: passe a `norminette` antes do push.
- Em geral, um erro em um exercício pode fazer a correção automática parar ali e ignorar os seguintes. Por isso, entregue em ordem e confira cada um. (As regras exatas de correção: confirme com a 42SP.)

## Erros comuns de git

| Situação | O que fazer |
|---|---|
| `git push` pede para configurar nome/email | `git config --global user.name "seu_login"` e `git config --global user.email "seu_email"` |
| Fiz `add` de um arquivo errado | `git restore --staged arquivo` (tira do staging) |
| Comitei um arquivo que não devia | `git rm --cached arquivo`, depois `commit` e `push` |
| `push` rejeitado (`rejected`, `fetch first`) | alguém (ou você em outra máquina) enviou antes: `git pull` e depois `git push` |

## Fluxo recomendado para cada exercício

```bash
# 1. escreve ex03/ft_is_negative.c
# 2. testa com um main.c FORA do repositório
cc -Wall -Wextra -Werror ex03/ft_is_negative.c ~/testes/main.c && ./a.out
# 3. confere a Norma
norminette ex03/
# 4. entrega
git add ex03/ft_is_negative.c
git commit -m "ex03"
git push
git status
```

## Treine agora

Crie um repositório local para simular:

```bash
mkdir -p ~/simulado/remoto && cd ~/simulado/remoto && git init --bare
cd ~/simulado && git clone remoto c00 && cd c00
mkdir ex00 && touch ex00/ft_putchar.c
git add ex00/ft_putchar.c && git commit -m "ex00" && git push
git log --oneline
```

`git init --bare` cria um repositório "servidor" na sua máquina, só para treinar o ciclo completo.

## É normal estranhar

Ter três "lugares" (pasta, staging, repositório) e um quarto (servidor) parece burocracia. A vantagem é que você escolhe exatamente o que entra em cada entrega, que é o que a 42 avalia.

## Perguntas de fixação

1. Um arquivo commitado mas sem `push` conta para a correção?
2. Para que serve o `git add`?
3. Por que não dar `git add .` sem pensar?
4. Qual comando mostra o que vai entrar no próximo commit?
5. Onde fica o `main.c` de teste?

<details>
<summary>Respostas</summary>

1. Não. Só o que está no repositório remoto conta.
2. Escolher quais mudanças entram no próximo commit (colocar no staging).
3. Porque ele adiciona tudo, inclusive `a.out`, `main.c` e outros arquivos que não podem ser entregues.
4. `git status` (e `git diff --staged` para ver o conteúdo).
5. Fora do repositório de entrega (ou, no mínimo, nunca adicionado ao git).

</details>
