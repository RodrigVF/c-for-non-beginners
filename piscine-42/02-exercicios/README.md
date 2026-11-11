# 02 — Exercícios

> ⚠️ **Estes enunciados são recriações no estilo da Piscine**, escritas para treino. Não são os subjects oficiais da 42. Os nomes de algumas funções (como `ft_putchar` e `ft_strlen`) são clássicos de C e aparecem em muitos lugares, mas os textos, exemplos e detalhes aqui foram escritos para este repositório.

## Módulos (em ordem)

| Módulo | Tema | Exercícios |
|---|---|---|
| [shell00](shell00/) | permissões, scripts, `grep`, pipes | 5 |
| [c00-basico](c00-basico/) | `write`, laços, `char`, `ft_putnbr` | 7 |
| [c01-ponteiros](c01-ponteiros/) | `ft_swap`, `ft_div_mod` | 3 |
| [c02-strings](c02-strings/) | cópia, comparação, inversão | 5 |
| [c03-memoria](c03-memoria/) | `malloc` | 3 |
| [c04-recursao](c04-recursao/) | fatorial, potência | 2 |
| [c05-programas](c05-programas/) | programas com `argc`/`argv` | 4 |
| [c06-desafios](c06-desafios/) | `ft_strncmp`, `ft_putnbr_base`, `ft_split` (extra, mais difícil) | 3 |
| [exames](exames/) | 4 simulações cronometradas | — |

## Como fazer cada exercício

1. Leia o subject **inteiro**, duas vezes. Na Piscine, muita gente erra por não ler um detalhe.
2. Crie o arquivo dentro de `minha-versao/`, imitando a estrutura de entrega:
   ```
   piscine-42/minha-versao/c00/ex00/ft_putchar.c
   ```
3. Escreva com o cabeçalho da 42 no topo (veja [`../ferramentas/`](../ferramentas/)).
4. Teste:
   ```bash
   ./run.sh ft_putchar
   ```
   O script compila com `cc -Wall -Wextra -Werror` junto com `testes/ft_putchar/main.c`, compara a saída, roda o `valgrind` (se houver `malloc`) e a `norminette`.
5. Só depois de passar (ou de travar por uns 20 minutos), abra a resposta em `03-respostas/`.

## Legenda

- **Dificuldade**: 🟢 fácil · 🟡 médio · 🔴 difícil
- **Allowed functions**: só essas funções externas podem ser usadas. Usar outra (como `printf` ou `strlen`) zera o exercício na correção real.
- As dicas ficam escondidas em blocos "Dica". Tente sem elas primeiro.
