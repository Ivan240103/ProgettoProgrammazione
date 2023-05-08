/*
 Classe per gestire la partita
*/

#ifndef GIOCO_HPP
#define GIOCO_HPP

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
    // per salvare i dati su file
    GestoreFile gf;
    // testa della lista bidir dinamica dei livelli
    pliv hlivelli;
    // puntatore al livello in cui si trova il protagonista
    pliv attuale;

    void aggiungiLivello(int id = 1);

    void eliminaSalvataggi();

  public:
    Gioco(bool reset = true, int diffPrimoLivello = 1);

    void muoviAvanti();

    void muoviIndietro();

    void salva();

    void debug();
};

#endif