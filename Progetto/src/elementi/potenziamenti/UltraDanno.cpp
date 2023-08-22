/*
 Classe UltraDanno
 Quando attivo, il protagonista uccide i nemici in un colpo solo
*/

#ifndef ULTRADANNO_CPP
#define ULTRADANNO_CPP

#include "Potenziamento.hpp"
#include "../../util/Stringa.hpp"

class UltraDanno : public Potenziamento {
  
  public:
    // costruttore
    UltraDanno(int durata) : Potenziamento(Stringa((char*) "UltraDanno"), 200, durata) {
      if (durata == 3) {
        this->costo = 500;
      }
    }
};

#endif