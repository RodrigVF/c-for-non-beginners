# Como contribuir

Este projeto é **open-source** e aceita contribuições: correções de texto, explicações melhores, exercícios novos ou trilhas inteiras.

## Antes de abrir um pull request

1. **Código C** segue a Norma da 42 e compila com `cc -Wall -Wextra -Werror`. Se a `norminette` estiver instalada, rode-a nos arquivos que mudou.
2. **Exercícios da trilha `piscine-42/`** precisam de teste em `piscine-42/testes/<nome>/`. Confira com:
   ```bash
   cd piscine-42 && ./testes/rodar_todos.sh --resposta
   ```
3. **Site:** gere de novo e inclua a pasta `docs/` no commit:
   ```bash
   python3 site/build.py
   ```
4. **Nada de conteúdo oficial da 42.** Não copie subjects, exames ou materiais da 42: escreva exercícios próprios, no estilo da Piscine, e marque como recriação.

## Licença das contribuições

Ao contribuir, você concorda que o seu código fica sob a licença [MIT](LICENSE) e os seus textos sob a [CC BY 4.0](LICENSE-CONTEUDO.md), como o resto do projeto.
