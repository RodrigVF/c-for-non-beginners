#!/bin/sh
# Teste do exercicio ola.sh (shell00/ex00). Uso: sh teste.sh caminho/ola.sh
SCRIPT="$1"
ERROS=0
if [ "$(stat -c %a "$SCRIPT")" != "755" ]; then
	echo "KO: permissoes de ola.sh sao $(stat -c %a "$SCRIPT"), esperado 755"
	ERROS=1
fi
SAIDA=$("$SCRIPT" 2>&1)
if [ "$SAIDA" != "Ola, Piscine!" ]; then
	echo "KO: saida foi [$SAIDA], esperado [Ola, Piscine!]"
	ERROS=1
fi
[ $ERROS -eq 0 ] && echo "OK: permissoes 755 e saida correta"
exit $ERROS
