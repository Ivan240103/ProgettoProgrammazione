/*
 Classe che gestisce il negozio
 Nel negozio è possibile acquistare armi, vita e/o potenziamenti
 Gli oggetti sono sempre acquistabili (inesauribili)
*/

#include "../elementi/armi/Spada.hpp"
#include "../elementi/armi/PallaChiodata.hpp"
#include "../elementi/armi/Arco.hpp"

#define NUM_ARMI 3

class Negozio {
  
  protected:
    Arma armi[NUM_ARMI] = {
      Spada(),
      PallaChiodata(),
      Arco()
    };

  public:
    // costruttore
    Negozio() {}

    // Postcondition: arma dalla posizione scelta
    Arma vendiArma(int position) {
      return armi[position];
    }
};
