/*
 Arma Bastone 
 Default del protagonista
*/

#ifndef BASTONE_CPP
#define BASTONE_CPP

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Bastone : public Arma {

  public:
    // costruttore
    Bastone() : Arma(Stringa((char*) "Bastone"), 5, 0) {}
};

#endif