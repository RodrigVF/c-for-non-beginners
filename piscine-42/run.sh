#!/bin/bash
# run.sh - compila e testa um exercicio pelo nome.
#
# Uso:
#   ./run.sh ft_strlen              testa a SUA versao (procura em minha-versao/)
#   ./run.sh ft_strlen --resposta   testa a versao de 03-respostas/
#   ./run.sh --todos                testa todos os exercicios (sua versao)
#   ./run.sh --todos --resposta     testa todas as respostas
#   ./run.sh --lista                lista os exercicios disponiveis

RAIZ="$(cd "$(dirname "$0")" && pwd)"
TESTES="$RAIZ/testes"
FLAGS="-Wall -Wextra -Werror"
VERDE=$'\033[32m'; VERMELHO=$'\033[31m'; AMARELO=$'\033[33m'; FIM=$'\033[0m'

ok()    { echo "  ${VERDE}OK${FIM}    $1"; }
erro()  { echo "  ${VERMELHO}ERRO${FIM}  $1"; }
aviso() { echo "  ${AMARELO}AVISO${FIM} $1"; }

acha_arquivo() {
	local base="$1" nome="$2" achados
	achados=$(find "$base" \( -name "$nome.c" -o -name "$nome.sh" \) \
		-not -path "*/testes/*" 2>/dev/null)
	if [ "$(echo "$achados" | grep -c .)" -gt 1 ]; then
		aviso "mais de um arquivo encontrado, usando o primeiro:" >&2
		echo "$achados" | sed 's/^/          /' >&2
	fi
	echo "$achados" | head -n 1
}

testa_norma() {
	if ! command -v norminette >/dev/null 2>&1; then
		aviso "norminette nao instalada: Norma nao verificada"
		return 0
	fi
	local saida
	saida=$(norminette "$1" 2>&1)
	if echo "$saida" | grep -q "Error"; then
		erro "Norma:"; echo "$saida" | grep -v "OK!" | sed 's/^/          /'
		return 1
	fi
	ok "Norma (norminette)"
}

testa_c() {
	local nome="$1" src="$2" dir="$TESTES/$1" tmp bin st
	tmp=$(mktemp -d); bin="$tmp/$nome"
	if ! cc $FLAGS -g "$src" "$dir/main.c" -o "$bin" 2>"$tmp/cc.txt"; then
		erro "compilacao (cc $FLAGS):"; sed 's/^/          /' "$tmp/cc.txt"
		rm -rf "$tmp"; return 1
	fi
	ok "compilacao com $FLAGS"
	timeout 5 "$bin" >"$tmp/saida.txt" 2>&1; st=$?
	if [ $st -eq 139 ]; then erro "segmentation fault (exit 139)"; rm -rf "$tmp"; return 1; fi
	if [ $st -eq 124 ]; then erro "timeout: loop infinito?"; rm -rf "$tmp"; return 1; fi
	if ! diff -u "$dir/esperado.txt" "$tmp/saida.txt" >"$tmp/diff.txt"; then
		erro "saida diferente do esperado (- esperado, + sua saida):"
		tail -n +3 "$tmp/diff.txt" | sed 's/^/          /'
		rm -rf "$tmp"; return 1
	fi
	ok "saida igual a esperada"
	if grep -q "malloc" "$src" && command -v valgrind >/dev/null 2>&1; then
		if valgrind -q --leak-check=full --errors-for-leak-kinds=all \
			--error-exitcode=42 "$bin" >/dev/null 2>"$tmp/vg.txt"; then
			ok "valgrind: sem leaks nem erros de memoria"
		else
			erro "valgrind encontrou problemas:"; sed 's/^/          /' "$tmp/vg.txt"
			rm -rf "$tmp"; return 1
		fi
	fi
	rm -rf "$tmp"
}

testa_um() {
	local nome="${1%.c}" base="$2" src r=0
	nome="${nome%.sh}"
	echo "== $nome"
	if [ ! -d "$TESTES/$nome" ]; then
		erro "nao existe teste para '$nome'. Veja ./run.sh --lista"; return 1
	fi
	src=$(acha_arquivo "$base" "$nome")
	if [ -z "$src" ]; then
		erro "nao achei $nome.c nem $nome.sh dentro de ${base#$RAIZ/}/"
		return 1
	fi
	echo "  arquivo: ${src#$RAIZ/}"
	if [ -f "$TESTES/$nome/teste.sh" ]; then
		if sh "$TESTES/$nome/teste.sh" "$src" | sed 's/^/  /'; [ "${PIPESTATUS[0]}" -eq 0 ]; then
			ok "testes do $( [ "${src##*.}" = "c" ] && echo programa || echo script)"
		else
			r=1
		fi
		if [ "${src##*.}" = "c" ]; then
			testa_norma "$src" || r=1
		fi
	else
		testa_c "$nome" "$src" || r=1
		testa_norma "$src" || r=1
	fi
	return $r
}

BASE="$RAIZ/minha-versao"
ARGS=()
for a in "$@"; do
	if [ "$a" = "--resposta" ]; then BASE="$RAIZ/03-respostas"; else ARGS+=("$a"); fi
done

case "${ARGS[0]}" in
	""|-h|--help)
		sed -n '2,9p' "$0" | sed 's/^# \{0,1\}//'; exit 0 ;;
	--lista)
		ls "$TESTES" | grep -v '\.' ; exit 0 ;;
	--todos)
		total=0; falhas=0; lista_falhas=""
		for d in "$TESTES"/*/; do
			n=$(basename "$d"); total=$((total + 1))
			if ! testa_um "$n" "$BASE"; then
				falhas=$((falhas + 1)); lista_falhas="$lista_falhas $n"
			fi
		done
		echo
		echo "Resultado: $((total - falhas))/$total passaram."
		[ $falhas -gt 0 ] && echo "Falharam:$lista_falhas"
		[ $falhas -eq 0 ]; exit $? ;;
	*)
		testa_um "${ARGS[0]}" "$BASE"; exit $? ;;
esac
