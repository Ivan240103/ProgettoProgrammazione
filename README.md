# ProgettoProgrammazione
Progetto di programmazione - Unibo  
Ivan De Simone, Nicolò Tambini, Tommaso Merighi
Gioco di stampo platform game in grafica ASCII controllato da terminale.  
Il protagonista ha lo scopo di uccidere i nemici per guadagnare punti ed avanzare di livello, game over quando la vita del protagonista arriva a zero. Sono presenti diversi tipi di nemici che si muovono, sparano... C'è una valuta che si guadagna uccidendo i nemici e serve per acquistare armi, potenziamenti e/o vita dal negozio sempre accessibile.

### comandi
- a: spostamento a sinistra
- d: spostamento a destra
- spazio: salto
- w: attacco
- e: apri/chiudi negozio
- x: esci

## DEBUG
Comando per eseguire il main (da eseguire nella cartella "Progetto/src/main"):

g++ -c Gioco.cpp ../elementi/personaggi/Protagonista.cpp ../elementi/personaggi/Nemico.cpp Negozio.cpp Livello.cpp ../elementi/armi/Arma.cpp ../elementi/potenziamenti/Potenziamento.cpp ../util/Stringa.cpp ../util/GestoreFile.cpp GUI.cpp -c Main.cpp && g++ Arma.o Potenziamento.o GestoreFile.o Gioco.o GUI.o Livello.o Negozio.o Nemico.o Protagonista.o Stringa.o Main.o -o Main -lncurses && ./Main && rm *.o

## Documentazione

### Cartelle
- db: file per i salvataggi di stato
- src: file sorgente delle classi
  - elementi: classi di personaggi, potenziamenti...
    - armi: classi delle armi
    - personaggi: classi protagonista e nemici
    - potenziamenti: classi potenziamenti
  - main: classi main e principali (gestore grafica, livelli...)
  - util: classi di utilità (accesso file, stringhe...)

### Dinamiche del gioco
Il protagonista viene creato caricando i dati salvati sul suo file. Se la vita è a zero vuol dire che il gioco si era concluso, quindi viene resettato il file dei salvataggi e creato un primo livello base, viene riportata la vita a 100 e i punti a 0 (inventario e denaro sono mantenuti). Se la vita non è a zero allora vengono caricati i dati della partita dal file ed il gioco riparte da dove era stato interrotto.  
Il protagonista può quindi muoversi nel livello attuale ed attaccare i nemici, il negozio è accessibile in qualunque momento della partita.  
Il protagonista può muoversi tra i livelli ma per poter andare oltre l'ultimo deve aver ucciso tutti i nemici. Quando invece si muove indiero ritrova lo schema del livello precedente così come lo aveva lasciato. All'ingresso in un nuovo livello il protagonista viene sempre fatto ripartire all'inizio dello schema.  
L'utente può interrompere la partita quando vuole, uscendo i dati vengono sempre salvati automaticamente. Se la vita del protagonista arriva a 0 è game over e la partita si interrompe in automatico.  

### Dettagli implementativi
Il protagonista ha una classe specializzata (*Protagonista*) che mantiene tutti gli attributi e i metodi per modificarli, ad esempio per diminuire la vita, modificare le coordinate della posizione a schermo..., oltre che metodi propri come per salvare lo stato del personaggio sul file. Nel costruttore il protagonista viene creato a partire dai dati che sono salvati sul file.  
I nemici hanno tutti una classe padre (*Nemico*) che mantiene gli attributi e mette a disposizione dei metodi uguali per tutti, mentre le sottoclassi (*Scheletro*, *Goblin*, *Guardia*) servono per specializzare gli attributi con valori fissati. Il valore del danno causabile dai nemici è scelto casualmente tra una soglia minima e massima.  
Stessa cosa per le armi, che hanno la classe padre (*Arma*) la quale contiene gli attributi con i relativi getters, mentre le sottoclassi (*Bastone*, *Spada*, *PallaChiodata*, *Arco*) specializzano gli attributi con valori fissi, diversi l'una dall'altra. L'arma Bastone è quella di default del protagonista.  
Seguono la stessa struttura i potenziamenti, la cui classe padre (*Potenziamento*) contiene gli attributi ed i metodi comuni, mentre le sottoclassi (*UltraDanno* e *SuperScudo*) specializzano gli attributi quali durata e costo. Il funzionamento dei poteri viene rimandato al momento del bisogno nella classe del protagonista.   
La classe *Negozio* gestisce lo shop in cui il protagonista può acquistare armi, potenziamenti e/o vita (inesauribili). Durante la permanenza nel negozio la partita è messa in pausa.  
Un singolo livello è gestito dalla classe *Livello*, la quale mantiene l'identificativo univoco, il flag della presenza o meno del protagonista e la lista dinamica dei nemici presenti, insieme ai metodi per aggiungere/rimuovere i nemici, modificare il flag, salvare il livello su file...  
L'insieme dei livelli e quindi la partita viene gestito dalla classe *Gioco*. Questa classe contiene la lista dinamica bidirezionale dei livelli con i metodi per crearli ed aggiungerli, oltre che per muovere il protagonista tra di essi. La classe ha un puntatore al livello in cui si trova il protagonista per semplificarne l'accesso. La classe implementa inoltre i metodi per salvare e caricare i dati su file dell'intera partita (protagonista escluso).  
Tutto ciò che riguarda l'interfaccia grafica ed il movimento degli oggetti a schermo è gestito dalla classe *GUI*, che contiene i metodi di stampa, movimento e attacco per tutti gli elementi, oltre che al metodo che gestisce l'intero gioco.  
Due classi *Stringa* e *GestoreFile* servono per semplificare l'uso degli array di char e l'accesso ai file in lettura/scrittura.  
La classe *Main* contiene per l'appunto il main da cui eseguire il gioco.  

### Salvataggi nel db
Lo stato della partita viene salvato nel file "db/partita.txt". Il file mantiene salvata la lista ordinata, dal primo all'ultimo, dei livelli (id, presenza o meno del protagonista) con i nemici presenti e le loro caratteristiche (i nemici solo dell'ultimo livello).  
L'inizio del livello è segnato con '@', i due valori seguenti sono la difficoltà (id) e 1 se era il livello attuale 0 altrimenti. '#' segnala la fine del file.  
Lo stato del protagonista viene salvato in un file a se, ovvero "db/protagonista.txt".  
Il file contiene gli attributi in ordine: nome, vita, denaro, arma, potenziamento, durata pot, punti, coord x, coord y, versoDestra
