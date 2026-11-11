# 02 — `struct` e `typedef`

⏱️ ~8 minutos · Arquivos: [`ponto.h`](exemplo/ponto.h), [`ponto.c`](exemplo/ponto.c), [`main.c`](exemplo/main.c)

## A ideia central

Até agora, cada variável guardava **uma** coisa. Uma `struct` agrupa várias variáveis relacionadas num tipo novo. É o mais perto de um "objeto" que C tem: só dados, sem métodos.

```c
struct s_ponto
{
	int	x;
	int	y;
};
```

Na memória, os campos ficam lado a lado, num bloco só:

```
struct s_ponto a;     a.x = 1;  a.y = 2;

 a: ┌──────────┬──────────┐
    │  x = 1   │  y = 2   │   8 bytes (2 ints)
    └──────────┴──────────┘
```

> 💡 Analogia: um formulário. A `struct` é o modelo do formulário (quais campos existem). Cada variável é um formulário preenchido.

## `typedef`: um nome mais curto

Escrever `struct s_ponto` toda vez cansa. O `typedef` cria um apelido para o tipo:

```c
typedef struct s_ponto
{
	int	x;
	int	y;
}	t_ponto;
```

Agora dá para declarar `t_ponto	a;`. O `typedef` não cria nada na memória: só dá um nome novo a um tipo que já existe.

**Na Norma da 42:**
- O nome da `struct` começa com `s_` e o do `typedef` com `t_`.
- A `norminette` não aceita `typedef` em arquivos `.c` (erro `FORBIDDEN_TYPEDEF`). Por isso a struct e o `typedef` ficam num header, como o [`ponto.h`](exemplo/ponto.h) do exemplo.
- Repare no tab entre `}` e `t_ponto`.

## Acessando os campos: `.` e `->`

| Você tem | Use | Exemplo |
|---|---|---|
| a própria struct | `.` | `a.x = 1;` |
| um **ponteiro** para a struct | `->` | `p->x = 1;` |

`p->x` é só um atalho para `(*p).x`: "vá até o endereço em `p` e pegue o campo `x`".

## Structs são passadas por valor (cópia inteira)

Lembra da [aula 06 da Piscine](../../piscine-42/01-exemplos/06-funcoes/)? Com struct é igual: a função recebe uma **cópia** da struct inteira. Para alterar o original, passe o endereço.

```c
void	ft_move_copia(t_ponto p, int dx, int dy)   /* mexe na cópia */
void	ft_move(t_ponto *p, int dx, int dy)       /* mexe no original */
{
	p->x = p->x + dx;
	p->y = p->y + dy;
}
```

```bash
cd exemplo
cc -Wall -Wextra -Werror main.c ponto.c
./a.out
```

```
a = (1, 2)
a depois de ft_move_copia = (1, 2)
a depois de ft_move = (4, 1)
b (copia feita antes) = (1, 2)
```

Duas coisas para notar na saída:
1. `ft_move_copia` não mudou `a`: ela mexeu numa cópia.
2. `b = a;` copiou a struct **inteira**, campo por campo. Por isso `b` continua `(1, 2)` depois que `a` mudou. (Arrays não podem ser copiados com `=`; structs podem.)

> ⚠️ Copiar uma struct grande a cada chamada custa tempo. Por isso, mesmo quando a função só **lê** a struct, é comum passar um ponteiro.

## Struct com ponteiro dentro

Se a struct tem um `char *`, a cópia com `=` copia **o endereço**, não o texto:

```c
typedef struct s_aluno
{
	char	*nome;
	int		nota;
}	t_aluno;
```

```
a.nome ──┐
         ├──> "Ana\0"     ← b = a; os dois apontam para o MESMO texto
b.nome ──┘
```

Mudar o texto por um muda para o outro. Para ter uma cópia independente, é preciso copiar o texto também (com o seu `ft_strdup`, por exemplo).

## É normal estranhar

Quem vem de linguagens com classes sente falta de métodos. Em C, o padrão é: a struct guarda os dados, e funções recebem um ponteiro para ela (`ft_move(&a, ...)`). É exatamente o que um método faz por baixo dos panos.

## Mini-exercício

Crie `t_retangulo` (campos `largura` e `altura`), a função `int	ft_area(t_retangulo r)` e a função `void	ft_dobra(t_retangulo *r)`, que dobra os dois lados. Teste com 3 × 4: a área deve dar 12, e depois de dobrar, 48.

## Perguntas de fixação

1. Qual a diferença entre `struct s_ponto` e `t_ponto`?
2. Quando usar `.` e quando usar `->`?
3. Uma função recebe `t_ponto p` e altera `p.x`. O original muda?
4. Depois de `b = a;`, alterar `a.x` muda `b.x`?
5. Onde a struct com `typedef` precisa ficar para passar na `norminette`?

<details>
<summary>Respostas</summary>

1. Nenhuma, depois do `typedef`: `t_ponto` é só um apelido para `struct s_ponto`.
2. `.` quando você tem a struct; `->` quando você tem um ponteiro para ela.
3. Não. A função recebeu uma cópia.
4. Não. `b = a;` copia a struct inteira; elas são independentes (a não ser que tenham ponteiros dentro, que continuam apontando para o mesmo lugar).
5. Num header (`.h`): a `norminette` recusa `typedef` em arquivos `.c` (`FORBIDDEN_TYPEDEF`).

Mini-exercício:

```c
/* retangulo.h */
#ifndef RETANGULO_H
# define RETANGULO_H

typedef struct s_retangulo
{
	int	largura;
	int	altura;
}	t_retangulo;

int		ft_area(t_retangulo r);
void	ft_dobra(t_retangulo *r);

#endif
```

```c
/* retangulo.c */
#include "retangulo.h"

int	ft_area(t_retangulo r)
{
	return (r.largura * r.altura);
}

void	ft_dobra(t_retangulo *r)
{
	r->largura = r->largura * 2;
	r->altura = r->altura * 2;
}
```

```c
/* main.c (teste, pode usar printf) */
#include <stdio.h>
#include "retangulo.h"

int	main(void)
{
	t_retangulo	r;

	r.largura = 3;
	r.altura = 4;
	printf("area = %d\n", ft_area(r));
	ft_dobra(&r);
	printf("depois de dobrar: %d x %d, ", r.largura, r.altura);
	printf("area = %d\n", ft_area(r));
	return (0);
}
```

```
area = 12
depois de dobrar: 6 x 8, area = 48
```

</details>
