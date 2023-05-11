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
    // testa della lista bidir dinamica dei livelli
    pliv hlivelli;
    // puntatore al livello in cui si trova il protagonista
    pliv attuale;

    void creaLivello(int id = 1);

    void aggiungiLivello(Livello livello);

    void setAttuale();

    void eliminaSalvataggi(GestoreFile &gf);

    void resetta(int diffPrimoLivello, GestoreFile &gf);

    void caricaSalvataggi(GestoreFile &gf);

  public:
    Gioco();

    Gioco(GestoreFile &gf, bool reset = true, int diffPrimoLivello = 1);

    bool muoviAvanti();

    bool muoviIndietro();

    void salva(GestoreFile &gf);

    void rimuoviNemici();

    // DEBUG: rimuovere quando non servirà più
    void debug();

    // DEBUG: rimuovere quando non servirà più
    bool attaccaNemico(int dannoSubito);

    // DEBUG: rimuovere quando non servirà più
    Nemico getPrimoNemico();
};

#endif