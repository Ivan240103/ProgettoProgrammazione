/*
 Classe che definisce il protagonista controllato dall'utente
*/

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include "../armi/Arma.hpp"
#include "../armi/Bastone.cpp"
#include "../../util/Stringa.hpp"

class Protagonista {
  
  protected:
    Stringa nome;
    int vita;
    int denaro;
    Arma arma = Bastone();
  
  public:

    Protagonista(Stringa nome);

    Stringa getNome();

    int getVita();

    int getDenaro();

    Arma getArma();

    void guadagna(int soldi);

    bool spendi(int soldi);

    void cambiaArma(Arma a);
};

#endif