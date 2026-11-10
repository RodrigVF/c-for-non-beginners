# Resposta — c00/ex00: ft_putchar

## Solução

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

Arquivo: [`ft_putchar.c`](ft_putchar.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. `write` pede: onde escrever (`1` = stdout), **o endereço** dos bytes e quantos bytes.
2. Temos o caractere `c`, não um endereço. `&c` é o endereço da variável `c` (que é uma cópia local do argumento, na stack).
3. Um `char` ocupa 1 byte, então o tamanho é `1`.

```
stack de ft_putchar:   c = 'a'   ← &c aponta aqui
write(1, &c, 1)  →  "pegue 1 byte a partir de &c e mande para a tela"
```

## Erros comuns

- `write(1, c, 1)`: passa o **valor** (`97`) como se fosse endereço. Com `-Wall -Werror` não compila (`makes pointer from integer without a cast`); sem as flags, dá segfault.
- `write(1, "c", 1)`: imprime sempre a letra `c`.
- Deixar uma `main` no arquivo.
- Esquecer `#include <unistd.h>`: `implicit declaration of function 'write'`.

## Casos extremos

- Caracteres não imprimíveis (`'\n'`, `'\0'`) também são escritos: `write` não interpreta nada.

## Como testar

```bash
./run.sh ft_putchar
```
