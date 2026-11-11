#!/bin/sh
# Funções comuns aos testes de PROGRAMAS (exercícios com main própria).
# Uso dentro de um teste.sh:
#   . "$(dirname "$0")/../programa.sh"
#   compila ft_show_args "$1"
#   confere "descricao" "saida esperada (formato do printf)" arg1 arg2 ...
#   fim

ERROS=0
DIR=$(mktemp -d)

compila() {
	NOME="$1"
	SRC="$(realpath "$2")"
	if ! cc -Wall -Wextra -Werror "$SRC" -o "$DIR/$NOME" 2>"$DIR/cc.txt"; then
		echo "KO: nao compila com -Wall -Wextra -Werror:"
		sed 's/^/    /' "$DIR/cc.txt"
		rm -rf "$DIR"
		exit 1
	fi
}

confere() {
	DESC="$1"
	ESPERADO=$(printf "$2"; echo x)
	shift 2
	SAIDA=$(cd "$DIR" && "./$NOME" "$@"; echo x)
	if [ "$SAIDA" = "$ESPERADO" ]; then
		echo "OK: $DESC"
	else
		echo "KO: $DESC"
		echo "    esperado: [$(printf '%s' "${ESPERADO%x}" | sed -n 'l' | tr -d '\n')]"
		echo "    obtido:   [$(printf '%s' "${SAIDA%x}" | sed -n 'l' | tr -d '\n')]"
		ERROS=1
	fi
}

fim() {
	rm -rf "$DIR"
	exit $ERROS
}
