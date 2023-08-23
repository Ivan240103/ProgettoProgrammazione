/*
 Classe per gestire un singolo livello del gioco
 Contiene la lista dinamica dei nemici presenti
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
  
  protected:
    // identificativo del livello
    int id;
    // true se c'è il protagonista nel livello, false altrimenti
    bool attuale;

    void rimuoviTesta();

  public:
    // puntatore ad un nodo contenente un livello
    typedef nodo* pnodo;

    // testa della lista dei nemici
    pnodo hnemici;

    Livello(
      int id = 1,
      bool attuale = false
    );

    int getId();

    bool isAttuale();

    void protagonistaArriva();

    void protagonistaAddios();
    
    void inserisciNemico(Nemico n);

    void rimuoviNemici();

    bool isTerminato();

    void salva(GestoreFile &gf);
};

#endif