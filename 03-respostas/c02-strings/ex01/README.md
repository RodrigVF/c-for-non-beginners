# Resposta — c02/ex01: ft_strcmp

## Solução

```c
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```

Arquivo: [`ft_strcmp.c`](ft_strcmp.c) (com o cabeçalho da 42 no topo)

## Raciocínio

1. Avança enquanto os caracteres são iguais **e** `s1` não acabou.
2. Não precisa testar se `s2` acabou: se `s2[i]` for `'\0'` e `s1[i]` não, eles já são diferentes e o laço para.
3. Ao parar, a diferença entre os caracteres atuais diz quem é "maior".

```
"abc" vs "abd"         "abc" vs "ab"
  a = a  → avança        a = a → avança
  b = b  → avança        b = b → avança
  c ≠ d  → para          c ≠ \0 → para
  'c' - 'd' = -1         'c' - 0 = 99  (positivo)
```

4. **Por que `unsigned char`?** O `char` no Linux x86 tem sinal: o byte `0x80` vale `-128`. A `strcmp` padrão compara como `unsigned char` (`0x80` = `128`, maior que `'a'`). Sem o cast, o caso 9 do teste (`"\200"` contra `"a"`) dá o sinal errado.

## Erros comuns

- Devolver só `-1`, `0` ou `1`: pela especificação (`man 3 strcmp`) só o sinal importa, e o teste deste repositório compara só o **sinal**. Mas não dá para saber de antemão como uma correção vai comparar; devolver a diferença, como a função original costuma fazer, é o mais seguro.
- Condição `s1[i] && s2[i] && s1[i] == s2[i]`: funciona, só é redundante.
- Comparar ponteiros (`s1 == s2`): compara endereços, não conteúdo.

## Casos extremos

- `""` vs `""` → 0; `""` vs `"a"` → negativo; `"a"` vs `""` → positivo.
- Prefixo: `"ab"` vs `"abc"` → negativo.

## Como testar

```bash
./run.sh ft_strcmp
```
