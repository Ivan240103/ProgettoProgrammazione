/*
 Classe padre per tutte le armi del gioco
*/

#include <cstring>

#define NOME_ARMA 20

class Arma {
  
  protected:
    char nome[NOME_ARMA];
    int danno;
    int costo;
    // se è true l'arma può colpire a distanza
    bool distanza;
    // se è true l'arma colpisce tutte le caselle intorno
    bool intorno;

  public:
    // costruttore
    Arma(char nome[], int danno = 5, int costo = 100, bool distanza = false, bool intorno = false) {
      strncpy(this->nome, nome, NOME_ARMA);
      this->danno = danno;
      this->costo = costo;
      this->distanza = distanza;
      this->intorno = intorno;
    }

    void getNome(char n[]) {
      strncpy(n, this->nome, NOME_ARMA);
    }

    int getDanno() {
      return danno;
    }

    int getCosto() {
      return costo;
    }

    bool isDistanza() {
      return distanza;
    }

    bool isIntorno() {
      return intorno;
    }
};