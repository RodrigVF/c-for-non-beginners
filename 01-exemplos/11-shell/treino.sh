#!/bin/sh
# Cria uma pasta "sandbox" com arquivos para treinar os comandos da aula 11.
# Uso: sh treino.sh      (depois: cd sandbox)
# Para recomecar: rm -rf sandbox && sh treino.sh

mkdir -p sandbox/projeto/src sandbox/projeto/docs
cd sandbox || exit 1
printf 'INFO servidor iniciado\nERRO disco cheio\nINFO usuario entrou\n' > log.txt
printf 'ERRO conexao perdida\nAVISO memoria alta\nERRO timeout\n' >> log.txt
printf 'ana\nbruno\ncarla\nana\ndaniel\n' > nomes.txt
printf '#include <unistd.h>\n' > projeto/src/main.c
touch projeto/src/ft_putchar.c projeto/src/ft_strlen.c projeto/docs/notas.md
printf '#!/bin/sh\necho "eu sou um script"\n' > script.sh
chmod 644 script.sh
echo "Pronto! Entre com: cd sandbox"
