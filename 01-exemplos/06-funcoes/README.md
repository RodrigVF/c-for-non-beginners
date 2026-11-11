# Aula 06 — Funções, escopo e passagem por valor

⏱️ ~7 minutos · Arquivo: [`por_valor.c`](por_valor.c)

## Sintaxe

```c
tipo_de_retorno	nome(tipo_param1 p1, tipo_param2 p2)
{
	...
	return (valor);
}
```

```c
int	dobro(int x)
{
	return (x * 2);
}

void	diz_oi(void)        /* void = não devolve nada */
{
	write(1, "oi\n", 3);
}
```

Tudo é tipado: retorno e parâmetros. Funções `void` usam `return ;` (sem valor) se precisarem sair antes do fim.

Regras da Norma para funções: no máximo **25 linhas** no corpo, **4 parâmetros**, **5 funções por arquivo**. Na 42, use o prefixo `ft_` nas funções de exercício.

## Escopo: cada função tem as suas variáveis

Uma variável declarada dentro de uma função **só existe dentro dela**, e só **enquanto ela está rodando**. Quando a função termina, a memória dessas variáveis é liberada automaticamente.

Essa memória fica numa região chamada **stack** (pilha):

```
   chamada de main()           main chama dobro(5)          dobro terminou
┌──────────────────┐        ┌──────────────────┐        ┌──────────────────┐
│ main: n = 5      │        │ main: n = 5      │        │ main: n = 10     │
└──────────────────┘        ├──────────────────┤        └──────────────────┘
                            │ dobro: x = 5     │  ← caixa nova, some no fim
                            └──────────────────┘
```

> ⚠️ Consequência importante: **nunca devolva o endereço de uma variável local**. Depois do `return`, aquela caixa não existe mais (volta na aula 09).

## Passagem por valor: a função recebe uma CÓPIA

Em C, **todo** argumento é passado por valor. A função recebe uma cópia; mexer nela não muda a variável original.

```bash
cc -Wall -Wextra -Werror por_valor.c ../util/ft_util.c && ./a.out
```

```
dentro de tenta_mudar, x = 100
na main, n continua = 5
usando o retorno: n = dobro(n) = 10
```

```
main                          tenta_mudar
┌─────────┐   copia o 5     ┌─────────┐
│ n = 5   │ ──────────────> │ x = 5   │   x = 100  →  │ x = 100 │
└─────────┘                 └─────────┘
     ↑ n não foi tocado
```

Então, como uma função altera uma variável de quem chamou? Duas saídas:

1. **Devolver** o novo valor (`n = dobro(n);`).
2. Passar o **endereço** da variável (um ponteiro). Aí a cópia é do endereço, e com ele dá para mexer no original. Isso é a aula 08 (`ft_swap`).

> 💡 Analogia: passar por valor é mandar uma **fotocópia** de um documento. A pessoa pode rabiscar a cópia à vontade; o seu original fica intacto. Passar um ponteiro é mandar o **endereço da sua casa**: aí ela pode ir lá e mudar os móveis.

## E arrays? Também é por valor?

Sim, mas o que é copiado é o **endereço** do primeiro elemento, não o array inteiro. Por isso uma função consegue alterar o conteúdo de uma string recebida (como `ft_strcpy`). Você vai entender por que na aula 07.

## Funções `static`

Você pode ver `static void	ft_aux(...)`. `static` numa função significa "visível só dentro deste arquivo". É útil para auxiliares, e evita conflito de nomes com outros arquivos.

## É normal estranhar

Em Python, listas e objetos parecem "passados por referência". Em C, nada é por referência de forma automática. Se algo mudou fora da função, foi porque um endereço foi passado. Isso é bom: dá para saber olhando a assinatura.

## Mini-exercício

Escreva `int	ft_max(int a, int b)` que devolve o maior. Depois `void	ft_print_max(int a, int b)` que imprime o maior usando `ft_max` e `ft_putnbr` (de `../util`). Respeite o limite de 25 linhas e declare tudo no início.

## Perguntas de fixação

1. O que acontece com as variáveis locais quando a função retorna?
2. Por que `tenta_mudar(n)` não altera `n`?
3. Quais as duas formas de uma função "mudar" um valor de quem chamou?
4. Por que devolver o endereço de uma variável local é um erro?
5. O que `static` faz numa função?

<details>
<summary>Respostas</summary>

1. Deixam de existir: o espaço delas na stack é liberado.
2. Porque `tenta_mudar` recebe uma cópia do valor de `n`, numa variável própria (`x`).
3. Devolver o novo valor com `return`, ou receber um ponteiro para a variável e alterar através dele.
4. Porque a variável deixa de existir quando a função termina; o endereço passa a apontar para memória que será reutilizada.
5. Restringe a visibilidade da função ao arquivo onde ela foi definida.

Mini-exercício:
```c
#include "../util/ft_util.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_print_max(int a, int b)
{
	ft_putnbr(ft_max(a, b));
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_max(3, 42);
	ft_print_max(-1, -7);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror arquivo.c ../util/ft_util.c && ./a.out
```

`ft_max` vem antes de `ft_print_max` no arquivo porque é usada por ela (aula 02).

</details>
