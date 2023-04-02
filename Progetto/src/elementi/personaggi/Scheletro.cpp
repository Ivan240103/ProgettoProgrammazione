/*
 Nemico Scheletro
 Causa danno solo tramite contatto
*/

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Scheletro : public Nemico {

  protected:
    char nome[15] = "Scheletro";
  
  public:
    // costruttore
    Scheletro() : Nemico(Stringa(nome), 10, 2, 4, false, 3) {}
};