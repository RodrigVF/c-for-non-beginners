#!/bin/sh
# Teste do programa ft_show_args (c05/ex01). Uso: sh teste.sh caminho/ft_show_args.c
. "$(dirname "$0")/../programa.sh"
compila ft_show_args "$1"
confere "sem argumentos: nao imprime nada" ''
confere "um argumento" 'a\n' a
confere "varios, com espaco e vazio" 'Ola\nPiscine 42\n\n' Ola "Piscine 42" ""
fim
