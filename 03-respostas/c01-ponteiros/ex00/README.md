# Resposta — c01/ex00: ft_swap

## Solução

```c
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
```

Arquivo: [`ft_swap.c`](ft_swap.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. C passa tudo por valor. Para alterar as variáveis de quem chamou, recebemos os **endereços** (aula 08).
2. `*a` é "o int que está no endereço `a`". Ler e escrever `*a` mexe no original.
3. A troca precisa de um terceiro lugar: se fizer `*a = *b` direto, o valor antigo de `*a` se perde.

```
antes:    x=1  y=2      tmp=?
tmp = *a  x=1  y=2      tmp=1
*a = *b   x=2  y=2      tmp=1
*b = tmp  x=2  y=1      tmp=1
```

## Erros comuns

- Trocar os ponteiros em vez dos valores (`tmp = a; a = b; b = tmp;` com `int *tmp`): troca só as cópias locais dos endereços. Nada muda fora.
- `int	tmp;` com `tmp = a;` (sem `*`): não compila com as flags (atribuir ponteiro a int).

## Casos extremos

- `ft_swap(&x, &x)`: funciona (o valor continua o mesmo). O truque "sem variável temporária" com XOR **zeraria** `x` neste caso; prefira a versão com `tmp`.

## Como testar

```bash
./run.sh ft_swap
```
