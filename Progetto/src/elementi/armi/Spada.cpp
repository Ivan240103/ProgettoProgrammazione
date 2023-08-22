/*
 Arma Spada
 Colpisce le due caselle adiacenti orizzontalmente
*/

#ifndef SPADA_CPP
#define SPADA_CPP

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Spada : public Arma {
  
  public:
    // costruttore
    Spada() : Arma(Stringa((char*) "Spada"), 15, 300) {}
};

#endif