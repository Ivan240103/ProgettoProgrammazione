/*
 Arma PallaChiodata
 Colpisce tutte le caselle intorno al protagonista
*/

#include "Arma.hpp"
#include "../../util/Stringa.hpp"

class PallaChiodata : public Arma {
  
  protected:
    char nome[20] = "Palla Chiodata";
  
  public:
    // costruttore
    PallaChiodata() : Arma(Stringa(nome), 12, 750, false, true) {}
};