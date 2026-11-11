# 01 — Seus próprios headers e vários arquivos

⏱️ ~7 minutos · Arquivos: [`ft.h`](exemplo/ft.h), [`ft_put.c`](exemplo/ft_put.c), [`main.c`](exemplo/main.c)

## A ideia central

Um programa real não cabe num arquivo só. Em C, a divisão é sempre a mesma:

- **`.c`**: o código de verdade (as **definições** das funções).
- **`.h`** (*header*): as **promessas** (os protótipos), para os outros arquivos saberem o que existe.

```
 main.c                    ft.h                     ft_put.c
┌────────────────┐       ┌──────────────────┐     ┌──────────────────┐
│ #include "ft.h"│ ────> │ void ft_putstr();│ <── │ #include "ft.h"  │
│ ft_putstr(..); │       │ void ft_putnbr();│     │ void ft_putstr() │
└────────────────┘       └──────────────────┘     │ { ...código... } │
   "existe, confia"         a promessa            └──────────────────┘
                                                     o cumprimento
```

> 💡 Você já fez isso sem perceber: `#include <unistd.h>` é o header do sistema que promete a função `write`. Agora você vai escrever o seu.

## O header

```c
#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif
```

- **Só declarações**: protótipos, `typedef`, `#define`. Nada de corpo de função.
- **Include guard** (`#ifndef / # define / #endif`): se o header for incluído duas vezes no mesmo arquivo, a segunda vez é ignorada. O nome (`FT_H`) é o nome do arquivo em maiúsculas.
- Na Norma, o `#` das linhas dentro do `#ifndef` leva um espaço depois: `# define`.

## `"aspas"` ou `<sinais>`?

```c
#include <unistd.h>   /* procura nas pastas do sistema */
#include "ft.h"       /* procura primeiro na pasta deste arquivo */
```

Seus headers usam aspas. Se o `.h` estiver em outra pasta, diga ao compilador onde procurar com `-I`:

```bash
cc -Wall -Wextra -Werror -I includes main.c ft_put.c
```

## Compilando vários arquivos

Passe **todos** os `.c` para o `cc`. Os `.h` não entram no comando: eles já são colados pelos `#include`.

```bash
cd exemplo
cc -Wall -Wextra -Werror main.c ft_put.c
./a.out
```

```
Funcoes de outro arquivo, prometidas pelo ft.h: 42
```

Se esquecer o `ft_put.c`, o compilador aceita (a promessa está no header), mas o **linker** não acha as funções:

```
undefined reference to `ft_putstr'
undefined reference to `ft_putnbr'
undefined reference to `ft_putchar'
```

É o mesmo erro da [aula 13 da Piscine](../../piscine-42/01-exemplos/13-erros/): prometeu e não entregou.

## Funções que só o arquivo vê: `static`

Uma função auxiliar que não precisa ser usada fora do arquivo pode ser `static`:

```c
static void	ft_putstr(char *str)
```

Ela não vai no header, e nenhum outro arquivo consegue chamá-la. Vantagem: dois arquivos podem ter uma `static` com o mesmo nome sem conflito. O exemplo da [aula 02](../02-struct-typedef/exemplo/ponto.c) usa isso.

## Armadilhas

| Erro | Sintoma |
|---|---|
| Definir função (com corpo) no `.h` | `multiple definition of ...` quando dois `.c` incluem o header |
| Esquecer a include guard | `redefinition of ...` quando o header é incluído duas vezes |
| Esquecer um `.c` no comando | `undefined reference to ...` |
| Protótipo diferente da definição | `conflicting types for ...` |

## É normal estranhar

Em Python ou JavaScript, um `import` traz o código junto. Em C, o `#include` traz **só a promessa**, e o código chega separado, pelo linker. São duas peças que você precisa entregar ao `cc`: o header e o `.c`.

## Mini-exercício

Separe o `ft_strlen` em dois arquivos (`ft_str.h` com o protótipo e `ft_str.c` com a função) e use-o num `main.c` que imprime o tamanho de `"Piscine"`.

## Perguntas de fixação

1. O que vai num `.h`? E o que nunca vai?
2. Para que serve a include guard?
3. Por que o `.h` não aparece no comando `cc`?
4. O que significa `undefined reference` num projeto com vários arquivos?
5. O que `static` muda numa função?

<details>
<summary>Respostas</summary>

1. Vão declarações: protótipos, `typedef`, `#define` e `#include`. Não vai o corpo de funções (definições).
2. Impedir que o conteúdo do header seja colado duas vezes no mesmo arquivo.
3. Porque o `#include` já cola o conteúdo do header dentro de cada `.c` que o usa.
4. Que alguma função foi prometida (no header), mas o `.c` com a definição não foi passado ao `cc`, ou o nome está diferente.
5. Ela fica visível só dentro do próprio arquivo, e não pode ser chamada de outros `.c`.

Mini-exercício:

```c
/* ft_str.h */
#ifndef FT_STR_H
# define FT_STR_H

int	ft_strlen(char *str);

#endif
```

```c
/* ft_str.c */
#include "ft_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
```

```c
/* main.c */
#include <unistd.h>
#include "ft_str.h"

int	main(void)
{
	char	c;

	c = ft_strlen("Piscine") + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c ft_str.c && ./a.out
```

Saída: `7`. (O truque `+ '0'` só funciona porque o resultado tem um dígito.)

</details>
