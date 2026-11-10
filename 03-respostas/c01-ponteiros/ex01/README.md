# Resposta — c01/ex01: ft_div_mod

## Solução

```c
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
```

Arquivo: [`ft_div_mod.c`](ft_div_mod.c) (com o cabeçalho da 42 no topo)

## Raciocínio

C só devolve **um** valor com `return`. Para "devolver" dois, a função recebe endereços e escreve neles. Quem chama faz:

```c
int	d;
int	m;

ft_div_mod(42, 10, &d, &m);
```

```
main: d=? m=?   ──&d, &m──>   ft_div_mod: div=&d mod=&m
                              *div = 4  → d = 4
                              *mod = 2  → m = 2
```

## Erros comuns

- `div = a / b;` (sem `*`): tenta guardar um número na variável que guarda o endereço. Não compila com as flags.
- Esperar `-7 / 2 = -4` (como em Python): em C a divisão trunca para zero, dá `-3`, e o resto tem o sinal de `a`: `-1`.

## Casos extremos

- `b == 0`: divisão por zero derruba o programa (`Floating point exception`). O subject diz que não é preciso tratar.
- `a` negativo / `b` negativo: veja os testes (`-7, 2` → `-3, -1`; `7, -2` → `-3, 1`).

## Como testar

```bash
./run.sh ft_div_mod
```
