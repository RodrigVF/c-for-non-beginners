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
  var feitos = ler("cfnb-feitos", {});

  var ordem = [];
  var grupoDe = {};
  C.nav.forEach(function (g) {
    g.itens.forEach(function (it) {
      if (ordem.indexOf(it.id) < 0) ordem.push(it.id);
      if (!(it.id in grupoDe)) grupoDe[it.id] = g.grupo;
    });
  });
  function tituloNav(id) {
    for (var i = 0; i < C.nav.length; i++)
      for (var j = 0; j < C.nav[i].itens.length; j++)
        if (C.nav[i].itens[j].id === id) return C.nav[i].itens[j].titulo;
    return C.paginas[id] ? C.paginas[id].titulo : id;
  }

  function esc(s) {
    return String(s).replace(/[&<>"']/g, function (c) {
      return { "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[c];
    });
  }

  /* ---------- menu ---------- */
  function abrirMenu(abrir) {
    menu.classList.toggle("aberto", abrir);
    fundo.hidden = !abrir;
    el("btn-menu").setAttribute("aria-expanded", abrir ? "true" : "false");
    if (abrir) document.body.style.overflow = "hidden";
    else document.body.style.overflow = "";
  }
  el("btn-menu").addEventListener("click", function () { abrirMenu(!menu.classList.contains("aberto")); });
  fundo.addEventListener("click", function () { abrirMenu(false); });
  document.addEventListener("keydown", function (e) { if (e.key === "Escape") abrirMenu(false); });

  function desenharMenu(atual) {
    var html = "";
    C.nav.forEach(function (g) {
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
    el("arvore").innerHTML = html;
    var a = el("arvore").querySelector(".atual");
    if (a && a.scrollIntoView && window.innerWidth >= 1000) a.scrollIntoView({ block: "nearest" });
  }

  /* ---------- tema ---------- */
  el("btn-tema").addEventListener("click", function () {
    var raiz = document.documentElement;
    var escuroAgora = raiz.getAttribute("data-theme") === "dark" ||
      (!raiz.getAttribute("data-theme") && window.matchMedia("(prefers-color-scheme: dark)").matches);
    var novo = escuroAgora ? "light" : "dark";
    raiz.setAttribute("data-theme", novo);
    try { localStorage.setItem("cfnb-tema", novo); } catch (e) { /* ok */ }
  });

  /* ---------- renderizacao ---------- */
  marked.use({ gfm: true });

  function enfeitar(raiz) {
    raiz.querySelectorAll("table").forEach(function (t) {
      var w = document.createElement("div");
      w.className = "tabela";
      t.parentNode.insertBefore(w, t);
      w.appendChild(t);
    });
    raiz.querySelectorAll("pre").forEach(function (pre) {
      var w = document.createElement("div");
      w.className = "bloco";
      pre.parentNode.insertBefore(w, pre);
      w.appendChild(pre);
      var code = pre.querySelector("code");
      if (code && window.hljs) {
        var m = /language-(\w+)/.exec(code.className);
        if (m && m[1] !== "plaintext" && hljs.getLanguage(m[1])) hljs.highlightElement(code);
      }
      if (!code || !/language-(c|bash|sh|python|json)\b/.test(code.className)) return;
      var b = document.createElement("button");
      b.className = "copiar";
      b.type = "button";
      b.textContent = "copiar";
      b.addEventListener("click", function () {
        var texto = pre.innerText;
        var pronto = function () { b.textContent = "copiado!"; setTimeout(function () { b.textContent = "copiar"; }, 1500); };
        if (navigator.clipboard) navigator.clipboard.writeText(texto).then(pronto, function () {});
      });
      w.appendChild(b);
    });
    raiz.querySelectorAll("a[href^='http']").forEach(function (a) {
      a.target = "_blank";
      a.rel = "noopener";
    });
  }

  function rodape(id) {
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

  function mostrarPagina(id) {
    var p = C.paginas[id];
    if (!p) return naoAchou();
    var corpo = marked.parse(p.md);
    var caminho = grupoDe[id] ? '<div class="caminho">' + esc(grupoDe[id]) + "</div>" : "";
    if (p.resposta && !reveladas[id]) {
      var tmp = document.createElement("div");
      tmp.innerHTML = corpo;
      var h1 = tmp.querySelector("h1");
      main.innerHTML = caminho + (h1 ? h1.outerHTML : "") +
        '<div class="spoiler-aviso"><p><strong>Já tentou resolver?</strong><br>O aprendizado está no tempo em que você fica travado. ' +
        "Tente uns 20 minutos antes de abrir.</p>" +
        '<button class="botao primario" id="btn-revelar" type="button">Mostrar a resposta</button></div>' + rodape(id);
      el("btn-revelar").addEventListener("click", function () { reveladas[id] = true; mostrarPagina(id); });
    } else {
      main.innerHTML = caminho + corpo + rodape(id);
    }
    enfeitar(main);
    var chk = el("chk-feito");
    if (chk) chk.addEventListener("change", function () {
      if (chk.checked) feitos[id] = 1; else delete feitos[id];
      gravar("cfnb-feitos", feitos);
      desenharMenu(id);
    });
    definirTitulo(p.titulo);
    desenharMenu(id);
  }

  function mostrarArquivo(caminho) {
    var f = C.arquivos[caminho];
    if (!f) return naoAchou();
    var nome = caminho.split("/").pop();
    var cerca = "````";
    main.innerHTML = '<div class="caminho">Arquivo do repositório</div><h1><code>' + esc(nome) + "</code></h1>" +
      '<p class="caminho">' + esc(caminho) + ' · <a href="' + esc(C.repo + "/blob/main/" + caminho) + '">ver no GitHub</a></p>' +
      marked.parse(cerca + f.lang + "\n" + f.texto + "\n" + cerca) +
      '<p><a class="botao" href="javascript:history.back()">← Voltar</a></p>';
    enfeitar(main);
    definirTitulo(nome);
    desenharMenu(null);
  }

  function naoAchou() {
    main.innerHTML = "<h1>Página não encontrada</h1><p><a href='#/'>Voltar ao início</a></p>";
    definirTitulo("Não encontrada");
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
      .replace(/[#*`>|_\[\]]/g, " ").replace(/<\/?\w+[^>]*>/g, " ").replace(/\s+/g, " ");
    return { id: id, titulo: C.paginas[id].titulo, texto: texto, norm: normal(texto), tnorm: normal(C.paginas[id].titulo) };
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
      html += '<a href="#/' + esc(a.p.id) + '">' + esc(a.p.titulo.replace(/`/g, "")) + (trecho ? "<small>" + trecho + "</small>" : "") + "</a>";
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
