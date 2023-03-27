/*
 Classe padre per tutti i potenziamenti
*/

#include <cstring>

#define NOME_POT 20

class Potenziamento {
  
  protected:
    char nome[NOME_POT];
    int costo;
    int durata;

  public:
    // costruttore
    Potenziamento(char nome[], int costo, int durata) {
      strncpy(this->nome, nome, NOME_POT);
      this->costo = costo;
      this->durata = durata;
    }  
};