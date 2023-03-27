/*
 Arma Spada
 Causa più danni del bastone
*/

#include "Arma.hpp"

class Spada : public Arma {
  
  public:
    // costruttore
    Spada() : Arma("Spada", 15, 300, false, false) {}
};