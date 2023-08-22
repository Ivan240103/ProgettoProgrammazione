/*
 Classe SuperScudo
 Quando attivo, il protagonista non subisce danno
*/

#ifndef SUPERSCUDO_CPP
#define SUPERSCUDO_CPP

#include "Potenziamento.hpp"
#include "../../util/Stringa.hpp"

class SuperScudo : public Potenziamento {
  
  public:
    // costruttore
    SuperScudo(int durata) : Potenziamento(Stringa((char*) "SuperScudo"), 200, durata) {
      if (durata == 3) {
        this->costo = 500;
      }
    }
};

#endif