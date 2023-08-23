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
    // costo per l'acquisto al negozio
    int costo;
    // numero di livelli in cui agisce
    int durata;

  public:
    Potenziamento();

    Potenziamento(
      Stringa nome,
      int costo = 0,
      int durata = 0
    );

    Stringa getNome();

    int getCosto();

    int getDurata();

    void riduciDurata();
};

#endif