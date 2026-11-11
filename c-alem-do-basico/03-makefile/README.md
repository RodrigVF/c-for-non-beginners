# 03 — `Makefile`

⏱️ ~8 minutos · Arquivos: [`Makefile`](exemplo/Makefile), [`ft.h`](exemplo/ft.h), [`ft_soma.c`](exemplo/ft_soma.c), [`main.c`](exemplo/main.c)

## A ideia central

Com 3 arquivos, digitar o `cc` na mão é tranquilo. Com 30, não. E recompilar os 30 porque você mudou 1 desperdiça tempo.

O `make` resolve as duas coisas. Ele lê um arquivo chamado `Makefile` com **receitas**: o que construir, a partir de quê, e com qual comando. E só refaz o que ficou desatualizado.

> 💡 Analogia: uma receita de bolo que sabe quais ingredientes você trocou. Trocou só o recheio? Ele refaz o recheio e monta de novo, sem assar a massa outra vez.

## Compilar em duas etapas: `.c` → `.o` → programa

Lembra das etapas da [aula 02 da Piscine](../../piscine-42/01-exemplos/02-compilacao/)? O `make` usa isso:

```
main.c ──cc -c──> main.o ──┐
                           ├──cc──> calculadora
ft_soma.c ─cc -c─> ft_soma.o ┘
```

Cada `.c` vira um `.o` (código de máquina com "buracos"). No fim, o linker junta os `.o`. Se só `ft_soma.c` mudou, só `ft_soma.o` precisa ser refeito.

## O Makefile do exemplo

```make
NAME	= calculadora
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c ft_soma.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c ft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

Lendo por partes:

- **Variáveis** (`NAME = ...`) e uso com `$(NAME)`. `$(SRCS:.c=.o)` troca `.c` por `.o` em cada nome: `main.o ft_soma.o`.
- **Regra** = `alvo: dependências`, e embaixo o comando. Ex.: `calculadora` depende dos `.o` e é feita juntando-os.
- `%.o: %.c ft.h` é uma regra genérica: "qualquer `.o` sai do `.c` de mesmo nome". Ter `ft.h` na lista faz tudo recompilar se o header mudar.
- `$<` é a primeira dependência (o `.c`) e `$@` é o alvo (o `.o`).
- `.PHONY` avisa que `clean`, `re` etc. são nomes de ações, não de arquivos.

> ⚠️ A linha do comando começa com **tab**, nunca com espaços. Com espaços, o erro é `missing separator`. É o erro de `Makefile` mais comum.

## As regras de costume na 42

| Regra | Faz |
|---|---|
| `all` (ou só `make`) | compila o programa |
| `clean` | apaga os `.o` |
| `fclean` | `clean` + apaga o programa |
| `re` | `fclean` + `all`: recompila do zero |

Projetos da 42 costumam exigir essas regras e proibir que o `make` recompile sem necessidade (o chamado *relink*). Os detalhes vêm no subject de cada projeto: confirme lá.

## Vendo funcionar

```bash
cd exemplo
make
```

```
cc -Wall -Wextra -Werror -c main.c -o main.o
cc -Wall -Wextra -Werror -c ft_soma.c -o ft_soma.o
cc -Wall -Wextra -Werror main.o ft_soma.o -o calculadora
```

Rode de novo, sem mudar nada:

```
make: Nothing to be done for 'all'.
```

Agora "mexa" em um arquivo só (o `touch` atualiza a data dele) e rode de novo:

```bash
touch ft_soma.c
make
./calculadora
```

```
cc -Wall -Wextra -Werror -c ft_soma.c -o ft_soma.o
cc -Wall -Wextra -Werror main.o ft_soma.o -o calculadora
42
```

O `main.c` **não** foi recompilado. O `make` compara as datas: se o alvo é mais novo que todas as dependências, ele está em dia.

Para limpar:

```bash
make clean    # some main.o e ft_soma.o
make fclean   # some também a calculadora
```

## É normal estranhar

A sintaxe do `Makefile` é antiga e cheia de símbolos (`$@`, `$<`, `%`). Não decore: copie a estrutura deste exemplo e mude só `NAME` e `SRCS`. Com o tempo, as partes fazem sentido.

## Mini-exercício

Adicione ao exemplo um arquivo `ft_sub.c` com `int	ft_sub(int a, int b)` (subtração). O que precisa mudar no `Makefile`? E no `ft.h`? Faça o `main.c` imprimir `ft_sub(ft_soma(2, 40), 2)`.

## Perguntas de fixação

1. Por que compilar cada `.c` num `.o` separado?
2. O que `make` faz se nenhum arquivo mudou?
3. Qual a diferença entre `clean` e `fclean`?
4. Qual o erro mais comum ao escrever um `Makefile` à mão?
5. Por que o `ft.h` aparece nas dependências da regra `%.o`?

<details>
<summary>Respostas</summary>

1. Para recompilar só o que mudou: os outros `.o` são reaproveitados.
2. Nada: mostra `Nothing to be done for 'all'`.
3. `clean` apaga os `.o`; `fclean` apaga os `.o` e o programa final.
4. Usar espaços em vez de tab antes do comando (`missing separator`).
5. Para que uma mudança no header (que é colado em todos os `.c`) faça tudo recompilar.

Mini-exercício: no `Makefile`, só a lista de fontes muda:

```make
SRCS	= main.c ft_soma.c ft_sub.c
```

No `ft.h`, um protótipo novo:

```c
int		ft_sub(int a, int b);
```

O arquivo novo:

```c
#include "ft.h"

int	ft_sub(int a, int b)
{
	return (a - b);
}
```

E no `main.c`: `ft_putnbr(ft_sub(ft_soma(2, 40), 2));`. Rode `make` e depois `./calculadora`: a saída é `40`. O `OBJS` não muda, porque é calculado a partir do `SRCS`.

</details>
