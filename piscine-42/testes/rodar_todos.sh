#!/bin/sh
# Roda todos os testes. Sem argumentos: testa minha-versao/.
# Com --resposta: testa as solucoes de 03-respostas/.
exec "$(dirname "$0")/../run.sh" --todos "$@"
