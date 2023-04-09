/*
 Arma Bastone 
 Default del protagonista
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Bastone : public Arma {

  public:
    // costruttore
    Bastone() : Arma(Stringa((char*) "Bastone"), 5, 100, false, false) {}
};