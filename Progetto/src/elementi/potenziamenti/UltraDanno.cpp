/*
 classe Ultradanno
 il danno del protagonista oneshotta i nemici
*/

#ifndef ULTRADANNO_CPP
#define ULTRADANNO_CPP

#include "Potenziamento.hpp"
#include "../../util/Stringa.hpp"

class UltraDanno : public Potenziamento {
  
  public:
    // costruttore
    UltraDanno() : Potenziamento(Stringa((char*) "UltraDanno"), 150, 5) {}
};

#endif