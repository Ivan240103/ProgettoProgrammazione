/*
 Arma PallaChiodata
 Colpisce tutte le caselle intorno al protagonista
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class PallaChiodata : public Arma {

  public:
    // costruttore
    PallaChiodata() : Arma(Stringa((char*) "PallaChiodata"), 12, 750, false, true) {}
};