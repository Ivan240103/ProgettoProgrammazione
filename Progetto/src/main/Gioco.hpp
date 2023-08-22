/*
 Classe per gestire la partita
*/

#ifndef GIOCO_HPP
#define GIOCO_HPP

#include <cstdlib>
#include "Livello.hpp"
#include "../elementi/personaggi/Scheletro.cpp"
#include "../elementi/personaggi/Goblin.cpp"
#include "../elementi/personaggi/Guardia.cpp"

class Gioco {
  
  struct liv {
    Livello l = Livello();
    liv* succ = NULL;
    liv* prec = NULL;
  };

  typedef liv* pliv;

  protected:
    // testa della lista bidir dinamica dei livelli
    pliv hlivelli;

    bool cercaIdLivello(int id);

    void creaLivello();

    void setAttuale();

    void eliminaSalvataggi(GestoreFile &gf);

    void resetta(GestoreFile &gf);

    void caricaSalvataggi(GestoreFile &gf);

  public:
    // puntatore al livello in cui si trova il protagonista
    pliv attuale;
    
    Gioco();

    Gioco(GestoreFile &gf, bool reset = true);

    void aggiungiLivello(Livello livello);

    bool muoviAvanti();

    bool muoviIndietro();

    void salva(GestoreFile &gf);

    void rimuoviNemici();
};

#endif