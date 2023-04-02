/*
 Classe padre per tutte le armi del gioco
*/

#ifndef ARMA_HPP
#define ARMA_HPP

#include "../../util/Stringa.hpp"

class Arma {
  
  protected:
    Stringa nome;
    int danno;
    int costo;
    // se è true l'arma può colpire a distanza
    bool distanza;
    // se è true l'arma colpisce tutte le caselle intorno
    bool intorno;

  public:
    
    Arma(Stringa nome, int danno, int costo, bool distanza, bool intorno);

    Stringa getNome();

    int getDanno();

    int getCosto();

    bool isDistanza();

    bool isIntorno();
};

#endif