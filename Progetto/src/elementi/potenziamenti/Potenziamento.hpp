/*
 Classe padre per tutti i potenziamenti
*/

#ifndef POTENZIAMENTO_HPP
#define POTENZIAMENTO_HPP

#include "../../util/Stringa.hpp"

class Potenziamento {
  
  protected:
    // nome del potenziamento
    Stringa nome;
    // costo per l'acquisto
    int costo;
    // numero di turni in cui permane l'effetto
    int durata;

  public:
    Potenziamento(Stringa nome, int costo = 0, int durata = 0);

    Stringa getNome();

    int getCosto();

    int getDurata();

    void riduciDurata();
};

#endif