#!/bin/sh
# Teste do exercicio usuarios.sh (shell00/ex04).
SCRIPT="$(realpath "$1")"
ERROS=0
ENTRADA="root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
zelia:x:1002:1002::/home/zelia:/bin/bash
ana:x:1001:1001::/home/ana:/bin/bash
bruno:x:1003:1003::/home/bruno:/bin/zsh
carla:x:1004:1004::/home/carla:/bin/bash/falso"
SAIDA=$(printf "%s\n" "$ENTRADA" | LC_ALL=C sh "$SCRIPT")
ESPERADO=$(printf "ana\nroot\nzelia")
if [ "$SAIDA" = "$ESPERADO" ]; then echo "OK: ana, root, zelia"
else echo "KO: saida:"; echo "$SAIDA"; echo "esperado:"; echo "$ESPERADO"; ERROS=1; fi
exit $ERROS
