# c-for-non-begginers — C para quem já programa

Material de estudo de C (e shell) para quem **já programa** em outra linguagem. O foco é o que é específico de C: sintaxe, o motivo de ela ser assim e como a memória funciona. Lógica de programação não é explicada.

📱 **Site para estudar no celular:** https://c-for-non-begginers.vercel.app

> ⚠️ **Não oficial.** Este é um projeto independente, sem vínculo com a 42, a 42 São Paulo ou a 42 Network. Os exercícios são recriações no estilo da Piscine, não os subjects oficiais.
>
> 🔓 **Open-source.** Código sob [MIT](LICENSE) e textos sob [CC BY 4.0](LICENSE-CONTEUDO.md). Contribuições são bem-vindas: veja [CONTRIBUTING.md](CONTRIBUTING.md).

## Trilhas

O conteúdo é organizado em **trilhas**. Cada trilha é uma pasta na raiz do repositório e vira uma **aba** no site.

| Trilha | Pasta | Conteúdo |
|---|---|---|
| Preparação Piscine 42 | [`piscine-42/`](piscine-42/) | 13 aulas, exercícios no estilo da Piscine da 42SP, 3 simulados, respostas comentadas e testes automáticos (`run.sh`) |

## Estrutura

```
c-for-non-begginers/
├── README.md         ← você está aqui
├── piscine-42/       ← trilha "Preparação Piscine 42" (tem o próprio README)
├── site/             ← código do site e o gerador (build.py)
├── docs/             ← site pronto, gerado (não edite à mão)
├── vercel.json       ← configuração da Vercel
├── LICENSE           ← licença MIT (código)
├── LICENSE-CONTEUDO.md ← licença CC BY 4.0 (textos)
├── CONTRIBUTING.md   ← como contribuir
└── .vscode/          ← configuração do editor (tabs, régua de 80 colunas)
```

## Como adicionar uma trilha nova

1. Crie uma pasta na raiz, por exemplo `ponteiros-avancados/`.
2. Dentro dela, crie um `trilha.json`:

```json
{
  "titulo": "Ponteiros avançados",
  "curto": "Ponteiros",
  "emoji": "🧭",
  "descricao": "Uma frase sobre a trilha."
}
```

3. Escreva um `README.md` (a página inicial da trilha) e organize o resto em subpastas, cada uma com o seu `README.md`. Exemplos de código (`.c`, `.h`, `.sh`) ao lado dos textos aparecem no site com realce de sintaxe.
4. Gere o site de novo (veja abaixo). A trilha aparece como uma aba nova, com o menu montado a partir das pastas, em ordem alfabética (use prefixos como `01-`, `02-` para controlar a ordem).

## O site

O site é **estático** (HTML, CSS e JavaScript, sem backend e sem framework). Ele tem abas por trilha, menu, busca, respostas escondidas até você tocar, marcação de "estudado" (guardada no seu navegador), tamanho de letra ajustável, tema escuro e funciona offline depois da primeira visita.

O botão "Apoie o projeto", o aviso de "não oficial" e o texto da licença que aparecem no rodapé do site ficam em [`site/config.json`](site/config.json). O botão do site só leva para a seção [Apoie o projeto](#apoie-o-projeto) deste README; as formas de apoio ficam aqui no GitHub.

Depois de editar qualquer `.md` ou exemplo, gere o site e faça commit da pasta `docs/`:

```bash
python3 site/build.py
```

Para ver localmente:

```bash
python3 -m http.server 8000 --directory docs
```

**Vercel:** o [`vercel.json`](vercel.json) diz que não há framework e que os arquivos prontos estão em `docs/`. Para cada push publicar sozinho, conecte o repositório na Vercel (Settings → Git).

Se um deploy aparecer como **Blocked** com a mensagem *"the commit author doesn't have permission"*, a Vercel não reconheceu o email dos commits como seu. Para resolver de vez, conecte a sua conta do GitHub à Vercel (Account Settings → Authentication). Enquanto isso, dá para publicar o site pronto a partir de uma pasta sem git:

```bash
python3 site/build.py
rm -rf /tmp/cfnb-deploy && mkdir /tmp/cfnb-deploy
cp -r docs vercel.json .vercel /tmp/cfnb-deploy/
cd /tmp/cfnb-deploy && npx vercel deploy --prod
```

## Apoie o projeto

Este material é gratuito e open-source. Se ele te ajudou, você pode apoiar de várias formas:

- ⭐ **Dê uma estrela** no repositório (botão *Star*, no topo desta página). Isso ajuda outras pessoas a encontrar o material.
- 🤝 **Contribua** com correções, explicações melhores, exercícios ou trilhas novas. Veja o [CONTRIBUTING.md](CONTRIBUTING.md).
- 🐛 **Avise sobre erros** abrindo uma [issue](https://github.com/RodrigVF/c-for-non-begginers/issues).
- 📣 **Compartilhe** com quem está se preparando para a Piscine.

## Licença

- **Código** (`.c`, `.h`, `.sh`, `.py`, `.js`, `.css`, `.html`): [MIT](LICENSE).
- **Textos** (aulas, enunciados, explicações): [CC BY 4.0](LICENSE-CONTEUDO.md). Pode copiar e adaptar, desde que dê o crédito.

"42" é marca de seus respectivos donos e aparece aqui só para indicar o assunto do material.

