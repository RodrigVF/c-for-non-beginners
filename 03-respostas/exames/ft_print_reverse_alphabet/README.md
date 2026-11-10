# Resposta — exame 01, nível 0: ft_print_reverse_alphabet

## Solução

```c
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
```

Arquivo: [`ft_print_reverse_alphabet.c`](ft_print_reverse_alphabet.c) (com o cabeçalho da 42 no topo)

## Raciocínio

O espelho do `ft_print_alphabet`: começa em `'z'`, decrementa (`c--`) e para depois do `'a'`.

## Erros comuns

- `while (c > 'a')`: esquece o `a`.
- Começar em `'a'` e somar: imprime na ordem errada.

## Como testar

```bash
./run.sh ft_print_reverse_alphabet
```
