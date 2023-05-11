/*
 Classe padre per tutte le armi del gioco
*/

#ifndef ARMA_HPP
#define ARMA_HPP

#include "../../util/Stringa.hpp"

class Arma {
  
  protected:
    Stringa nome;
    // danno causabile
    int danno;
    // costo per l'acquisto al negozio
    int costo;
    // se è true l'arma può colpire a distanza
    bool distanza;
    // se è true l'arma colpisce tutte le caselle intorno
    bool intorno;
    // coefficiente per calcolare la difficoltà del livello iniziale
    int coeff;

  public:
    Arma(
      Stringa nome,
      int danno = 5,
      int costo = 0,
      bool distanza = false,
      bool intorno = false,
      int coeff = 1
    );

    Stringa getNome();

    int getDanno();

    int getCosto();

    bool isDistanza();

    bool isIntorno();

    int getCoeff();

    // DEBUG: rimuovere quando non servirà più
    Stringa toString();
};

#endif