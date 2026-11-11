#!/bin/sh
# Teste do programa ft_last_arg (exame 04). Uso: sh teste.sh caminho/ft_last_arg.c
. "$(dirname "$0")/../programa.sh"
compila ft_last_arg "$1"
confere "sem argumentos: so a quebra de linha" '\n'
confere "um argumento" 'um\n' um
confere "varios" 'tres\n' um dois tres
confere "ultimo vazio" '\n' x ""
fim
