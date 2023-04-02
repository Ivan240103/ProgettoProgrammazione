/*
 Classe padre per tutti i potenziamenti
*/

#ifndef POTENZIAMENTO_HPP
#define POTENZIAMENTO_HPP

#include "../../util/Stringa.hpp"

class Potenziamento {
  
  protected:
    Stringa nome;
    int costo;
    int durata;

  public:
    Potenziamento(Stringa nome, int costo, int durata);
};

#endif