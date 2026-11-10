# Aula 07 — Arrays e strings

⏱️ ~10 minutos · Arquivos: [`array_int.c`](array_int.c), [`strings.c`](strings.c)

## Array = caixas iguais, lado a lado

```c
int	notas[3];
```

Reserva **3 ints consecutivos** (12 bytes). O tamanho é fixo, decidido na compilação.

```
notas:   [  10  ][  7   ][  25  ]
índice:     0       1       2
bytes:   0-3     4-7     8-11
```

- Índices começam em `0`.
- **C não confere os limites.** `notas[5] = 1;` compila e escreve em memória que não é sua. Pode não acontecer nada, pode corromper outra variável, pode dar *segmentation fault*. O C confia em você.

> 💡 Por que C não confere? Conferir custa uma comparação a cada acesso. C prefere ser rápido e deixar a responsabilidade com o programador.

Arrays não sabem o próprio tamanho quando são passados para funções. Por isso a função recebe o tamanho junto, como em [`array_int.c`](array_int.c):

```c
int	soma(int *tab, int tamanho)
```

## String = array de `char` terminado em `'\0'`

C não tem um tipo "string". Uma string é **uma sequência de `char` que termina com o byte zero** (`'\0'`).

```c
"ola"
```

ocupa **4 bytes**:

```
[ 'o' ][ 'l' ][ 'a' ][ '\0' ]
  111    108    97     0
```

O `'\0'` é a **única** forma de saber onde a string termina. Toda função de string (`ft_strlen`, `ft_putstr`, `ft_strcpy`...) é um laço "ande até achar `'\0'`":

```c
i = 0;
while (str[i] != '\0')
{
	...
	i++;
}
```

> ⚠️ Se você montar uma string e esquecer o `'\0'`, as funções vão continuar lendo memória até achar um zero por acaso. É um dos bugs mais comuns da Piscine (o `ft_strcpy` sem `dest[i] = '\0'`).

`'\0'` (char nulo, valor 0) não é `'0'` (o caractere zero, valor 48).

## Literal contra array

Existem dois jeitos de ter uma string, e eles **não são iguais**:

```c
char	*literal;
char	palavra[4];

literal = "ola";        /* aponta para um texto fixo do programa */
palavra[0] = 'o';       /* array seu, na stack */
palavra[1] = 'l';
palavra[2] = 'a';
palavra[3] = '\0';
```

(Fora da 42 você veria `char palavra[] = "ola";`, que faz a mesma coisa em uma linha. Na Norma, a inicialização na declaração é proibida.)

```
 STACK (suas variáveis)                     ÁREA SÓ-LEITURA DO PROGRAMA
┌───────────────────────────┐              ┌──────────────────────────┐
│ palavra: [o][l][a][\0]    │              │ "ola\0"  ← o literal     │
│ literal: [ endereço ] ────┼─────────────>│                          │
└───────────────────────────┘              └──────────────────────────┘
```

| | `palavra` (array) | `literal` (`char *`) |
|---|---|---|
| O que é | 4 bytes de chars | 8 bytes guardando um endereço |
| `sizeof` | 4 | 8 |
| Pode mudar letras? | Sim | **Não** (crash: *segmentation fault*) |

Rode [`strings.c`](strings.c):

```bash
cc -Wall -Wextra -Werror strings.c ../util/ft_util.c && ./a.out
```

```
[o][l][a][\0]
Ola
sizeof(palavra) = 4 | sizeof(literal) = 8
[o][l][a][\0]
```

> ⚠️ Nos testes de `ft_strrev`, `ft_strcpy` e `ft_strcat`, **nunca** passe um literal como destino. Use um array (`char buf[64];`). Escrever num literal dá *segmentation fault*.

## `char *` e `char[]` em parâmetros

Quando você passa um array para uma função, o que vai é o **endereço do primeiro elemento**. Por isso estes protótipos são equivalentes:

```c
void	ft_putstr(char *str);
void	ft_putstr(char str[]);
```

Na 42 usa-se `char *str`. E é por isso que `ft_strcpy` consegue alterar o `dest` de quem chamou: recebeu o endereço dele.

## Array de strings: `char **`

```c
char	*nomes[3];      /* 3 ponteiros para char */

nomes[0] = "Ana";
nomes[1] = "Bia";
nomes[2] = "Caio";
```

Passado para função, vira `char **strs`. É o que `ft_strjoin` recebe. `strs[1][0]` é `'B'`.

## É normal estranhar

"String é um array, mas às vezes é um ponteiro?" Sim, e essa é a parte mais confusa de C para todo mundo. A regra: **na maioria das expressões, o nome de um array vira o endereço do primeiro elemento**. A aula 08 deixa isso mais claro.

## Mini-exercício

Escreva `int	ft_count_char(char *str, char c)` que devolve quantas vezes `c` aparece em `str`. Teste com `"banana"` e `'a'` (deve dar 3).

## Perguntas de fixação

1. Quantos bytes ocupa `"Piscine"`?
2. O que acontece se você acessar `tab[10]` num `int tab[3]`?
3. Por que mudar `literal[0]` dá erro, mas mudar `palavra[0]` não?
4. Qual a diferença entre `'\0'` e `'0'`?
5. Por que funções que recebem arrays precisam de um parâmetro de tamanho (exceto strings)?

<details>
<summary>Respostas</summary>

1. 8 bytes: 7 letras mais o `'\0'`.
2. Comportamento indefinido: o C não verifica. Pode ler lixo, corromper outra variável ou dar *segmentation fault*.
3. O literal fica numa área de memória só-leitura do programa; `palavra` é um array seu, na stack, que você pode alterar.
4. `'\0'` é o byte de valor 0 (fim de string). `'0'` é o caractere do dígito zero (valor 48).
5. Porque a função só recebe o endereço do primeiro elemento e não tem como saber o tamanho. Strings não precisam porque terminam em `'\0'`.

</details>
