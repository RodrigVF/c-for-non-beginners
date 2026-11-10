#!/usr/bin/env python3
"""Coloca o cabecalho da 42 no topo de arquivos .c/.h (se ainda nao tiverem).

Uso:
    python3 ferramentas/cabecalho.py arquivo.c [outro.c ...]
    LOGIN=meulogin python3 ferramentas/cabecalho.py arquivo.c

Sem LOGIN, usa "seu_login". Na 42 voce vai usar o gerador de la
(no vim, o comando :Stdheader); este script so imita o formato.
"""
import os
import sys
import time

ART = ["        :::      ::::::::",
       "      :+:      :+:    :+:",
       "    +:+ +:+         +:+  ",
       "  +#+  +:+       +#+     ",
       "+#+#+#+#+#+   +#+        ",
       "     #+#    #+#          ",
       "    ###   ########.fr    "]


def linha(esq, dir_):
    esq = esq[:80 - 10 - len(dir_)]
    return "/*   " + esq + " " * (70 - len(esq) - len(dir_)) + dir_ + "   */"


def cabecalho(nome, login):
    data = time.strftime("%Y/%m/%d %H:%M:%S")
    mail = "%s@student.42sp.org.br" % login
    s = "/* " + "*" * 74 + " */"
    b = "/*" + " " * 76 + "*/"
    ls = [s, b, linha("", ART[0]), linha(nome, ART[1]), linha("", ART[2]),
          linha("By: %s <%s>" % (login, mail), ART[3]), linha("", ART[4]),
          linha("Created: %s by %s" % (data, login), ART[5]),
          linha("Updated: %s by %s" % (data, login), ART[6]), b, s]
    return "\n".join(ls) + "\n\n"


def main():
    login = os.environ.get("LOGIN_42", os.environ.get("LOGIN", "seu_login"))
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    for caminho in sys.argv[1:]:
        with open(caminho) as f:
            texto = f.read()
        if texto.startswith("/* ****"):
            print("ja tem cabecalho: " + caminho)
            continue
        with open(caminho, "w") as f:
            f.write(cabecalho(os.path.basename(caminho), login) + texto)
        print("cabecalho adicionado: " + caminho)
    return 0


if __name__ == "__main__":
    sys.exit(main())
