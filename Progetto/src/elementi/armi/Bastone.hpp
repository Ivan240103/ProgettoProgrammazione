/*
 Arma Bastone 
 Default del protagonista
*/

#include "Arma.hpp"

class Bastone : public Arma {
  
  public:
    // costruttore
    Bastone() : Arma("Bastone", 5, 100, false, false) {}
};