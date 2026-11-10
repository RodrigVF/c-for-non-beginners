#!/bin/sh
# Teste do exercicio conta_erros.sh (shell00/ex02).
SCRIPT="$(realpath "$1")"
ERROS=0
confere() {
	SAIDA=$(printf "$1" | sh "$SCRIPT")
	if [ "$SAIDA" = "$2" ]; then echo "OK: $3 -> $SAIDA"
	else echo "KO: $3 -> [$SAIDA], esperado [$2]"; ERROS=1; fi
}
confere "INFO inicio\nERRO disco cheio\nAVISO memoria\nERRO rede\nerro minusculo\nINFO ERRO no meio\n" 3 "log com 3 ERROs"
confere "INFO tudo certo\nAVISO nada grave\n" 0 "log sem ERRO"
confere "" 0 "entrada vazia"
exit $ERROS
