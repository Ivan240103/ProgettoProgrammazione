/*
 Arma Arco
 Colpisce a distanza
*/

#ifndef ARCO_CPP
#define ARCO_CPP

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Arco : public Arma {

  public:
    // costruttore
    Arco() : Arma(Stringa((char*) "Arco"), 10, 1000) {}
};

#endif