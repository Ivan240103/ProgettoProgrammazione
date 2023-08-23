/*
 Arma PallaChiodata
 Colpisce tutte le caselle adiacenti al protagonista
*/

#ifndef PALLACHIODATA_CPP
#define PALLACHIODATA_CPP

#include "Arma.hpp"

class PallaChiodata : public Arma {

  public:
    // costruttore
    PallaChiodata() : Arma(Stringa((char*) "PallaChiodata"), 12, 750) {}
};

#endif