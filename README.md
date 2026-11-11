# c-for-non-begginers — C para quem já programa

Material de estudo de C (e shell) para quem **já programa** em outra linguagem. O foco é o que é específico de C: sintaxe, o motivo de ela ser assim e como a memória funciona. Lógica de programação não é explicada.

📱 **Site para estudar no celular:** https://c-for-non-begginers.vercel.app

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
