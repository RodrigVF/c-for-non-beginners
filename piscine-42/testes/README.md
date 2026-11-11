# testes/

Uma pasta por exercício. Estes arquivos **nunca são entregues**: eles só existem para testar.

```
testes/ft_strlen/
├── main.c          ← chama a sua função com vários casos (pode usar printf)
└── esperado.txt    ← a saída correta, byte a byte
testes/ola/
└── teste.sh        ← exercícios de shell têm um script de teste
testes/ft_show_args/
└── teste.sh        ← programas (c05) também: o teste compila o seu .c
                      sozinho e roda com vários argumentos
```

Nos testes de programa, a saída aparece entre colchetes, e o `$` marca o fim de cada linha (o `\n`). Assim dá para ver linhas vazias e espaços sobrando: `[a$b$]` é "a", quebra de linha, "b", quebra de linha.

## Rodando

```bash
./run.sh ft_strlen                  # sua versão (minha-versao/)
./run.sh ft_strlen --resposta       # versão de 03-respostas/
./testes/rodar_todos.sh             # todos, sua versão
./testes/rodar_todos.sh --resposta  # todos, respostas
./run.sh --lista                    # nomes disponíveis
```

O que o `run.sh` confere, em ordem:

1. Acha o arquivo (`ft_strlen.c`) em `minha-versao/`.
2. Compila com `cc -Wall -Wextra -Werror -g` junto com `testes/ft_strlen/main.c`.
3. Roda (com limite de 5 segundos, para pegar loop infinito) e detecta *segmentation fault*.
4. Compara a saída com `esperado.txt` e mostra a diferença (`-` esperado, `+` sua saída).
5. Se o seu arquivo usa `malloc`: roda o `valgrind` e acusa leaks e acessos inválidos.
6. Roda a `norminette` no seu arquivo.

## Por que `setbuf(stdout, NULL)` nos `main.c`?

`printf` não escreve na hora: ele junta o texto num buffer e escreve depois. Já `write` escreve na hora. Misturando os dois, a ordem na saída pode sair trocada (especialmente quando a saída vai para um arquivo ou pipe, como no `run.sh`). `setbuf(stdout, NULL)` desliga o buffer do `printf` e mantém a ordem certa.

## Escrevendo seus próprios testes

Faça isso sempre: na Piscine e nos exames, você não terá estes testes prontos. Modelo:

```c
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("%d\n", ft_strlen("abc"));
	printf("%d\n", ft_strlen(""));
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror ft_strlen.c main.c && ./a.out
```

Pense nos casos extremos: string vazia, um caractere, negativos, zero, `INT_MIN`, `INT_MAX`.
