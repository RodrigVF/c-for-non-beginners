# Aula 02 — Compilação e por que a ordem das funções importa

⏱️ ~9 minutos · Arquivos: [`prototipo.c`](prototipo.c), [`com_util.c`](com_util.c), [`../util/ft_util.h`](../util/ft_util.h), [`../util/ft_util.c`](../util/ft_util.c)

## A ideia central

O comando `cc` parece fazer uma coisa só, mas faz **três etapas**. Cada tipo de erro que você vai ver na Piscine vem de uma etapa diferente. Saber qual é qual economiza muito tempo.

```
 arquivo.c
    │
    ▼
┌───────────────────┐  resolve #include e #define
│ 1. PRÉ-PROCESSADOR│  (copia e cola texto)
└───────────────────┘
    │  arquivo.i (C "puro")
    ▼
┌───────────────────┐  verifica sintaxe e tipos,
│ 2. COMPILADOR     │  gera código de máquina
└───────────────────┘
    │  arquivo.o (objeto: código de máquina com "buracos")
    ▼
┌───────────────────┐  junta todos os .o e as bibliotecas,
│ 3. LINKER         │  preenche os "buracos"
└───────────────────┘
    │
    ▼
  a.out (executável)
```

## Etapa 1 — Pré-processador: copia e cola

Tudo que começa com `#` é para ele. `#include <unistd.h>` significa literalmente: **"cole aqui o conteúdo do arquivo unistd.h"**.

Veja com seus olhos:

```bash
cc -E prototipo.c | tail -20
```

`-E` para depois do pré-processador. Você vai ver seu código com centenas de linhas coladas antes dele.

- `<arquivo.h>` (sinais de menor e maior): procura nas pastas do sistema.
- `"arquivo.h"` (aspas): procura primeiro na pasta do seu arquivo.

## Etapa 2 — Compilador: lê de cima para baixo, uma vez

Aqui está o ponto mais importante desta aula:

> **O compilador lê o arquivo de cima para baixo, numa passada só. Ele só conhece o que já leu.**

Se `main` chama `ft_diz_oi` e `ft_diz_oi` só aparece **depois**, o compilador chega na chamada sem saber o que é aquilo. Ele não sabe o tipo de retorno nem os parâmetros, então não consegue gerar o código certo.

Duas soluções:

**A)** Definir a função antes de usar (o mais comum nos exercícios da 42).

**B)** Escrever um **protótipo**: uma "promessa" da função, só a assinatura com `;`.

```c
void	ft_diz_oi(void);      /* protótipo: "existe, confia" */

int	main(void)
{
	ft_diz_oi();              /* agora o compilador sabe o que é */
	return (0);
}

void	ft_diz_oi(void)       /* a definição de verdade */
{
	write(1, "oi!\n", 4);
}
```

É exatamente isso que tem em [`prototipo.c`](prototipo.c). Compile e rode:

```bash
cc -Wall -Wextra -Werror prototipo.c && ./a.out
```

> 💡 Analogia: o protótipo é o cardápio. O garçom (compilador) só precisa saber que o prato existe e o que vem nele para anotar o pedido. Quem prepara (a definição) pode estar em outro lugar.

Para ver só a etapa 2:

```bash
cc -Wall -Wextra -Werror -c prototipo.c
```

`-c` para antes do linker e gera `prototipo.o`.

## Arquivos `.h` (headers) = coleção de protótipos

Um **header** é só um arquivo com protótipos para ser colado via `#include`. É o que `unistd.h` faz com `write`.

Em [`../util/ft_util.h`](../util/ft_util.h):

```c
#ifndef FT_UTIL_H
# define FT_UTIL_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
...

#endif
```

O `#ifndef / #define / #endif` é a **include guard**: se o header for incluído duas vezes, a segunda vez é ignorada. Sem isso, os protótipos seriam colados duas vezes.

## Etapa 3 — Linker: liga as peças

O protótipo é uma promessa. Quem confere se a promessa foi cumprida é o **linker**: ele procura a definição real em algum `.o` ou biblioteca.

O exemplo [`com_util.c`](com_util.c) usa `ft_putstr`, que está definida em outro arquivo:

```bash
cc -Wall -Wextra -Werror com_util.c ../util/ft_util.c
./a.out
```

Se você esquecer de passar `../util/ft_util.c`, a compilação de `com_util.c` funciona (o protótipo está no header), mas o linker reclama:

```
undefined reference to `ft_putstr'
```

Tradução: "você prometeu que existia, mas não achei em lugar nenhum". Mais na aula 13.

## Por que a 42 usa isso tanto

Na Piscine, você entrega **só o arquivo da função** (`ft_putchar.c`), sem `main`. A Moulinette compila seu arquivo junto com um `main.c` dela. É exatamente o que o [`run.sh`](../../run.sh) deste repositório faz:

```bash
cc -Wall -Wextra -Werror ft_putchar.c main.c
```

Por isso: se você deixar uma `main` no seu arquivo entregue, vão existir **duas** `main` e o linker falha. Nunca entregue `main` quando o subject não pede.

## É normal estranhar

Quem vem de Python/JS nunca pensou em "ordem das funções". Lá, a função só precisa existir na hora em que é **chamada**. Em C, ela precisa ser conhecida na hora em que é **lida pelo compilador**. A diferença é que C decide tudo antes de rodar.

## Mini-exercício

1. Em `prototipo.c`, apague a linha do protótipo e compile. Leia o erro.
2. Compile `com_util.c` sem `../util/ft_util.c`. Leia o erro. Ele vem do compilador ou do linker?

## Perguntas de fixação

1. Quais são as três etapas do `cc`, na ordem?
2. O que `#include` faz, literalmente?
3. O que é um protótipo e quando ele é necessário?
4. Para que serve a include guard (`#ifndef`)?
5. Por que entregar um arquivo com `main` pode quebrar a correção automática?

<details>
<summary>Respostas</summary>

1. Pré-processador, compilador, linker.
2. Copia o conteúdo do arquivo indicado e cola no lugar da linha.
3. É a assinatura da função terminada em `;`. É necessário quando a função é usada antes da sua definição no arquivo, ou quando ela está definida em outro arquivo.
4. Evitar que o mesmo header seja colado duas vezes no mesmo arquivo (o que causaria declarações repetidas).
5. Porque a correção compila seu arquivo junto com a `main` dela. Duas `main` geram erro de linker (`multiple definition of 'main'`).

</details>
