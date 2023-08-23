/*
 Classe padre per tutte le armi del gioco
*/

#ifndef ARMA_HPP
#define ARMA_HPP

#include "../../util/Stringa.hpp"

class Arma {
  
  protected:
    // nome dell'arma
    Stringa nome;
    // danno causabile
    int danno;
    // costo per l'acquisto al negozio
    int costo;

  public:
    Arma();

    Arma(
      Stringa nome,
      int danno = 5,
      int costo = 0
    );

    Stringa getNome();

    int getDanno();

    int getCosto();
};

#endif