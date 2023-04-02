/*
 Arma Spada
 Causa più danni del bastone
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Spada : public Arma {
  
  protected:
    char nome[10] = "Spada";
  
  public:
    // costruttore
    Spada() : Arma(Stringa(nome), 15, 300, false, false) {}
};