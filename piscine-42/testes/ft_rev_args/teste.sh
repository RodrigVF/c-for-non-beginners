#!/bin/sh
# Teste do programa ft_rev_args (c05/ex02). Uso: sh teste.sh caminho/ft_rev_args.c
. "$(dirname "$0")/../programa.sh"
compila ft_rev_args "$1"
confere "sem argumentos: nao imprime nada" ''
confere "um argumento" 'so\n' so
confere "tres argumentos" '3\n2\n1\n' 1 2 3
fim
