/*
 Classe che gestisce il negozio
 Nel negozio è possibile acquistare armi, vita e/o potenziamenti
 Gli oggetti sono sempre acquistabili (inesauribili)
*/

#ifndef NEGOZIO_HPP
#define NEGOZIO_HPP

#include <ncurses.h>
#include "../elementi/armi/Spada.cpp"
#include "../elementi/armi/PallaChiodata.cpp"
#include "../elementi/armi/Arco.cpp"
#include "../elementi/potenziamenti/UltraDanno.cpp"
#include "../elementi/potenziamenti/SuperScudo.cpp"
#include "../elementi/personaggi/Protagonista.hpp"

class Negozio {
  
  protected:
    // puntatore al protagonista
    Protagonista* pr;
    Spada s = Spada();
    PallaChiodata p = PallaChiodata();
    Arco a = Arco();
    UltraDanno u1 = UltraDanno(1);
    UltraDanno u3 = UltraDanno(3);
    SuperScudo ss1 = SuperScudo(1);
    SuperScudo ss3 = SuperScudo(3);

    void stampaInfo(WINDOW* finestra);

    void stampaNegozio(int standout, WINDOW* finestra);
    
    void stampaArmi(int standout, WINDOW* finestra);

    void stampaPotenziamenti(int standout, WINDOW* finestra);

    void stampaVita(int standout, WINDOW* finestra);

    void caratteristiche(int articolo, WINDOW* finestra);

    bool armiNegozio(WINDOW* finestra, int &scelta);

    bool potenziamentiNegozio(WINDOW* finestra, int &scelta);

    bool vitaNegozio(WINDOW* finestra, int &scelta);

    void cancellaMenu(WINDOW* finestra);

  public:
    Negozio();

    Negozio(Protagonista* pr);

    void creaNegozio();
};

#endif