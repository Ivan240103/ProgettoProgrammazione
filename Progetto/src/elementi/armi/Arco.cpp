/*
 Arma Arco
 Colpisce a distanza
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Arco : public Arma {
  
  protected:
    char nome[10] = "Arco";

  public:
    // costruttore
    Arco() : Arma(Stringa(nome), 10, 1000, true, false) {}
};