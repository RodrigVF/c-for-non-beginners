# Resposta — c00/ex04: ft_putstr

## Solução

```c
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
```

Arquivo: [`ft_putstr.c`](ft_putstr.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. A string termina no `'\0'`; é o único jeito de saber o fim.
2. `&str[i]` é o endereço do i-ésimo caractere (equivale a `str + i`).
3. Escreve 1 byte por vez até achar o `'\0'` (que **não** é escrito).

## Variação com um só `write`

Mais eficiente (uma syscall em vez de N):

```c
void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}
```

## Erros comuns

- Esquecer o `i++`: loop infinito imprimindo a primeira letra.
- Condição `str[i] != '0'` (o caractere zero) em vez de `'\0'`: para no primeiro dígito `0` e passa do fim em strings sem ele.

## Casos extremos

- String vazia (`""`): o laço não roda, nada é impresso. Correto.
- `NULL`: segfault. O subject não pede tratamento; a função padrão `puts` também quebraria. Se quiser se proteger, `if (str == NULL) return ;` no início.

## Como testar

```bash
./run.sh ft_putstr
```
