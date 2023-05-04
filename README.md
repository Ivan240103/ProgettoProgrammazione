# ProgettoProgrammazione
Progetto di programmazione - Unibo

## Documentazione

### DEBUG
Ivan: Comando che funziona(va) per eseguire in VS Code: cd "/home/ivan/Documenti/Unibo/ProgettoProgrammazione-ivan/Progetto/src/main/" && g++ Gioco.cpp ../elementi/personaggi/Protagonista.cpp Negozio.cpp ../elementi/armi/Arma.cpp ../util/Stringa.cpp ../util/GestoreFile.cpp -o Gioco && "/home/ivan/Documenti/Unibo/ProgettoProgrammazione-ivan/Progetto/src/main/"Gioco

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
  - main: classi main e principali (negoozio, livello...)
  - elementi: classi di personaggi, potenziamenti...
    - armi: classi delle armi
    - personaggi: classi protagonista e nemici
    - potenziamenti: classi potenziamenti
  - util: classi di utilità (accesso file, stringhe...)

### dettagli implementativi
Il protagonista può mantenere al massimo 3 potenziamenti e un'arma contemporaneamente.
I potenziamenti durano un certo numero di livelli. Quando il livello finisce,
prima di andare al successivo i potenziamenti arrivati a durata 0 vengono rimossi.

### salvataggi nel db
Le caratteristiche del protagonista vengono salvate in un file a se, in modo che a prescindere dal fatto che
sia vivo o morto i suoiequipaggiamenti restano salvati.
Quando il protagonista muore la partita riparte da un livello x generato, mentre tutti quelli salvati in precedenza
vengono rimossi. Se l'utente esce dal gioco salvando quando il protagonista è ancora vivo, al caricamento del
gioco si ritroverà esattamente nella stessa situazione in cui era prima di chiudere.
Se al caricamento del gioco la vita del protagonista è 0 vuol dire che era morto alla fine della partita.
Ogni volta che si passa di livello, quello precedente viene salvato/aggiornato nel db.
Ogni tot secondi viene salvato anche il livello in cui si trova il protagonista attualmente (autosalvataggio)