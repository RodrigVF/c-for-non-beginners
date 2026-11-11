#!/bin/sh
# Teste do exercicio lista_c.sh (shell00/ex03).
SCRIPT="$(realpath "$1")"
DIR=$(mktemp -d)
ERROS=0
mkdir "$DIR/sub"
touch "$DIR/main.c" "$DIR/ft_putchar.c" "$DIR/ft_strlen.c" "$DIR/ft.h" \
	"$DIR/notas.txt" "$DIR/velho.c.bak" "$DIR/sub/escondido.c"
SAIDA=$(cd "$DIR" && LC_ALL=C sh "$SCRIPT")
ESPERADO=$(printf "ft_putchar\nft_strlen\nmain")
if [ "$SAIDA" = "$ESPERADO" ]; then echo "OK: listou ft_putchar, ft_strlen, main"
else echo "KO: saida:"; echo "$SAIDA"; echo "esperado:"; echo "$ESPERADO"; ERROS=1; fi
rm -rf "$DIR"
exit $ERROS
