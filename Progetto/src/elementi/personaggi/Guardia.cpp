/*
 Nemico Guardia
 Causa danno a distanza
*/

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Guardia : public Nemico {

  protected:
    char nome[10] = "Guardia";
  
  public:
    // costruttore
    Guardia() : Nemico(Stringa(nome), 40, 5, 8, true, 10) {}
};