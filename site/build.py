#!/usr/bin/env python3
"""Gera o site estatico em docs/ a partir dos .md e do codigo do repositorio.

Uso: python3 site/build.py

Cada pasta da raiz que tem um trilha.json vira uma "trilha" (uma aba no site).
O site nao tem backend: e HTML + CSS + JS, publicado pela Vercel.
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
        return os.path.dirname(rel)
    return rel[:-3]


def titulo_md(texto, padrao):
    m = re.search(r"^# (.+)$", texto, re.M)
    return m.group(1) if m else padrao


def carregar():
    paginas = {}
    codigos = {}
    for rel in arquivos():
        ext = os.path.splitext(rel)[1]
        texto = open(os.path.join(RAIZ, rel), encoding="utf-8").read()
        if ext == ".md":
            paginas[rel] = texto
        elif ext in EXT_CODIGO and os.path.basename(rel) != "trilha.json":
            codigos[rel] = {"lang": EXT_CODIGO[ext], "texto": texto}
    return paginas, codigos


def achar_trilhas():
    trilhas = []
    for d in sorted(os.listdir(RAIZ)):
        cfg = os.path.join(RAIZ, d, "trilha.json")
        if d not in IGNORAR and os.path.isfile(cfg):
            t = json.load(open(cfg, encoding="utf-8"))
            t["id"] = d
            trilhas.append(t)
    return trilhas


def extras_da_piscine(local, pasta_local, prefixo, paginas, codigos):
    """Links extras nas paginas que seguem o formato aulas/exercicios/respostas."""
    extras = []
    p = prefixo + "/"
    if pasta_local.startswith("01-exemplos/") and pasta_local.count("/") == 1:
        fs = [c for c in codigos if c.startswith(p + pasta_local + "/")]
        if fs:
            extras.append("\n\n---\n\n## Arquivos desta aula\n")
            extras += ["- [`%s`](#/arquivo/%s)" % (c[len(p + pasta_local) + 1:], c)
                       for c in fs]
    if pasta_local.startswith("02-exercicios/") and pasta_local != "02-exercicios/exames":
        mod = pasta_local.split("/")[1]
        resp = sorted(x for x in paginas
                      if x.startswith(p + "03-respostas/%s/" % mod))
        if resp:
            extras.append("\n\n---\n\n## Respostas deste módulo\n")
            extras.append("Tente antes de abrir.\n")
            extras += ["- [%s](#/%s)" % (
                titulo_md(paginas[x], x).replace("Resposta — ", ""), id_da_pagina(x))
                for x in resp]
    if pasta_local.startswith("03-respostas/") and pasta_local.count("/") == 2:
        fonte = [c for c in codigos if c.startswith(p + pasta_local + "/")]
        if fonte:
            fn = os.path.splitext(os.path.basename(fonte[0]))[0]
            t = [c for c in codigos if c.startswith(p + "testes/%s/" % fn)]
            if t:
                extras.append("\n\n---\n\n## Teste usado pelo `run.sh`\n")
                extras += ["- [`%s`](#/arquivo/%s)" % (c[len(p):], c) for c in t]
    return extras


def nav_piscine(pre, pags):
    def tit(pid):
        return pags[pid]["titulo"]

    def curto(pid):
        t = re.sub(r"^Aula \d+ — ", "", tit(pid))
        return re.sub(r"^Resposta — ", "", t)

    aulas = sorted(p for p in pags if re.match(r"^" + pre + r"/01-exemplos/\d\d-", p))
    mods = ["shell00", "c00-basico", "c01-ponteiros", "c02-strings",
            "c03-memoria", "c04-recursao"]
    nav = [
        {"grupo": "Começo", "itens": [
            {"id": pre, "titulo": "Visão geral e plano de 7 dias"},
            {"id": pre + "/ferramentas", "titulo": "Ferramentas"},
            {"id": pre + "/testes", "titulo": "Como os testes funcionam"},
            {"id": pre + "/03-respostas", "titulo": "Índice das respostas"},
        ]},
        {"grupo": "Aulas", "itens": [
            {"id": pre + "/01-exemplos", "titulo": "Índice das aulas"}] + [
            {"id": p, "titulo": "%s · %s" % (p.split("/")[2][:2], curto(p))}
            for p in aulas]},
        {"grupo": "Exercícios", "itens": [
            {"id": pre + "/02-exercicios", "titulo": "Como fazer"}] + [
            {"id": pre + "/02-exercicios/" + m,
             "titulo": tit(pre + "/02-exercicios/" + m).split(" — ")[0]}
            for m in mods] + [
            {"id": pre + "/02-exercicios/exames", "titulo": "Simulações de exame"}] + [
            {"id": pre + "/02-exercicios/exames/exame-0%d" % i,
             "titulo": "Exame 0%d" % i} for i in (1, 2, 3)]},
    ]
    for mod in mods + ["exames"]:
        ids = sorted(p for p in pags if p.startswith(pre + "/03-respostas/%s/" % mod))
        nav.append({"grupo": "Respostas · " + mod, "fechado": True,
                    "itens": [{"id": p, "titulo": curto(p).split(": ")[-1]}
                              for p in ids]})
    return nav


def nav_generica(pre, pags):
    """Menu para trilhas novas: um grupo por subpasta, em ordem alfabetica."""
    nav = [{"grupo": "Começo", "itens": [{"id": pre, "titulo": "Visão geral"}]}]
    subpastas = sorted({p.split("/")[1] for p in pags
                        if p.startswith(pre + "/") and p.count("/") >= 1})
    for sp in subpastas:
        base = pre + "/" + sp
        ids = sorted(p for p in pags if p == base or p.startswith(base + "/"))
        if not ids:
            continue
        grupo = pags[base]["titulo"] if base in pags else sp
        nav.append({"grupo": re.sub(r"^\d+[-_ ]*", "", grupo),
                    "itens": [{"id": p, "titulo": pags[p]["titulo"]} for p in ids]})
    return nav


def main():
    paginas, codigos = carregar()
    trilhas = achar_trilhas()
    ids_trilha = {t["id"] for t in trilhas}

    def resolve(md_rel, link):
        if re.match(r"^(https?:|mailto:|#)", link):
            return link
        alvo = link.partition("#")[0]
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

    saida = {}
    for rel, texto in paginas.items():
        pid = id_da_pagina(rel)
        trilha = rel.split("/")[0] if rel.split("/")[0] in ids_trilha else ""
        texto_links = re.sub(r"\]\(([^)\s]+)\)",
                             lambda m: "](" + resolve(rel, m.group(1)) + ")", texto)
        extras = []
        pasta_local = ""
        if trilha:
            pasta_local = os.path.dirname(rel)[len(trilha) + 1:]
            extras = extras_da_piscine(rel, pasta_local, trilha, paginas, codigos)
        saida[pid] = {
            "titulo": titulo_md(texto, pid),
            "md": texto_links + "\n".join(extras),
            "resposta": pasta_local.startswith("03-respostas/") and pasta_local.count("/") >= 2,
            "trilha": trilha,
        }

    for t in trilhas:
        if os.path.isdir(os.path.join(RAIZ, t["id"], "01-exemplos")):
            t["nav"] = nav_piscine(t["id"], saida)
        else:
            t["nav"] = nav_generica(t["id"], saida)
        for g in t["nav"]:
            for it in g["itens"]:
                it["titulo"] = it["titulo"].replace("`", "")

    conteudo = {"paginas": saida, "arquivos": codigos, "trilhas": trilhas,
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
    print("site gerado em docs/ (versao %s): %d trilha(s), %d paginas, %d arquivos de codigo"
          % (versao, len(trilhas), len(saida), len(codigos)))


if __name__ == "__main__":
    main()
