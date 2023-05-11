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
    // identificativo del livello (difficoltà)
    int id;
    // true se c'è il protagonista nel livello
    bool attuale;
    // testa della lista dinamica dei nemici
    pnodo hnemici;

    void rimuoviTesta();

  public:
    Livello(int id = 1, bool attuale = false);

    int getId();

    bool isAttuale();

    void protagonistaArriva();

    void protagonistaAddios();

    void inserisciNemico(Nemico n);

    void rimuoviNemici();

    bool isTerminato();

    void salva(GestoreFile &gf);

    // DEBUG: rimuovere quando non servirà più
    void debug();
    
    // DEBUG: rimuovere quando non servirà più
    Nemico getPrimoNemico();
    
    // DEBUG: rimuovere quando non servirà più
    bool attaccaNemico(int dannoSubito);
};

#endif