# C além do básico

> ⚠️ Material **não oficial**, sem vínculo com a 42. Gratuito e [open-source](../README.md#licença).

Esta trilha continua de onde a [Preparação Piscine 42](../piscine-42/) para. São três aulas curtas sobre como **organizar** um programa em C de verdade:

| # | Aula | Ideia |
|---|---|---|
| 01 | [Seus próprios headers e vários arquivos](01-headers-e-arquivos/) | separar o código em `.c` e `.h` |
| 02 | [`struct` e `typedef`](02-struct-typedef/) | agrupar dados e criar seus próprios tipos |
| 03 | [`Makefile`](03-makefile/) | compilar tudo com um comando, sem recompilar à toa |

**Pré-requisitos:** as aulas de [compilação](../piscine-42/01-exemplos/02-compilacao/) e de [ponteiros](../piscine-42/01-exemplos/08-ponteiros/) da trilha da Piscine.

Na Piscine, esses assuntos costumam aparecer mais para o fim (o momento exato, confirme com a 42SP). Nos projetos depois dela, eles aparecem o tempo todo.

## Como rodar os exemplos

Cada aula tem uma pasta `exemplo/` com um mini-projeto. Entre nela e siga o comando da aula. Por exemplo:

```bash
cd c-alem-do-basico/02-struct-typedef/exemplo
cc -Wall -Wextra -Werror main.c ponto.c
./a.out
```

Todo o código segue a Norma da 42 e passa na `norminette`.
