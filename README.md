# Ajeje's adventures
Progetto di Programmazione 2022-23 - Unibo  

Ajeje’s adventures è un gioco platform in grafica ASCII realizzato in C++ sfruttando le librerie ncurses. L’obiettivo del gioco è uccidere i nemici per poter avanzare di livello. È un gioco a punti in cui non esistono traguardi, game over se la vita scende a zero. Quando il protagonista muore mantiene armi, potenziamenti e denaro ma perde tutti i punti. Il giocatore può uscire dalla partita in qualunque momento ed i suoi progressi verranno salvati automaticamente.

## ESECUZIONE
**Comando per compilare ed eseguire il main** (da eseguire nella cartella "Progetto/src/main"):

g++ -c Main.cpp GUI.cpp Gioco.cpp Livello.cpp Negozio.cpp ../elementi/personaggi/Protagonista.cpp ../elementi/personaggi/Nemico.cpp ../elementi/armi/Arma.cpp ../elementi/potenziamenti/Potenziamento.cpp ../util/*.cpp && g++ *.o -o Ajeje -lncurses && rm *.o && ./Ajeje

**Comando per resettare il database in caso di errori** (da eseguire nella cartella "Progetto/src/main"):

g++ -c Reset.cpp Gioco.cpp Livello.cpp ../elementi/personaggi/Nemico.cpp ../util/*.cpp && g++ *.o -o Reset && rm *.o && ./Reset

## COMANDI
- a: spostamento a sinistra
- d: spostamento a destra
- spazio: salto
- w: attacco
- e: apri/chiudi negozio
- x: esci

## AUTORI
Ivan De Simone, Nicolò Tambini, Tommaso Merighi