# Aula 04 — Operadores e armadilhas

⏱️ ~7 minutos · Arquivos: [`divisao.c`](divisao.c), [`verdade.c`](verdade.c)

Você já conhece `+ - * / % == != < > && || !`. Aqui vão só as diferenças de C que causam bugs.

## Armadilha 1 — Divisão entre inteiros joga fora a parte decimal

```bash
cc -Wall -Wextra -Werror divisao.c ../util/ft_util.c && ./a.out
```

```
7 / 2      = 3
7 % 2      = 1
-7 / 2     = -3
-7 % 2     = -1
1 / 3 * 3  = 0
1 * 3 / 3  = 1
123 % 10   = 3
123 / 10   = 12
```

**Por quê?** O tipo do resultado depende do tipo dos operandos. `int / int` produz `int`. Não existe "promoção automática" para decimal como em JavaScript.

- A divisão **trunca em direção ao zero**: `-7 / 2` é `-3` (e não `-4`, como em Python com `//`).
- O resto tem o **sinal do dividendo**: `-7 % 2` é `-1`.
- A ordem importa: `1 / 3 * 3` é `0` porque `1 / 3` já virou `0`.

O par `% 10` e `/ 10` é a chave para separar dígitos de um número (você vai usar em `ft_putnbr`):

```
123 % 10 = 3    → último dígito
123 / 10 = 12   → "corta" o último dígito
```

## Armadilha 2 — `=` atribui, `==` compara

```c
if (x = 5)      /* ATRIBUI 5 a x. O valor da expressão é 5 → sempre verdade */
if (x == 5)     /* compara */
```

Em C, **atribuição é uma expressão que tem valor**. Por isso o primeiro `if` compila.
A boa notícia: com `-Wall -Werror`, o `cc` recusa:

```
error: suggest parentheses around assignment used as truth value [-Werror=parentheses]
```

Se aparecer essa mensagem, quase sempre você quis `==`.

## Armadilha 3 — Não existe `true` e `false` (por padrão)

Em C, condições são números:

- `0` é **falso**.
- **Qualquer** outro valor é **verdadeiro** (inclusive `-1`).
- Comparações devolvem `int`: `1` ou `0`.

```bash
cc -Wall -Wextra -Werror verdade.c ../util/ft_util.c && ./a.out
```

```
5 > 3    vale 1
5 < 3    vale 0
!0       vale 1
!42      vale 0
3 && 0   vale 0
3 || 0   vale 1
if (-1) entrou: qualquer valor diferente de 0 e verdade
```

Isso explica idiomas que você vai ver muito:

```c
while (str[i])            /* para quando str[i] vale 0, ou seja, '\0' */
if (!ptr)                 /* "se ptr é nulo" */
```

Na 42 é comum escrever a comparação explícita (`str[i] != '\0'`) para ficar mais legível. As duas formas são iguais para o compilador.

## Armadilha 4 — `&&` e `||` param cedo (short-circuit)

```c
if (ptr != NULL && ptr[0] == 'a')
```

Se `ptr != NULL` for falso, a segunda parte **nem roda**. Isso é uma proteção: ler `ptr[0]` com `ptr` nulo quebraria o programa. A ordem das condições importa.

## Armadilha 5 — `i++` e `++i`

Os dois somam 1. A diferença só aparece se você usar o valor na mesma expressão:

```c
i = 5;
a = i++;     /* a recebe 5, depois i vira 6 */
b = ++i;     /* i vira 7, depois b recebe 7 */
```

Conselho: use `i++;` sozinho numa linha. Nunca use `i` duas vezes numa expressão com `++` (`i = i++;` é comportamento indefinido).

## Armadilha 6 — Overflow silencioso

```c
int	x;

x = 2147483647;
x = x + 1;      /* overflow: comportamento indefinido; na prática vira -2147483648 */
```

C não avisa em tempo de execução. O número "dá a volta". Quando houver risco, use um tipo maior (`long`) para as contas.

## É normal estranhar

Quem vem de linguagens com `bool` acha `if (-1)` esquisito. Em C, `if` só pergunta: "isso é zero?". Ponto. Pense sempre assim.

## Mini-exercício

Sem rodar, diga o que cada linha produz. Depois confirme num programa.

```c
17 / 5
17 % 5
-17 / 5
2 * 3 % 4
!(5 == 5)
```

## Perguntas de fixação

1. Por que `7 / 2` dá `3` em C?
2. O que `if (x = 0)` faz? O `if` entra?
3. Quanto vale a expressão `10 > 3`?
4. Como pegar o último dígito de 4321? E como "remover" esse dígito?
5. Em `if (p != NULL && p[0] == 'x')`, por que a ordem importa?

<details>
<summary>Respostas</summary>

1. Porque os dois operandos são `int`, então o resultado é `int` e a parte decimal é descartada (truncada em direção ao zero).
2. Atribui `0` a `x`. O valor da expressão é `0` (falso), então o `if` nunca entra. Com `-Wall -Werror`, nem compila.
3. `1`.
4. `4321 % 10` dá `1`. `4321 / 10` dá `432`.
5. Por causa do short-circuit: se `p` for `NULL`, a segunda parte não é avaliada, o que evita ler memória inválida.

Mini-exercício: `3`, `2`, `-3`, `2` (`6 % 4`), `0`.

</details>
