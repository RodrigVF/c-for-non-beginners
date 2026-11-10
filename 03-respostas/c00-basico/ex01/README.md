# Resposta — c00/ex01: ft_print_alphabet

## Solução

```c
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
```

Arquivo: [`ft_print_alphabet.c`](ft_print_alphabet.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. As letras minúsculas têm códigos consecutivos: `'a'` = 97, ..., `'z'` = 122 (veja `man ascii`).
2. Então um `char` começando em `'a'` e incrementado até passar de `'z'` percorre o alfabeto.
3. O `for` é proibido pela Norma: inicialização antes, condição no `while`, `c++` no fim do corpo.

## Erros comuns

- `while (c < 'z')`: esquece o `z`.
- Imprimir `'\n'` no final: o subject não pede. A correção compara a saída exata.
- Inicializar na declaração (`char c = 'a';`): erro de Norma.

## Variação

Poderia ser feito com `write(1, "abcdefghijklmnopqrstuvwxyz", 26);`. Funciona, mas foge da intenção do exercício (praticar laço e `char` como número).

## Como testar

```bash
./run.sh ft_print_alphabet
```
