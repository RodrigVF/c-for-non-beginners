# Preparação Piscine 42 — 7 dias de C e shell

> ⚠️ **Material não oficial**, sem vínculo com a 42 ou a 42 São Paulo. É gratuito e [open-source](../README.md#licença).

Repositório de estudo para quem **já programa** em outra linguagem e **nunca escreveu C**. Não explica lógica de programação: foca no que é específico de C (sintaxe, por que ela é assim, e como a memória funciona) e no shell.

## A Piscine, em poucas linhas

A Piscine é a imersão de seleção da 42: cerca de 4 semanas com projetos diários em C e shell, correção automática (a **Moulinette**), correção por pares (*peer evaluation*), exames e *rushes* em grupo. Não há professores: o aprendizado acontece entre colegas.

Datas, duração exata, regras de exame, o que é permitido levar e outros detalhes **variam por campus e edição. Confirme com a 42SP.**

> ⚠️ Os exercícios deste repositório são **recriações no estilo da Piscine**, escritas para treino. Não são os subjects oficiais.

## Estrutura

```
piscine-42/
├── README.md            ← você está aqui (plano de 7 dias no fim)
├── run.sh               ← compila e testa um exercício pelo nome
├── 01-exemplos/         ← 14 aulas curtas, cada uma com código que roda
├── 02-exercicios/       ← enunciados no formato subject (sem resposta)
├── 03-respostas/        ← soluções na Norma + explicação detalhada
├── testes/              ← main.c e saída esperada de cada exercício
├── minha-versao/        ← onde VOCÊ escreve as suas soluções
└── ferramentas/         ← gerador do cabeçalho da 42
```

## Preparando o ambiente (Ubuntu no WSL)

```bash
sudo apt update
sudo apt install build-essential valgrind manpages-dev git
```

- `build-essential` traz o `cc` e o `make`.
- `valgrind` encontra leaks (aula 09).
- `manpages-dev` traz as seções 2 e 3 do `man` (`man 2 write`, `man 3 malloc`).

**Norminette** (o verificador da Norma, feito pela 42 e distribuído como pacote Python):

```bash
sudo apt install pipx
pipx install norminette
pipx ensurepath
```

Feche e abra o terminal, e confira com `norminette --version`.

**VS Code:** instale a extensão **WSL** no Windows, entre na pasta pelo terminal do Ubuntu e rode `code .`. A pasta [`.vscode/`](../.vscode/settings.json), na raiz do repositório, já configura tabs de largura 4 (sem espaços) e uma régua na coluna 80.

> 💡 Guarde seus arquivos **dentro do Linux** (`~/...`), não em `/mnt/c/...`. No disco do Windows, as permissões de arquivo não funcionam direito, e o shell00 depende delas.

## Como usar

Todos os comandos abaixo são rodados **de dentro da pasta `piscine-42/`** (`cd piscine-42`).

1. Leia uma aula em [`01-exemplos/`](01-exemplos/), compile e rode os exemplos.
2. Faça os exercícios correspondentes de [`02-exercicios/`](02-exercicios/), escrevendo em `minha-versao/` (por exemplo, `minha-versao/c00/ex00/ft_putchar.c`).
3. Coloque o cabeçalho: `python3 ferramentas/cabecalho.py minha-versao/c00/ex00/ft_putchar.c`
4. Teste:

```bash
./run.sh ft_putchar
```

```
== ft_putchar
  arquivo: minha-versao/c00/ex00/ft_putchar.c
  OK    compilacao com -Wall -Wextra -Werror
  OK    saida igual a esperada
  OK    Norma (norminette)
```

5. Depois de passar (ou de travar por uns 20 minutos), leia a resposta em [`03-respostas/`](03-respostas/). Mesmo acertando, leia: as seções de "erros comuns" e "casos extremos" valem muito.

Outros comandos:

```bash
./run.sh --lista                  # exercícios disponíveis
./run.sh ft_putnbr --resposta     # testa a resposta oficial deste repositório
./testes/rodar_todos.sh           # testa tudo o que você já fez
```

## A Norma, resumida (como este repositório a aplica)

Todo o código daqui segue estas regras e passa na `norminette`:

| Regra | Exemplo |
|---|---|
| Indentação com **tab** (largura 4); tab entre tipo e nome | `int	main(void)` |
| Máximo de 25 linhas por função, 80 colunas por linha | |
| Máximo de 4 parâmetros por função e 5 funções por arquivo | |
| Variáveis no início da função, uma por linha, sem inicializar na declaração, seguidas de uma linha em branco | `int	i;` ↵ ↵ `i = 0;` |
| Proibidos: `for`, `do...while`, `switch`, `goto`, ternário `? :` | só `while` |
| Sem comentários **dentro** das funções | |
| `return` com parênteses | `return (0);` |
| Prefixo `ft_` e arquivo com o nome da função | `ft_putnbr.c` |
| Cabeçalho da 42 no topo de cada arquivo | [`ferramentas/`](ferramentas/) |
| Compilar sempre com `cc -Wall -Wextra -Werror` | |
| Sem `printf` nas funções de exercício: use `write` | `printf` só nos `main.c` de teste |

A Norma completa tem mais regras. A `norminette` é a referência: se ela aceitou, está na Norma.

## Plano de 7 dias

Ritmo pensado para **3 a 5 horas por dia**. Se um dia atrasar, não pule: as aulas dependem umas das outras. Os dias 6 e 7 têm folga para recuperar.

### Dia 1 — O programa, a compilação e o terminal
- Aulas: [01 Anatomia](01-exemplos/01-anatomia/), [02 Compilação](01-exemplos/02-compilacao/), [03 Tipos](01-exemplos/03-tipos/), [11 Shell](01-exemplos/11-shell/)
- Exercícios: shell00 ex00, ex01, ex02 · c00 ex00 (`ft_putchar`), ex01, ex02
- Meta: compilar sem pensar nas flags e navegar no terminal sem mouse.

### Dia 2 — Controle de fluxo, funções e git
- Aulas: [04 Operadores](01-exemplos/04-operadores/), [05 if/while](01-exemplos/05-if-while/), [06 Funções](01-exemplos/06-funcoes/), [12 Git](01-exemplos/12-git/)
- Exercícios: c00 ex03 (`ft_is_negative`), ex04 (`ft_putstr`), ex05 (`ft_strlen`) · shell00 ex03, ex04
- Extra: monte o simulado de git da aula 12 e entregue o c00 nele, com `ex00/`, `ex01/`...

### Dia 3 — Strings e erros
- Aulas: [07 Arrays e strings](01-exemplos/07-arrays-strings/), [13 Erros](01-exemplos/13-erros/), [10 Recursão](01-exemplos/10-recursao/) (curta; o `ft_putnbr` precisa dela)
- Exercícios: c00 ex06 (`ft_putnbr`, com INT_MIN) · c02 ex00 (`ft_strcpy`), ex03 (`ft_str_is_numeric`)
- Meta: entender por que toda função de string é "anda até o `'\0'`".

### Dia 4 — Ponteiros (o dia mais importante)
- Aula: [08 Ponteiros](01-exemplos/08-ponteiros/) (leia duas vezes, desenhe no papel)
- Exercícios: c01 inteiro (`ft_swap`, `ft_div_mod`, `ft_ultimate_div_mod`) · c02 ex01 (`ft_strcmp`), ex02 (`ft_strrev`), ex04 (`ft_strcat`)

### Dia 5 — Memória dinâmica + primeiro exame
- Aula: [09 malloc/free/valgrind](01-exemplos/09-malloc/)
- Exercícios: c03 inteiro (`ft_strdup`, `ft_range`, `ft_strjoin`)
- Simulação: [Exame 01](02-exercicios/exames/exame-01.md) (30 min, sem consulta)

### Dia 6 — Recursão, programas + segundo exame
- Releia a aula [10 Recursão](01-exemplos/10-recursao/) (lida no dia 3)
- Aula: [14 argc e argv](01-exemplos/14-argc-argv/) (programas que recebem argumentos)
- Exercícios: c04 inteiro (`ft_factorial`, `ft_power`) · c05 inteiro (`ft_show_name`, `ft_show_args`, `ft_rev_args`, `ft_sort_args`)
- Simulação: [Exame 02](02-exercicios/exames/exame-02.md) (40 min)
- Refaça, do zero e sem olhar, os exercícios em que você errou até agora.

### Dia 7 — Último exame e revisão
- Simulações: [Exame 03](02-exercicios/exames/exame-03.md) (45 min) e [Exame 04](02-exercicios/exames/exame-04.md) (40 min, só programas)
- Refaça de memória, em arquivos novos: `ft_putnbr`, `ft_strcmp`, `ft_strdup`, `ft_strjoin`, `ft_atoi`.
- Responda de novo as **perguntas de fixação** de todas as aulas, sem abrir as respostas. No site, a **Revisão rápida** junta todas elas em cartões (dá para embaralhar).
- Rode `./testes/rodar_todos.sh` e deixe tudo verde.

### Se sobrar tempo
- Desafios: [c06](02-exercicios/c06-desafios/) (`ft_strncmp`, `ft_putnbr_base`, `ft_split`). São mais difíceis e juntam tudo o que você viu.
- Comece a trilha [C além do básico](../c-alem-do-basico/): headers próprios, `struct` e `Makefile`.

## Dicas para a Piscine em si

- **Leia o subject inteiro.** Nome de arquivo, pasta e protótipo errados reprovam código correto.
- **Teste com seu próprio `main.c`**, com casos extremos, antes de entregar. Nunca entregue o `main.c`.
- **Rode a `norminette`** antes de cada push.
- **Pergunte aos colegas e explique para eles.** Explicar ponteiros para alguém é a melhor forma de aprender ponteiros.
- `man` é seu amigo: `man 2 write`, `man 3 malloc`, `man ascii`.
