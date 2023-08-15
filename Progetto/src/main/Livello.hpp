/*
 Classe per gestire il singolo livello del gioco
*/

#ifndef LIVELLO_HPP
#define LIVELLO_HPP

#include "../elementi/personaggi/Nemico.hpp"
#include "../util/Stringa.hpp"
#include "../util/GestoreFile.hpp"

class Livello {

  struct nodo {
    Nemico nem = Nemico(Stringa((char*) "tmp"));
    nodo* succ = NULL;
  };

  typedef nodo* pnodo;
  
  protected:
    // identificativo del livello
    int id;
    // true se c'è il protagonista nel livello
    bool attuale;

    void rimuoviTesta();

  public:
    Livello(int id = 1, bool attuale = false);

    // testa della lista dinamica dei nemici
    pnodo hnemici;

    pnodo appoggio;

    int getId();

    bool isAttuale();

    void protagonistaArriva();

    void protagonistaAddios();

    void inserisciNemicoTesta(Nemico n);
    
    void inserisciNemicoCoda(Nemico n);

    void rimuoviNemici();

    bool isTerminato();

    void salva(GestoreFile &gf);
};

#endif