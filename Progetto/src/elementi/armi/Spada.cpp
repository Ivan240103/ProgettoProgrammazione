/*
 Arma Spada
 Colpisce le due caselle verso cui è rivolto il protagonista orizzontalmente
*/

#ifndef SPADA_CPP
#define SPADA_CPP

#include "Arma.hpp"

class Spada : public Arma {
  
  public:
    // costruttore
    Spada() : Arma(Stringa((char*) "Spada"), 15, 300) {}
};

#endif