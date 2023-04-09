/*
 Arma Arco
 Colpisce a distanza
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Arco : public Arma {

  public:
    // costruttore
    Arco() : Arma(Stringa((char*) "Arco"), 10, 1000, true, false) {}
};