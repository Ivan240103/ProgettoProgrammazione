# ProgettoProgrammazione
Progetto di programmazione - Unibo  
Gioco del genere platform game in grafica ASCII.  
Il protagonista ha lo scopo di uccidere i nemici per guadagnare punti ed avanzare di livello, game over quando la vita del protagonista arriva a zero.

### comandi
- a: spostamento a sinistra
- d: spostamento a destra
- spazio: salto
- w: attacco
- e: accesso al negozio
- x: esci

## DEBUG
Comando nuovo per eseguire il main:

g++ -c Gioco.cpp ../elementi/personaggi/Protagonista.cpp ../elementi/personaggi/Nemico.cpp Negozio.cpp Livello.cpp ../elementi/armi/Arma.cpp ../elementi/potenziamenti/Potenziamento.cpp ../util/Stringa.cpp ../util/GestoreFile.cpp GUI.cpp -c Main.cpp && g++ Arma.o Potenziamento.o GestoreFile.o Gioco.o GUI.o Livello.o Negozio.o Nemico.o Protagonista.o Stringa.o Main.o -o Main -lncurses && ./Main && rm *.o

Comando per compilare ed eseguire il codice (in VS code almeno):  
cd "/home/master/Scrivania/ProgettoCompleto/ProgettoProgrammazione-tambo/Progetto/src/main/" && g++ Main.cpp Gioco.cpp ../elementi/personaggi/Protagonista.cpp ../elementi/personaggi/Nemico.cpp Negozio.cpp Livello.cpp GUI.cpp  ../elementi/armi/Arma.cpp ../util/Stringa.cpp ../util/GestoreFile.cpp -o Main && "/home/master/Scrivania/ProgettoCompleto/ProgettoProgrammazione-tambo/Progetto/src/main/"Main 

**Ivan:** cd "/home/ivan/Documenti/Unibo/ProgettoProgrammazione-ivan/Progetto/src/main/" && g++ Main.cpp Gioco.cpp ../elementi/personaggi/Protagonista.cpp ../elementi/personaggi/Nemico.cpp Negozio.cpp Livello.cpp ../elementi/armi/Arma.cpp ../util/Stringa.cpp ../util/GestoreFile.cpp -o Main && "/home/ivan/Documenti/Unibo/ProgettoProgrammazione-ivan/Progetto/src/main/"Main

In alcuni file sono presenti delle righe di codice con l'etichetta *DEBUG:*, sono parti che andranno rimosse a progetto concluso in quanto servivano per testare il codice da riga di comando senza la grafica

## Documentazione

### Cartelle
- db: file per i salvataggi di stato
- src: file sorgente delle classi
  - elementi: classi di personaggi, potenziamenti...
    - armi: classi delle armi
    - personaggi: classi protagonista e nemici
    - potenziamenti: classi potenziamenti
  - main: classi main e principali (gestore gioco, livello...)
  - util: classi di utilità (accesso file, stringhe...)

### Dinamiche del gioco
Il protagonista viene creato caricando i dati salvati sul suo file. Se la vita è a zero vuol dire che il gioco si era concluso, quindi viene resettato il file dei salvataggi e viene creato un primo livello di una difficoltà adatta basandosi sulla vita e sull'inventario del protagonista tramite dei coefficienti, viene riportata la vita a 100 e i punti a 0 (inventario e denaro sono mantenuti). Se la vita non è a zero allora vengono caricati i dati della partita del file ed il gioco riparte da dove era stato interrotto.  
I nemici all'interno di un livello diventano sempre di più e sempre più forti man mano che si procede nel gioco.  
Il protagonista può quindi muoversi nel livello attuale ed attaccare i nemici, il negozio è accessibile in qualunque momento della partita da un "menù di pausa". Il protagonista può muoversi tra i livelli ma per poter andare oltre l'ultimo deve aver ucciso tutti i nemici.  
Quando il livello finisce, prima di andare al successivo i potenziamenti arrivati a durata 0 vengono rimossi dall'inventario del protagonista.  
L'utente può interrompere la partita quando vuole, uscendo i dati vengono sempre salvati automaticamente. Se la vita del protagonista arriva a 0 è game over e la partita si interrompe in automatico.  

### Dettagli implementativi
Il protagonista ha una classe specializzata (*Protagonista*) che mantiene tutti gli attributi e i metodi per modificarli, ad esempio per diminuire la vita, modificare le coordinate della posizione a schermo..., oltre che metodi propri come per salvare lo stato del personaggio sul file. Nel costruttore il protagonista viene creato a partire dai dati che sono salvati sul file.
Il protagonista può mantenere al massimo 3 potenziamenti e un'arma contemporaneamente.  
I nemici hanno tutti una classe padre (*Nemico*) che mantiene gli attributi e mette a disposizione dei metodi uguali per tutti, mentre le sottoclassi (*Scheletro*, *Goblin*, *Guardia*) servono per specializzare gli attributi con valori fissati. Il valore del danno causabile dai nemici è scelto casualmente tra una soglia minima e massima.  
Stessa cosa per le armi, che hanno la classe padre (*Arma*) che contiene gli attributi con i relativi getters, mentre le sottoclassi (*Bastone*, *Spada*, *PallaChiodata*, *Arco*) specializzano gli attributi con valori fissi, diversi l'una dall'altra. L'arma Bastone è quella di default del protagonista.  
.... I potenziamenti durano un certo numero di livelli ....   
La classe *Negozio* gestisce lo shop in cui il protagonista può acquistare armi e/o potenziamenti, pertanto mantiene questi oggetti salvati in due array e permette di ottenerli in cambio della giusta quantità di denaro.  
Un singolo livello è gestito dalla classe *Livello*, la quale mantiene l'indice della difficoltà, il flag della presenza o meno del protagonista e la lista dinamica dei nemici presenti, insieme ai metodi per aggiungere/rimuovere i nemici, modificare il flag, salvare il livello su file...  
L'insieme dei livelli e quindi la partita viene gestito dalla classe *Gioco*. Questa classe contiene la lista dinamica bidirezionale dei livelli con i metodi per crearli ed aggiungerli, oltre che per muovere il protagonista tra di essi. La classe ha un puntatore al livello in cui si trova il protagonista per semplificarne l'accesso. La classe implementa inoltre i metodi per salvare e caricare i dati su file dell'intera partita (protagonista escluso).  
Due classi *Stringa* e *GestoreFile* servono per semplificare l'uso degli array di char e l'accesso ai file in lettura/scrittura.  
La classe *Main* contiene per l'appunto il main da cui eseguire il gioco.  

### Salvataggi nel db
Lo stato della partita viene salvato nel file "db/partita.txt". Il file mantiene salvata la lista ordinata, dal primo all'ultimo, dei livelli (id = difficoltà, presenza o meno del protagonista) con i nemici presenti e le loro caratteristiche (i nemici solo dell'ultimo livello).  
L'inizio del livello è segnato con '@', i due valori seguenti sono la difficoltà (id) e 1 se era il livello attuale 0 altrimenti. '#' segnala la fine del file.  
Lo stato del protagonista viene salvato in un file a se, ovvero "db/protagonista.txt".  
Il file contiene gli attributi in ordine: nome, vita, denaro, arma, punti, coord x, coord y, versoDestra
