# ProgettoProgrammazione
Progetto di programmazione - Unibo
## Documentazione
### comandi
a: spostamento a sinistra
d: spostamento a destra
spazio: salto
w: attacco
e: accesso al negozio
q: esci

### cartelle
- db: file per i salvataggi di stato
- src: file sorgente delle classi
  - main: classi main e principali (negoozio, ...)
  - elementi: classi di personaggi, potenziamenti...
    - personaggi: classi protagonista e nemici
    - potenziamenti: classi potenziamenti
    - armi: classi delle armi
  - util: classi di utilità (accesso file, liste...)

### dettagli implementativi
Il protagonista può mantenere al massimo 3 potenziamenti e un'arma contemporaneamente.
I potenziamenti durano un certo numero di livelli. Quando il livello finisce,
prima di andare al successivo i potenziamenti arrivati a durata 0 vengono rimossi.