/*
 Arma Arco
 Colpisce a distanza
*/

#include "Arma.hpp"

class Arco : public Arma {
  
  public:
    // costruttore
    Arco() : Arma("Arco", 10, 1000, true, false) {}
};