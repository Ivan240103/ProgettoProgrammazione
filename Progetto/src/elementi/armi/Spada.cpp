/*
 Arma Spada
 Causa più danni del bastone
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Spada : public Arma {
  
  public:
    // costruttore
    Spada() : Arma(Stringa((char*) "Spada"), 15, 300, false, false) {}
};