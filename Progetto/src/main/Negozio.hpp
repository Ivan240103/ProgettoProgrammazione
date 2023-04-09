/*
 Classe che gestisce il negozio
 Nel negozio è possibile acquistare armi, vita e/o potenziamenti
 Gli oggetti sono sempre acquistabili (inesauribili)
*/

#ifndef NEGOZIO_HPP
#define NEGOZIO_HPP

#include "../elementi/armi/Arma.hpp"
#include "../elementi/armi/Spada.cpp"
#include "../elementi/armi/PallaChiodata.cpp"
#include "../elementi/armi/Arco.cpp"

const int NUM_ARMI = 3;

class Negozio {
  
  protected:
    Arma armi[NUM_ARMI] = {
      Spada(),
      PallaChiodata(),
      Arco()
    };

  public:

    Negozio();

    Arma vendiArma(int position);

    Stringa mostraArticoli();
};

#endif