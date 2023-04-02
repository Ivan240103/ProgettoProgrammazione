/*
 Arma Bastone 
 Default del protagonista
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class Bastone : public Arma {
  
  protected:
    char nome[10] = "Bastone";
  
  public:
    // costruttore
    Bastone() : Arma(Stringa(nome), 5, 100, false, false) {}
};