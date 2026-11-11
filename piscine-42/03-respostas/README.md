# 03 — Respostas

> Abra só **depois** de tentar. O aprendizado está no tempo que você passa travado. Uma boa regra: 20 minutos de tentativa real (incluindo testar e ler o erro) antes de olhar.

Cada pasta tem a solução (`.c` ou `.sh`, seguindo a Norma e com cabeçalho) e um `README.md` com: raciocínio passo a passo, erros comuns, casos extremos e como testar. Os de `malloc` mostram como conferir leaks com o `valgrind`.

| Módulo | Respostas |
|---|---|
| shell00 | [ex00 ola](shell00/ex00/) · [ex01 permissoes](shell00/ex01/) · [ex02 conta_erros](shell00/ex02/) · [ex03 lista_c](shell00/ex03/) · [ex04 usuarios](shell00/ex04/) |
| c00 | [ex00 ft_putchar](c00-basico/ex00/) · [ex01 ft_print_alphabet](c00-basico/ex01/) · [ex02 ft_print_numbers](c00-basico/ex02/) · [ex03 ft_is_negative](c00-basico/ex03/) · [ex04 ft_putstr](c00-basico/ex04/) · [ex05 ft_strlen](c00-basico/ex05/) · [ex06 ft_putnbr](c00-basico/ex06/) |
| c01 | [ex00 ft_swap](c01-ponteiros/ex00/) · [ex01 ft_div_mod](c01-ponteiros/ex01/) · [ex02 ft_ultimate_div_mod](c01-ponteiros/ex02/) |
| c02 | [ex00 ft_strcpy](c02-strings/ex00/) · [ex01 ft_strcmp](c02-strings/ex01/) · [ex02 ft_strrev](c02-strings/ex02/) · [ex03 ft_str_is_numeric](c02-strings/ex03/) · [ex04 ft_strcat](c02-strings/ex04/) |
| c03 | [ex00 ft_strdup](c03-memoria/ex00/) · [ex01 ft_range](c03-memoria/ex01/) · [ex02 ft_strjoin](c03-memoria/ex02/) |
| c04 | [ex00 ft_factorial](c04-recursao/ex00/) · [ex01 ft_power](c04-recursao/ex01/) |
| c05 | [ex00 ft_show_name](c05-programas/ex00/) · [ex01 ft_show_args](c05-programas/ex01/) · [ex02 ft_rev_args](c05-programas/ex02/) · [ex03 ft_sort_args](c05-programas/ex03/) |
| c06 | [ex00 ft_strncmp](c06-desafios/ex00/) · [ex01 ft_putnbr_base](c06-desafios/ex01/) · [ex02 ft_split](c06-desafios/ex02/) |
| exames (novos) | [ft_print_reverse_alphabet](exames/ft_print_reverse_alphabet/) · [ft_str_is_alpha](exames/ft_str_is_alpha/) · [ft_atoi](exames/ft_atoi/) · [ft_last_arg](exames/ft_last_arg/) |

Os outros exercícios das simulações de exame usam as respostas dos módulos acima.

Para conferir que todas as respostas passam:

```bash
./testes/rodar_todos.sh --resposta
```
