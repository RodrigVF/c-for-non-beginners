#!/bin/sh
# Teste do programa ft_sort_args (c05/ex03). Uso: sh teste.sh caminho/ft_sort_args.c
. "$(dirname "$0")/../programa.sh"
compila ft_sort_args "$1"
confere "sem argumentos: nao imprime nada" ''
confere "ja ordenados" 'a\nb\nc\n' a b c
confere "ordem ASCII (maiusculas antes)" '\nC\na\naa\nb\n' b a C aa ""
confere "repetidos" 'x\nx\ny\n' y x x
fim
