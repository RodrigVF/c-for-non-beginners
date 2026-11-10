#!/bin/sh
# Teste do exercicio permissoes.sh (shell00/ex01). Roda o script numa pasta vazia.
SCRIPT="$(realpath "$1")"
DIR=$(mktemp -d)
ERROS=0
(cd "$DIR" && sh "$SCRIPT")
confere() {
	if [ ! -e "$DIR/$1" ]; then
		echo "KO: $1 nao foi criado"; ERROS=1; return
	fi
	if [ ! "$3" "$DIR/$1" ]; then
		echo "KO: $1 tem o tipo errado (arquivo/pasta)"; ERROS=1
	fi
	P=$(stat -c %a "$DIR/$1")
	if [ "$P" = "$2" ]; then echo "OK: $1 -> $P"
	else echo "KO: $1 -> $P, esperado $2"; ERROS=1; fi
}
confere publico.txt 644 -f
confere privado.txt 600 -f
confere script_vazio.sh 755 -f
confere pasta 750 -d
rm -rf "$DIR"
exit $ERROS
