(function () {
  "use strict";

  var C = window.CONTEUDO;
  var el = function (id) { return document.getElementById(id); };
  var menu = el("menu");
  var fundo = el("fundo");
  var main = el("conteudo");
  var reveladas = {};

  function ler(chave, padrao) {
    try {
      var v = localStorage.getItem(chave);
      return v === null ? padrao : JSON.parse(v);
    } catch (e) { return padrao; }
  }
  function gravar(chave, valor) {
    try { localStorage.setItem(chave, JSON.stringify(valor)); } catch (e) { /* sem storage: tudo bem */ }
  }

  /* ---------- trilhas ---------- */
  var trilhas = C.trilhas;
  var porId = {};
  trilhas.forEach(function (t) {
    porId[t.id] = t;
    t.ordem = [];
    t.grupoDe = {};
    t.nav.forEach(function (g) {
      g.itens.forEach(function (it) {
        if (t.ordem.indexOf(it.id) < 0) t.ordem.push(it.id);
        if (!(it.id in t.grupoDe)) t.grupoDe[it.id] = g.grupo;
      });
    });
    t.aulas = t.ordem.filter(function (id) { return /\/01-exemplos\/\d\d-/.test(id); });
  });
  var PADRAO = trilhas.length ? trilhas[0].id : "";

  function trilhaDe(id) {
    if (C.paginas[id]) return porId[C.paginas[id].trilha] || null;
    return porId[String(id).split("/")[0]] || null;
  }

  /* migra o progresso salvo antes das abas existirem (ids sem o prefixo da trilha) */
  var feitos = ler("cfnb-feitos", {});
  (function () {
    var mudou = false;
    Object.keys(feitos).forEach(function (k) {
      if (C.paginas[k] && k !== "") return;
      var novo = k === "" ? PADRAO : PADRAO + "/" + k;
      if (C.paginas[novo]) { feitos[novo] = feitos[k]; }
      delete feitos[k];
      mudou = true;
    });
    if (mudou) gravar("cfnb-feitos", feitos);
  })();

  function tituloNav(id) {
    var t = trilhaDe(id);
    if (t) {
      for (var i = 0; i < t.nav.length; i++)
        for (var j = 0; j < t.nav[i].itens.length; j++)
          if (t.nav[i].itens[j].id === id) return t.nav[i].itens[j].titulo;
    }
    return C.paginas[id] ? C.paginas[id].titulo.replace(/`/g, "") : id;
  }

  function esc(s) {
    return String(s).replace(/[&<>"']/g, function (c) {
      return { "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[c];
    });
  }

  /* ---------- abas e menu ---------- */
  function desenharAbas(t) {
    var html = '<a class="aba' + (!t ? " ativa" : "") + '" href="#/">Início</a>';
    trilhas.forEach(function (x) {
      html += '<a class="aba' + (t && t.id === x.id ? " ativa" : "") + '" href="#/' + esc(x.id) + '">' +
        (x.emoji ? '<span aria-hidden="true">' + esc(x.emoji) + "</span> " : "") + esc(x.titulo) + "</a>";
    });
    el("abas").innerHTML = html;
  }

  function abrirMenu(abrir) {
    menu.classList.toggle("aberto", abrir);
    fundo.hidden = !abrir;
    el("btn-menu").setAttribute("aria-expanded", abrir ? "true" : "false");
    document.body.style.overflow = abrir ? "hidden" : "";
  }
  el("btn-menu").addEventListener("click", function () { abrirMenu(!menu.classList.contains("aberto")); });
  fundo.addEventListener("click", function () { abrirMenu(false); });
  document.addEventListener("keydown", function (e) { if (e.key === "Escape") abrirMenu(false); });

  function desenharMenu(atual, t) {
    var html = '<details class="grupo" open><summary>Trilhas</summary>' +
      '<a class="item' + (atual === "" ? " atual" : "") + '" href="#/"><span>Início</span></a>';
    trilhas.forEach(function (x) {
      html += '<a class="item' + (t && t.id === x.id && atual !== x.id ? " na-trilha" : "") + (atual === x.id ? " atual" : "") +
        '" href="#/' + esc(x.id) + '"><span>' + esc((x.emoji ? x.emoji + " " : "") + x.titulo) + "</span></a>";
    });
    html += "</details>";
    if (t) {
      t.nav.forEach(function (g) {
        var temAtual = g.itens.some(function (it) { return it.id === atual; });
        var aberto = !g.fechado || temAtual;
        html += '<details class="grupo"' + (aberto ? " open" : "") + "><summary>" + esc(g.grupo) + "</summary>";
        g.itens.forEach(function (it) {
          html += '<a class="item' + (it.id === atual ? " atual" : "") + '" href="#/' + esc(it.id) + '">' +
            "<span>" + esc(it.titulo) + "</span>" +
            (feitos[it.id] ? '<span class="feito" aria-label="estudado">✓</span>' : "") + "</a>";
        });
        html += "</details>";
      });
    }
    el("arvore").innerHTML = html;
    var a = el("arvore").querySelector(".atual");
    if (a && a.scrollIntoView && window.innerWidth >= 1000) a.scrollIntoView({ block: "nearest" });
  }

  /* ---------- tema e tamanho da letra ---------- */
  el("btn-tema").addEventListener("click", function () {
    var raiz = document.documentElement;
    var escuroAgora = raiz.getAttribute("data-theme") === "dark" ||
      (!raiz.getAttribute("data-theme") && window.matchMedia("(prefers-color-scheme: dark)").matches);
    var novo = escuroAgora ? "light" : "dark";
    raiz.setAttribute("data-theme", novo);
    try { localStorage.setItem("cfnb-tema", novo); } catch (e) { /* ok */ }
  });
  el("btn-fonte").addEventListener("click", function () {
    var raiz = document.documentElement;
    var atual = Number(raiz.getAttribute("data-fonte") || "2");
    var novo = atual >= 3 ? 1 : atual + 1;
    raiz.setAttribute("data-fonte", String(novo));
    try { localStorage.setItem("cfnb-fonte", String(novo)); } catch (e) { /* ok */ }
  });

  /* ---------- barra de progresso da leitura ---------- */
  var barra = el("progresso");
  function atualizarProgresso() {
    var max = document.documentElement.scrollHeight - window.innerHeight;
    barra.style.width = (max > 40 ? Math.min(100, (window.scrollY / max) * 100) : 0) + "%";
  }
  window.addEventListener("scroll", atualizarProgresso, { passive: true });
  window.addEventListener("resize", atualizarProgresso);

  /* ---------- renderização ---------- */
  marked.use({ gfm: true });

  var NOMES_LING = { c: "C", bash: "Terminal", sh: "Terminal", python: "Python", json: "JSON" };

  function dicaDeRolagem(caixa, rolavel) {
    requestAnimationFrame(function () {
      if (rolavel.scrollWidth > rolavel.clientWidth + 4) {
        caixa.classList.add("rola");
        var rotulo = caixa.querySelector(".barra span");
        if (rotulo) rotulo.insertAdjacentHTML("beforeend", ' <em class="deslize">· deslize →</em>');
        rolavel.addEventListener("scroll", function () {
          caixa.classList.toggle("fim", rolavel.scrollLeft + rolavel.clientWidth >= rolavel.scrollWidth - 8);
        }, { passive: true });
      }
    });
  }

  function blocosDeCodigo(raiz) {
    raiz.querySelectorAll("pre").forEach(function (pre) {
      var code = pre.querySelector("code");
      var m = code && /language-(\w+)/.exec(code.className);
      var ling = m ? m[1] : "";
      var w = document.createElement("div");
      w.className = "bloco";
      pre.parentNode.insertBefore(w, pre);
      if (NOMES_LING[ling]) {
        if (window.hljs && hljs.getLanguage(ling)) hljs.highlightElement(code);
        var topo = document.createElement("div");
        topo.className = "barra";
        topo.innerHTML = "<span>" + NOMES_LING[ling] + '</span><button class="copiar" type="button">copiar</button>';
        w.appendChild(topo);
        var b = topo.querySelector("button");
        b.addEventListener("click", function () {
          var pronto = function () { b.textContent = "copiado!"; setTimeout(function () { b.textContent = "copiar"; }, 1500); };
          if (navigator.clipboard) navigator.clipboard.writeText(code.innerText).then(pronto, function () {});
        });
      } else if (/^(Exercise \d|Assignment name)/.test(pre.textContent)) {
        w.classList.add("subject");
      } else {
        w.classList.add("diagrama");
      }
      w.appendChild(pre);
      dicaDeRolagem(w, pre);
    });
  }

  function tabelas(raiz) {
    raiz.querySelectorAll("table").forEach(function (t) {
      var w = document.createElement("div");
      w.className = "tabela";
      t.parentNode.insertBefore(w, t);
      w.appendChild(t);
      dicaDeRolagem(w, w);
    });
  }

  function citacoes(raiz) {
    raiz.querySelectorAll("blockquote").forEach(function (q) {
      var texto = q.textContent.trim();
      var tipo = null;
      if (/^💡/.test(texto)) tipo = ["dica", "Dica"];
      else if (/^⚠️/.test(texto)) tipo = ["atencao", "Atenção"];
      if (!tipo) return;
      q.classList.add(tipo[0]);
      var andador = document.createTreeWalker(q, NodeFilter.SHOW_TEXT);
      var no;
      while ((no = andador.nextNode())) {
        if (no.nodeValue.trim()) { no.nodeValue = no.nodeValue.replace(/^\s*(💡|⚠️)\s*/, ""); break; }
      }
      var r = document.createElement("span");
      r.className = "rotulo";
      r.textContent = tipo[1];
      q.insertBefore(r, q.firstChild);
    });
  }

  var SECOES = [
    [/^É normal estranhar/, "acolhe"],
    [/^Mini-exercício/, "pratica"],
    [/^Perguntas de fixação/, "pratica"],
    [/^A ideia central/, "ideia"],
    [/^Erros comuns/, "atencao"],
    [/^Casos extremos/, "nota"],
  ];
  function secoes(raiz) {
    Array.prototype.slice.call(raiz.children).forEach(function (h) {
      if (h.tagName !== "H2") return;
      var tipo = null;
      SECOES.forEach(function (s) { if (!tipo && s[0].test(h.textContent.trim())) tipo = s[1]; });
      if (!tipo) return;
      var caixa = document.createElement("section");
      caixa.className = "caixa " + tipo;
      raiz.insertBefore(caixa, h);
      var no = h;
      while (no && !(no !== h && (no.tagName === "H2" || no.tagName === "HR"))) {
        var prox = no.nextElementSibling;
        caixa.appendChild(no);
        no = prox;
      }
    });
  }

  function linhaMeta(raiz) {
    var p = raiz.querySelector("h1 + p");
    if (!p || !/^⏱/.test(p.textContent.trim())) return;
    var partes = p.innerHTML.split(" · ");
    var html = '<span class="chip">' + partes[0].replace(/minutos/, "min de leitura") + "</span>";
    var tmp = document.createElement("div");
    tmp.innerHTML = partes.slice(1).join(" · ");
    tmp.querySelectorAll("a").forEach(function (a) {
      a.classList.add("chip");
      a.insertAdjacentHTML("afterbegin", "📄 ");
      html += a.outerHTML;
    });
    var div = document.createElement("div");
    div.className = "meta";
    div.innerHTML = html;
    p.replaceWith(div);
  }

  function sumario(raiz) {
    var hs = raiz.querySelectorAll("h2");
    if (hs.length < 4) return;
    var html = '<details class="sumario"><summary>Nesta página · ' + hs.length + " partes</summary><ol>";
    hs.forEach(function (h, i) {
      h.id = "secao-" + i;
      html += '<li><button type="button" data-alvo="secao-' + i + '">' + esc(h.textContent) + "</button></li>";
    });
    html += "</ol></details>";
    var ancora = raiz.querySelector(".meta") || raiz.querySelector("h1");
    if (!ancora) return;
    ancora.insertAdjacentHTML("afterend", html);
    raiz.querySelectorAll(".sumario button").forEach(function (b) {
      b.addEventListener("click", function () { el(b.getAttribute("data-alvo")).scrollIntoView({ behavior: "smooth" }); });
    });
  }

  function linksExternos(raiz) {
    raiz.querySelectorAll("a[href^='http']").forEach(function (a) {
      a.target = "_blank";
      a.rel = "noopener";
    });
  }

  function enfeitar(raiz, completo, semSumario) {
    if (completo) {
      linhaMeta(raiz);
      citacoes(raiz);
      secoes(raiz);
      if (!semSumario) sumario(raiz);
    }
    blocosDeCodigo(raiz);
    tabelas(raiz);
    linksExternos(raiz);
  }

  function rodape(id, t) {
    if (!t) return "";
    var ordem = t.ordem;
    var i = ordem.indexOf(id);
    var html = '<div class="rodape-pagina">';
    if (i >= 0) {
      html += '<label class="estudado"><input type="checkbox" id="chk-feito"' + (feitos[id] ? " checked" : "") +
        "> Marcar como estudado</label>";
      html += '<div class="navegacao">';
      if (i > 0) html += '<a href="#/' + esc(ordem[i - 1]) + '"><small>← anterior</small>' + esc(tituloNav(ordem[i - 1])) + "</a>";
      if (i < ordem.length - 1) html += '<a class="prox" href="#/' + esc(ordem[i + 1]) + '"><small>próxima →</small>' + esc(tituloNav(ordem[i + 1])) + "</a>";
      html += "</div>";
    }
    return html + "</div>";
  }

  var CFG = C.config || {};
  var APOIO = CFG.apoio || {};
  var temApoio = !!(APOIO.link || APOIO.pix);

  function cartaoApoio() {
    if (!temApoio) return "";
    var html = '<div class="apoio"><span class="emoji" aria-hidden="true">💙</span><div><strong>Gostou? Apoie este material</strong>' +
      "<p>" + esc(APOIO.texto || "") + '</p><div class="apoio-acoes">';
    if (APOIO.link) html += '<a class="botao primario" href="' + esc(APOIO.link) + '" target="_blank" rel="noopener">' + esc(APOIO.rotulo_link || "Apoiar") + " ↗</a>";
    if (APOIO.pix) html += '<button class="botao" type="button" id="btn-pix">Copiar chave Pix</button>';
    return html + "</div></div></div>";
  }

  function rodapeSite() {
    return '<footer class="rodape-site">' + cartaoApoio() +
      '<p><strong>Não oficial.</strong> ' + esc(CFG.aviso || "") + "</p>" +
      '<p><strong>Open-source.</strong> ' + esc(CFG.licenca || "") +
      ' <a href="' + esc(C.repo) + '" target="_blank" rel="noopener">Código no GitHub</a> · ' +
      '<a href="' + esc(C.repo + "/blob/main/CONTRIBUTING.md") + '" target="_blank" rel="noopener">Como contribuir</a></p></footer>';
  }

  function ligarRodapeSite() {
    var b = el("btn-pix");
    if (b) b.addEventListener("click", function () {
      var ok = function () { b.textContent = "Chave copiada!"; setTimeout(function () { b.textContent = "Copiar chave Pix"; }, 2000); };
      if (navigator.clipboard) navigator.clipboard.writeText(APOIO.pix).then(ok, function () { b.textContent = APOIO.pix; });
      else b.textContent = APOIO.pix;
    });
  }

  function cartao(href, emoji, titulo, sub) {
    return '<a class="cartao" href="' + href + '"><span class="emoji">' + emoji + "</span><strong>" + esc(titulo) + "</strong><small>" + esc(sub) + "</small></a>";
  }

  /* página inicial do site: escolhe a trilha */
  function inicioSite() {
    var html = '<div class="hero"><div class="caminho">Material de estudo</div>' +
      "<h1>C para quem já programa</h1>" +
      "<p>O que é específico de C — sintaxe, memória e ponteiros — explicado para quem já sabe programar em outra linguagem.</p>" +
      '<div class="selos"><span class="chip">🆓 Gratuito</span><a class="chip" href="' + esc(C.repo) + '" target="_blank" rel="noopener">🔓 Open-source</a><span class="chip">⚠️ Não oficial</span></div></div>' +
      '<h2 class="titulo-secao">Trilhas</h2><div class="trilhas">';
    trilhas.forEach(function (t) {
      var total = t.ordem.length;
      var feitas = t.ordem.filter(function (id) { return feitos[id]; }).length;
      html += '<a class="trilha" href="#/' + esc(t.id) + '"><span class="emoji">' + esc(t.emoji || "📘") + "</span>" +
        "<strong>" + esc(t.titulo) + "</strong><small>" + esc(t.descricao || "") + "</small>" +
        '<div class="trilho"><span style="width:' + Math.round((feitas / Math.max(1, total)) * 100) + '%"></span></div>' +
        '<small class="progresso-txt">' + feitas + " de " + total + " páginas estudadas</small></a>";
    });
    return html + '<div class="trilha em-breve"><span class="emoji">🧩</span><strong>Mais conceitos de C</strong><small>Novas trilhas em breve.</small></div></div>';
  }

  /* página inicial de uma trilha com aulas: progresso e atalhos */
  function inicioTrilha(t) {
    var feitas = t.aulas.filter(function (id) { return feitos[id]; }).length;
    var total = t.ordem.filter(function (id) { return id !== t.id; });
    var estudadas = total.filter(function (id) { return feitos[id]; }).length;
    var proxima = t.aulas.filter(function (id) { return !feitos[id]; })[0];
    var p = t.id + "/";
    var botao = proxima
      ? '<a class="botao primario" href="#/' + esc(proxima) + '">' + (feitas ? "Continuar: " : "Começar: ") + esc(tituloNav(proxima)) + " →</a>"
      : '<a class="botao primario" href="#/' + p + '02-exercicios/exames">Todas as aulas feitas! Ir para os exames →</a>';
    return '<div class="hero"><div class="caminho">' + esc(t.emoji ? t.emoji + " " : "") + "Trilha</div>" +
      "<h1>" + esc(t.titulo) + "</h1><p>" + esc(t.descricao || "") + "</p></div>" +
      '<div class="painel"><div class="linha"><span>Aulas estudadas</span><strong>' + feitas + " de " + t.aulas.length + "</strong></div>" +
      '<div class="trilho"><span style="width:' + Math.round((feitas / Math.max(1, t.aulas.length)) * 100) + '%"></span></div>' +
      botao + '<div class="linha" style="margin:10px 0 0"><span>Páginas marcadas nesta trilha</span><span>' + estudadas + " de " + total.length + "</span></div></div>" +
      '<div class="cartoes">' +
      cartao("#/" + p + "01-exemplos", "📘", "Aulas", t.aulas.length + " aulas de 5 a 10 min") +
      cartao("#/" + p + "02-exercicios", "🛠️", "Exercícios", "Módulos no estilo subject") +
      cartao("#/" + p + "02-exercicios/exames", "⏱️", "Exames", "Simulados cronometrados") +
      cartao("#/" + p + "03-respostas", "✅", "Respostas", "Soluções explicadas") +
      "</div>";
  }

  function trocarTitulo(tmp, texto) {
    var h = tmp.querySelector("h1");
    if (h) h.outerHTML = "<h2>" + texto + "</h2>";
    tmp.querySelectorAll("p").forEach(function (pp) { if (/^📱/.test(pp.textContent.trim())) pp.remove(); });
  }

  function mostrarPagina(id) {
    var p = C.paginas[id];
    if (!p) return naoAchou(id);
    var t = trilhaDe(id);
    var corpo = marked.parse(p.md);
    var grupo = t && t.grupoDe[id] && id !== t.id ? t.grupoDe[id] : "";
    var caminho = t && id !== t.id ? '<div class="caminho">' + esc(t.curto || t.titulo) + (grupo ? " · " + esc(grupo) : "") + "</div>" : "";
    var tmp = document.createElement("div");
    tmp.innerHTML = corpo;
    if (id === "") {
      trocarTitulo(tmp, "Sobre este material");
      main.innerHTML = inicioSite() + tmp.innerHTML;
    } else if (t && id === t.id && t.aulas.length) {
      trocarTitulo(tmp, "Sobre esta trilha");
      main.innerHTML = inicioTrilha(t) + tmp.innerHTML + rodape(id, t);
    } else if (p.resposta && !reveladas[id]) {
      var h1 = tmp.querySelector("h1");
      main.innerHTML = caminho + (h1 ? h1.outerHTML : "") +
        '<div class="spoiler-aviso"><p><strong>Já tentou resolver?</strong><br>O aprendizado está no tempo em que você fica travado. ' +
        "Tente uns 20 minutos antes de abrir.</p>" +
        '<button class="botao primario" id="btn-revelar" type="button">Mostrar a resposta</button></div>' + rodape(id, t);
      el("btn-revelar").addEventListener("click", function () { reveladas[id] = true; mostrarPagina(id); });
    } else {
      main.innerHTML = caminho + corpo + rodape(id, t);
    }
    main.insertAdjacentHTML("beforeend", rodapeSite());
    ligarRodapeSite();
    enfeitar(main, true, id === "" || (t && id === t.id));
    var chk = el("chk-feito");
    if (chk) chk.addEventListener("change", function () {
      if (chk.checked) feitos[id] = 1; else delete feitos[id];
      gravar("cfnb-feitos", feitos);
      desenharMenu(id, t);
    });
    definirTitulo(id === "" ? "Início" : (t && id === t.id ? t.titulo : p.titulo));
    desenharAbas(t);
    desenharMenu(id, t);
  }

  function mostrarArquivo(caminho) {
    var f = C.arquivos[caminho];
    if (!f) return naoAchou("arquivo/" + caminho);
    var t = trilhaDe(caminho);
    var nome = caminho.split("/").pop();
    var cerca = "````";
    main.innerHTML = '<div class="caminho">' + (t ? esc(t.curto || t.titulo) + " · " : "") + "Arquivo</div><h1><code>" + esc(nome) + "</code></h1>" +
      '<div class="meta"><span class="chip">' + esc(caminho) + '</span><a class="chip" href="' +
      esc(C.repo + "/blob/main/" + caminho) + '">ver no GitHub ↗</a></div>' +
      marked.parse(cerca + f.lang + "\n" + f.texto + "\n" + cerca) +
      '<p><a class="botao" href="javascript:history.back()">← Voltar</a></p>' + rodapeSite();
    ligarRodapeSite();
    enfeitar(main, false);
    definirTitulo(nome);
    desenharAbas(t);
    desenharMenu(null, t);
  }

  function naoAchou(rotaPedida) {
    var antiga = rotaPedida.indexOf("arquivo/") === 0
      ? "arquivo/" + PADRAO + "/" + rotaPedida.slice(8)
      : PADRAO + "/" + rotaPedida;
    if (PADRAO && (C.paginas[antiga] || C.arquivos[antiga.slice(8)])) {
      location.replace("#/" + antiga);
      return;
    }
    main.innerHTML = "<h1>Página não encontrada</h1><p><a href='#/'>Voltar ao início</a></p>";
    definirTitulo("Não encontrada");
    desenharAbas(null);
    desenharMenu(null, null);
  }

  function definirTitulo(t) {
    var limpo = t.replace(/`/g, "");
    document.title = limpo + " · C para quem já programa";
    el("titulo-topo").textContent = limpo;
  }

  function rota() {
    var h = decodeURIComponent(location.hash.replace(/^#\/?/, ""));
    abrirMenu(false);
    if (h.indexOf("arquivo/") === 0) mostrarArquivo(h.slice(8));
    else mostrarPagina(h.replace(/\/$/, ""));
    window.scrollTo(0, 0);
    atualizarProgresso();
    main.focus({ preventScroll: true });
  }
  window.addEventListener("hashchange", rota);

  /* ---------- busca ---------- */
  function normal(s) {
    return s.normalize("NFD").replace(/[̀-ͯ]/g, "").toLowerCase();
  }
  var indice = Object.keys(C.paginas).map(function (id) {
    var texto = C.paginas[id].md
      .replace(/```[a-z]*\n/g, "").replace(/\]\([^)]*\)/g, "]")
      .replace(/[#*`>|_\[\]]/g, " ").replace(/<\/?\w+[^>]*>/g, " ").replace(/\s+/g, " ").normalize("NFC");
    var t = porId[C.paginas[id].trilha];
    return { id: id, titulo: C.paginas[id].titulo, trilha: t ? (t.curto || t.titulo) : "", texto: texto, norm: normal(texto), tnorm: normal(C.paginas[id].titulo) };
  });
  var timer = null;
  el("busca").addEventListener("input", function () {
    clearTimeout(timer);
    timer = setTimeout(buscar, 120);
  });
  function buscar() {
    var q = normal(el("busca").value.trim());
    var box = el("resultados");
    if (q.length < 2) { box.hidden = true; el("arvore").hidden = false; return; }
    var achados = [];
    indice.forEach(function (p) {
      var i = p.norm.indexOf(q);
      var noTitulo = p.tnorm.indexOf(q) >= 0;
      if (i < 0 && !noTitulo) return;
      var n = 0, pos = i;
      while (pos >= 0 && n < 50) { n++; pos = p.norm.indexOf(q, pos + q.length); }
      achados.push({ p: p, i: i, peso: (noTitulo ? 100 : 0) + n });
    });
    achados.sort(function (a, b) { return b.peso - a.peso; });
    var html = "";
    achados.slice(0, 25).forEach(function (a) {
      var trecho = "";
      if (a.i >= 0) {
        var ini = Math.max(0, a.i - 40);
        var t = a.p.texto;
        trecho = (ini > 0 ? "…" : "") + esc(t.slice(ini, a.i)) + "<mark>" + esc(t.slice(a.i, a.i + q.length)) + "</mark>" +
          esc(t.slice(a.i + q.length, a.i + q.length + 60)) + "…";
      }
      html += '<a href="#/' + esc(a.p.id) + '">' + (a.p.trilha ? '<span class="de-trilha">' + esc(a.p.trilha) + "</span>" : "") +
        esc(a.p.titulo.replace(/`/g, "")) + (trecho ? "<small>" + trecho + "</small>" : "") + "</a>";
    });
    box.innerHTML = html || '<div class="vazio">Nada encontrado.</div>';
    box.hidden = false;
    el("arvore").hidden = true;
  }

  rota();

  if ("serviceWorker" in navigator && /^https?:$/.test(location.protocol)) {
    navigator.serviceWorker.register("sw.js").catch(function () {});
  }
})();
