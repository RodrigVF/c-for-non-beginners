# Ferramentas

## `cabecalho.py`

A `norminette` exige o cabeçalho da 42 no topo de cada arquivo. Este script coloca um no formato padrão:

```bash
python3 ferramentas/cabecalho.py minha-versao/c00/ex00/ft_putchar.c
```

Para usar seu login em vez de `seu_login`:

```bash
LOGIN_42=meulogin python3 ferramentas/cabecalho.py arquivo.c
```

Alternativas:
- No VS Code, há extensões que geram esse cabeçalho (procure por "42 Header" no marketplace).
- Nos computadores da 42, o vim costuma ter o comando `:Stdheader` (confirme com a 42SP).
