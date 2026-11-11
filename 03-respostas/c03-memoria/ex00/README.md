# Resposta — c03/ex00: ft_strdup

## Solução

```c
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
```

Arquivo: [`ft_strdup.c`](ft_strdup.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Mede `src`. Não dá para chamar a `strlen` da biblioteca (não está nas *allowed functions*), mas você pode escrever um `ft_strlen` auxiliar no mesmo arquivo. Aqui o laço é curto, então ficou direto na função.
2. Aloca `len + 1` bytes: o `+ 1` é o `'\0'`.
3. Testa `NULL` (falta de memória).
4. Copia **incluindo** o `'\0'`: por isso `i <= len`.
5. Devolve o ponteiro do heap. Ele sobrevive ao fim da função. Quem chamou é quem dá `free`.

```
 STACK (ft_strdup)        HEAP
 dup ───────────────────> [O][l][a][\0]   ← sobrevive ao return
 src ──> "Ola" (literal, só leitura)
```

## Erros comuns

- `malloc(len)`: falta 1 byte. O teste passa a saída por sorte, mas o `valgrind` acusa `Invalid write of size 1 ... 0 bytes after a block of size 3`.
- Não testar o retorno do `malloc`.
- Devolver um array local (`char dup[100]; ... return (dup);`): o compilador avisa (`function returns address of local variable`) e a memória é inválida depois do `return`.
- Esquecer `#include <stdlib.h>`: `implicit declaration of function 'malloc'`.

## Casos extremos

- `""`: aloca 1 byte e copia só o `'\0'`. Devolve uma string vazia válida (e liberável).

## Conferindo leaks

O `run.sh` já roda o `valgrind`. Manualmente:

```bash
cc -Wall -Wextra -Werror -g minha-versao/c03/ex00/ft_strdup.c testes/ft_strdup/main.c -o t
valgrind --leak-check=full ./t
```

Procure: `All heap blocks were freed -- no leaks are possible` e `ERROR SUMMARY: 0 errors`. Lembre: o `free` está no `main.c` de teste; o leak, se aparecer, é do teste, a menos que sua função aloque duas vezes.

## Como testar

```bash
./run.sh ft_strdup
```
