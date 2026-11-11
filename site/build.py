#!/usr/bin/env python3
"""Gera o site estatico em docs/ a partir dos .md e do codigo do repositorio.

Uso: python3 site/build.py
O site nao tem backend: e HTML + CSS + JS, publicado pelo GitHub Pages.
"""
import hashlib
import json
import os
import re
import shutil

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SITE = os.path.join(RAIZ, "site")
SAIDA = os.path.join(RAIZ, "docs")
REPO = "https://github.com/RodrigVF/c-for-non-begginers"
IGNORAR = {".git", "docs", "site", ".vercel", "node_modules"}
EXT_CODIGO = {".c": "c", ".h": "c", ".sh": "bash", ".py": "python",
              ".txt": "plaintext", ".json": "json"}


def arquivos():
    for pasta, dirs, nomes in os.walk(RAIZ):
        dirs[:] = sorted(d for d in dirs if d not in IGNORAR)
        for n in sorted(x for x in nomes if not x.startswith(".env")):
            yield os.path.relpath(os.path.join(pasta, n), RAIZ)


def id_da_pagina(rel):
    if os.path.basename(rel) == "README.md":
        d = os.path.dirname(rel)
        return d
    return rel[:-3]


def main():
    paginas = {}
    codigos = {}
    for rel in arquivos():
        ext = os.path.splitext(rel)[1]
        texto = open(os.path.join(RAIZ, rel), encoding="utf-8").read()
        if ext == ".md":
            paginas[rel] = texto
        elif ext in EXT_CODIGO:
            codigos[rel] = {"lang": EXT_CODIGO[ext], "texto": texto}

    def resolve(md_rel, link):
        if re.match(r"^(https?:|mailto:|#)", link):
            return link
        alvo, _, ancora = link.partition("#")
        p = os.path.normpath(os.path.join(os.path.dirname(md_rel), alvo))
        if p == ".":
            p = ""
        if p in paginas:
            return "#/" + id_da_pagina(p)
        leia = os.path.join(p, "README.md") if p else "README.md"
        if leia in paginas:
            return "#/" + id_da_pagina(leia)
        if p in codigos:
            return "#/arquivo/" + p
        if os.path.isdir(os.path.join(RAIZ, p)):
            return REPO + "/tree/main/" + p
        return REPO + "/blob/main/" + p

    saida_paginas = {}
    for rel, texto in paginas.items():
        pid = id_da_pagina(rel)
        titulo = re.search(r"^# (.+)$", texto, re.M)
        titulo = titulo.group(1) if titulo else pid
        texto = re.sub(r"\]\(([^)\s]+)\)",
                       lambda m: "](" + resolve(rel, m.group(1)) + ")", texto)
        pasta = os.path.dirname(rel)
        extras = []
        if pasta.startswith("01-exemplos/") and pasta.count("/") == 1:
            fs = [c for c in codigos if c.startswith(pasta + "/")]
            if fs:
                extras.append("\n\n---\n\n## Arquivos desta aula\n")
                extras += ["- [`%s`](#/arquivo/%s)" % (c[len(pasta) + 1:], c)
                           for c in fs]
        if pasta.startswith("02-exercicios/") and pasta != "02-exercicios/exames":
            mod = pasta.split("/")[1]
            resp = sorted(p for p in paginas
                          if p.startswith("03-respostas/%s/" % mod))
            if resp:
                extras.append("\n\n---\n\n## Respostas deste módulo\n")
                extras.append("Tente antes de abrir.\n")
                extras += ["- [%s](#/%s)" % (
                    re.search(r"^# (.+)$", paginas[p], re.M).group(1)
                    .replace("Resposta — ", ""), id_da_pagina(p))
                    for p in resp]
        if pasta.startswith("03-respostas/") and pasta.count("/") == 2:
            nome = [c for c in codigos if c.startswith(pasta + "/")]
            if nome:
                fn = os.path.splitext(os.path.basename(nome[0]))[0]
                t = [c for c in codigos if c.startswith("testes/%s/" % fn)]
                if t:
                    extras.append("\n\n---\n\n## Teste usado pelo `run.sh`\n")
                    extras += ["- [`%s`](#/arquivo/%s)" % (c, c) for c in t]
        saida_paginas[pid] = {
            "titulo": titulo,
            "md": texto + "\n".join(extras),
            "resposta": pasta.startswith("03-respostas/") and pasta.count("/") >= 2,
            "fonte": rel,
        }

    def tit(pid):
        return saida_paginas[pid]["titulo"]

    def curto(pid):
        t = tit(pid)
        t = re.sub(r"^Aula \d+ — ", "", t)
        t = re.sub(r"^Resposta — ", "", t)
        return t

    aulas = sorted(p for p in saida_paginas
                   if re.match(r"^01-exemplos/\d\d-", p))
    nav = [
        {"grupo": "Começo", "itens": [
            {"id": "", "titulo": "Visão geral e plano de 7 dias"},
            {"id": "ferramentas", "titulo": "Ferramentas"},
            {"id": "testes", "titulo": "Como os testes funcionam"},
        ]},
        {"grupo": "Aulas", "itens": [
            {"id": "01-exemplos", "titulo": "Índice das aulas"}] + [
            {"id": p, "titulo": "%s · %s" % (p[12:14], curto(p))}
            for p in aulas]},
        {"grupo": "Exercícios", "itens": [
            {"id": "02-exercicios", "titulo": "Como fazer"}] + [
            {"id": "02-exercicios/" + m, "titulo": tit("02-exercicios/" + m)
             .split(" — ")[0]}
            for m in ["shell00", "c00-basico", "c01-ponteiros",
                      "c02-strings", "c03-memoria", "c04-recursao"]] + [
            {"id": "02-exercicios/exames", "titulo": "Simulações de exame"}] + [
            {"id": "02-exercicios/exames/exame-0%d" % i,
             "titulo": "Exame 0%d" % i} for i in (1, 2, 3)]},
    ]
    for mod in ["shell00", "c00-basico", "c01-ponteiros", "c02-strings",
                "c03-memoria", "c04-recursao", "exames"]:
        ids = sorted(p for p in saida_paginas
                     if p.startswith("03-respostas/%s/" % mod))
        nav.append({"grupo": "Respostas · " + mod, "fechado": True,
                    "itens": [{"id": p, "titulo": curto(p).split(": ")[-1]}
                              for p in ids]})
    nav[0]["itens"].append({"id": "03-respostas",
                            "titulo": "Índice das respostas"})

    for g in nav:
        for it in g["itens"]:
            it["titulo"] = it["titulo"].replace("`", "")
    conteudo = {"paginas": saida_paginas, "arquivos": codigos, "nav": nav,
                "repo": REPO}
    js = "window.CONTEUDO = " + json.dumps(conteudo, ensure_ascii=False) + ";\n"
    h = hashlib.sha1(js.encode())
    for n in sorted(os.listdir(SITE)):
        if n != "build.py":
            h.update(open(os.path.join(SITE, n), "rb").read())
    versao = h.hexdigest()[:10]

    if os.path.isdir(SAIDA):
        shutil.rmtree(SAIDA)
    os.makedirs(SAIDA)
    open(os.path.join(SAIDA, "conteudo.js"), "w", encoding="utf-8").write(js)
    for n in ["index.html", "app.js", "style.css", "sw.js", "icon.svg",
              "manifest.webmanifest"]:
        t = open(os.path.join(SITE, n), encoding="utf-8").read()
        t = t.replace("__VERSAO__", versao)
        open(os.path.join(SAIDA, n), "w", encoding="utf-8").write(t)
    open(os.path.join(SAIDA, ".nojekyll"), "w").close()
    print("site gerado em docs/ (versao %s): %d paginas, %d arquivos de codigo"
          % (versao, len(saida_paginas), len(codigos)))


if __name__ == "__main__":
    main()
