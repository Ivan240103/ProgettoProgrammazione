/*
 Classe per gestire l'insieme dei livelli
 Contiene la lista dinamica dei livelli (bidirezionale)
*/

#ifndef GIOCO_HPP
#define GIOCO_HPP

#include <cstdlib>
#include "Livello.hpp"

class Gioco {
  
  struct liv {
    Livello l = Livello();
    liv* succ = NULL;
    liv* prec = NULL;
  };

  typedef liv* pliv;

  protected:
    // testa della lista dei livelli
    pliv hlivelli;

    bool cercaIdLivello(int id);

    void creaLivello();

    void aggiungiLivello(Livello livello);

    void setAttuale();

    void eliminaSalvataggi(GestoreFile &gf);

    void resetta(GestoreFile &gf);

    void caricaSalvataggi(GestoreFile &gf);

  public:
    // puntatore al livello in cui si trova il protagonista
    pliv attuale;
    
    Gioco();

    Gioco(
      GestoreFile &gf,
      bool reset = true
    );

    bool muoviAvanti();

    bool muoviIndietro();

    void rimuoviNemici();

    int numeroLivelli();

    void salva(GestoreFile &gf);
};

#endif