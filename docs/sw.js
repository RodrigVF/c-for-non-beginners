const CACHE = "cfnb-e44bb2d98b";
const BASE = [
  "./", "index.html", "style.css?v=e44bb2d98b", "app.js?v=e44bb2d98b",
  "conteudo.js?v=e44bb2d98b", "icon.svg", "manifest.webmanifest",
  "https://cdnjs.cloudflare.com/ajax/libs/marked/12.0.2/marked.min.js",
  "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"
];
self.addEventListener("install", (e) => {
  e.waitUntil(caches.open(CACHE).then((c) => c.addAll(BASE)).then(() => self.skipWaiting()));
});
self.addEventListener("activate", (e) => {
  e.waitUntil(caches.keys().then((ks) => Promise.all(
    ks.filter((k) => k !== CACHE).map((k) => caches.delete(k))
  )).then(() => self.clients.claim()));
});
self.addEventListener("fetch", (e) => {
  if (e.request.method !== "GET") return;
  const url = new URL(e.request.url);
  const nossa = url.origin === location.origin || url.hostname === "cdnjs.cloudflare.com";
  if (!nossa) return;
  if (e.request.mode === "navigate") {
    e.respondWith(fetch(e.request).catch(() => caches.match("index.html")));
    return;
  }
  e.respondWith(caches.match(e.request).then((r) => r || fetch(e.request).then((resp) => {
    const copia = resp.clone();
    caches.open(CACHE).then((c) => c.put(e.request, copia));
    return resp;
  })));
});
