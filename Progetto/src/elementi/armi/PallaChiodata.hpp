/*
 Arma PallaChiodata
 Colpisce tutte le caselle intorno al protagonista
*/

#include "Arma.hpp"

class PallaChiodata : public Arma {
  
  public:
    // costruttore
    PallaChiodata() : Arma("Palla Chiodata", 12, 750, false, true) {}
};