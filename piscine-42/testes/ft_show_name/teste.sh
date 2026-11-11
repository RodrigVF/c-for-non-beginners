#!/bin/sh
# Teste do programa ft_show_name (c05/ex00). Uso: sh teste.sh caminho/ft_show_name.c
. "$(dirname "$0")/../programa.sh"
compila ft_show_name "$1"
confere "sem argumentos" './ft_show_name\n'
confere "com argumentos (continua mostrando so o nome)" './ft_show_name\n' um dois
fim
