/*
 Classe che definisce il protagonista controllato dall'utente
*/

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include "../armi/Bastone.cpp"
#include "../../util/Stringa.hpp"

class Protagonista {
  
  protected:
    Stringa nome;
    int vita;
    int denaro;
    Arma arma = Arma();
    // se true il protagonista è rivolto a destra, false a sinistra
    bool versoDestra;
  
  public:

    Protagonista(Stringa nome);

    Stringa getNome();

    int getVita();

    int getDenaro();

    Arma getArma();

    bool isVersoDestra();

    void guadagna(int soldi);

    bool spendi(int soldi);

    void cambiaArma(Arma a);

    Stringa toString();

    Stringa getData();
};

#endif