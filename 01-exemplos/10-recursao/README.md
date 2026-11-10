# Aula 10 — Recursão

⏱️ ~6 minutos · Arquivo: [`contagem.c`](contagem.c)

Você já sabe o que é recursão. Aqui vai o que é específico de C: **como ela usa a memória**.

## Cada chamada ganha uma caixa nova na stack

Toda chamada de função cria um bloco na stack (*stack frame*) com seus parâmetros e variáveis locais. Na recursão, cada chamada tem **o seu próprio** `n`, independente dos outros.

```c
void	contagem(int n)
{
	if (n == 0)
		return ;          /* caso base */
	/* ida */
	contagem(n - 1);
	/* volta */
}
```

```
contagem(3)
   │
   ▼
┌─────────────┐
│ contagem    │ n = 0   ← caso base: retorna, e a stack "desempilha"
├─────────────┤
│ contagem    │ n = 1
├─────────────┤
│ contagem    │ n = 2
├─────────────┤
│ contagem    │ n = 3
├─────────────┤
│ main        │
└─────────────┘
```

```bash
cc -Wall -Wextra -Werror contagem.c ../util/ft_util.c && ./a.out
```

```
ida   n = 3
ida   n = 2
ida   n = 1
caso base: n == 0, comecando a voltar
volta n = 1
volta n = 2
volta n = 3
soma_ate(4) = 10
```

O que vem **antes** da chamada recursiva roda na ida. O que vem **depois** roda na volta, em ordem inversa. É assim que `ft_putnbr` imprime os dígitos na ordem certa: chama para `nb / 10` primeiro e imprime o seu dígito na volta.

```
ft_putnbr(123)
  └─ ft_putnbr(12)
       └─ ft_putnbr(1)
            imprime '1'          (volta)
       imprime '2'
  imprime '3'
```

## Sem caso base = *segmentation fault*

A stack tem tamanho limitado (no Linux, normalmente 8 MB; veja com `ulimit -s`). Uma recursão sem fim enche a stack e o sistema mata o programa:

```
Segmentation fault (core dumped)
```

Isso é o *stack overflow* (sim, o nome do site vem daqui).

## Recursão e a Norma

- Funciona bem para exercícios como `ft_factorial` e `ft_power`, e simplifica muito o `ft_putnbr`.
- Cuidado com os casos extremos: números negativos e o caso `0`. Pense neles **antes** de escrever.
- Não há otimização garantida: uma recursão de 1 milhão de níveis pode estourar a stack. Para laços grandes, prefira `while`.

## É normal estranhar

Em C, a recursão não é "mágica": é a mesma pilha de chamadas de sempre. Desenhar a pilha (como acima) com 3 ou 4 níveis resolve qualquer dúvida.

## Mini-exercício

Escreva `int	ft_sum_digits(int n)` recursiva, que devolve a soma dos dígitos de um número positivo (`1234` → `10`). Dica: `n % 10` e `n / 10`.

## Perguntas de fixação

1. Onde ficam os parâmetros de cada chamada recursiva?
2. Em `contagem`, por que "volta" aparece em ordem crescente?
3. O que acontece sem caso base?
4. Por que `ft_putnbr` recursivo imprime os dígitos na ordem certa?

<details>
<summary>Respostas</summary>

1. Na stack, cada chamada no seu próprio *stack frame*.
2. Porque a chamada mais profunda (`n = 1`) é a primeira a terminar; as outras terminam depois, desempilhando.
3. A recursão continua até estourar a stack, e o programa termina com *segmentation fault*.
4. Porque ele resolve `nb / 10` (os dígitos da esquerda) antes e só imprime o último dígito na volta.

Mini-exercício:
```c
int	ft_sum_digits(int n)
{
	if (n < 10)
		return (n);
	return (n % 10 + ft_sum_digits(n / 10));
}
```

</details>
