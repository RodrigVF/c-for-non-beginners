# Simulações de exame

> ⚠️ Os exercícios e o formato daqui são **recriações**. O funcionamento real dos exames da Piscine (duração, sistema usado, como os exercícios são sorteados, se há níveis, o que é permitido levar, se há acesso a internet ou ao `man`) **pode variar por campus e edição. Confirme com a 42SP.**

## Como simular

1. Escolha uma simulação e marque o tempo sugerido num cronômetro.
2. **Sem internet, sem anotações, sem abrir `01-exemplos/` nem `03-respostas/`.** Só o terminal, o editor e o `man`.
3. Faça os exercícios **na ordem**. Em muitos formatos de exame, você só avança depois de passar no anterior; simule isso: não pule.
4. Escreva em `minha-versao/exames/` (qualquer subpasta serve) e só rode `./run.sh <nome>` quando achar que terminou o exercício. Trate cada execução como uma "entrega": se falhar, anote e corrija, mas conte quantas tentativas usou.
5. No fim, compare com `03-respostas/` e anote o que errou.

> Dica de exame: testar sem `run.sh` faz parte do treino. Escreva seu próprio `main.c` rapidinho para cada função. Na hora do exame real, você provavelmente não vai ter o `run.sh` deste repositório.

| Simulação | Tempo | Exercícios |
|---|---|---|
| [Exame 01](exame-01.md) | 30 min | `ft_print_reverse_alphabet`, `ft_strlen`, `ft_swap`, `ft_strrev` |
| [Exame 02](exame-02.md) | 40 min | `ft_str_is_alpha`, `ft_strcmp`, `ft_putnbr`, `ft_range` |
| [Exame 03](exame-03.md) | 45 min | `ft_power`, `ft_strdup`, `ft_atoi`, `ft_strjoin` |
| [Exame 04](exame-04.md) | 40 min | só programas: `ft_last_arg`, `ft_show_args`, `ft_rev_args`, `ft_sort_args` |

Os exercícios novos (que não estão nos módulos) são `ft_print_reverse_alphabet`, `ft_str_is_alpha`, `ft_atoi` e `ft_last_arg`. As respostas deles estão em [`03-respostas/exames/`](../../03-respostas/exames/).
