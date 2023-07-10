/*
 Classe che gestisce il negozio
 Nel negozio è possibile acquistare armi, vita e/o potenziamenti
 Gli oggetti sono sempre acquistabili (inesauribili)
*/

#ifndef NEGOZIO_HPP
#define NEGOZIO_HPP

#include <ncurses.h>
#include "../elementi/armi/Arma.hpp"
#include "../elementi/armi/Spada.cpp"
#include "../elementi/armi/PallaChiodata.cpp"
#include "../elementi/armi/Arco.cpp"
#include "../elementi/potenziamenti/Potenziamento.hpp"
#include "../elementi/potenziamenti/UltraDanno.cpp"
#include "../elementi/personaggi/Protagonista.hpp"
#include "../util/GestoreFile.hpp"

const int NUM_ARMI = 3;

class Negozio {
  
  protected:
    Arma armi[NUM_ARMI] = {
      Spada(),
      PallaChiodata(),
      Arco()
    };

  public:

    Negozio(Protagonista pr);
    Spada s = Spada();
    PallaChiodata p = PallaChiodata();
    Arco a = Arco();
    UltraDanno u = UltraDanno();
    GestoreFile gf = GestoreFile();
    Protagonista pr = Protagonista(gf);

    void stampaNegozio(WINDOW* negozio);
    
    void stampaArmi(WINDOW* negozio);

    void armiNegozio(WINDOW* negozio, int &scelta);

    void stampaPotenziamenti(WINDOW* negozio);

    void potenziamentiNegozio(WINDOW* negozio, int &scelta);

    void vitaNegozio(WINDOW* negozio, int &scelta);

    void stampaVita(WINDOW* negozio);

    void caratteristiche(int scelta, WINDOW* negozio);

    void creaNegozio();

    void cancellaMenu(WINDOW* negozio);

    Arma vendiArma(int position);

    Stringa mostraArticoli();
};

#endif