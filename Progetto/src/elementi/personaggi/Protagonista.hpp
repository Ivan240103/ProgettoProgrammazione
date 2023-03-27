/*
 Classe che definisce il protagonista controllato dall'utente
*/

#include <cstring>
#include "../armi/Arma.hpp"
#include "../armi/Bastone.hpp"

#define NOME_PROT 30

class Protagonista {
  
  protected:
    char nome[NOME_PROT];
    int vita;
    int denaro;
    Arma arma = NULL;
  
  public:
    // costruttore
    Protagonista(char nome[]) {
      strncpy(this->nome, nome, NOME_PROT);
      this->vita = 100;
      this->denaro = 0;
      this->arma = Bastone();
    }

    void getNome(char n[]) {
      strncpy(n, nome, NOME_PROT);
    }

    int getVita() {
      return vita;
    }

    int getDenaro() {
      return denaro;
    }

    Arma getArma() {
      return arma;
    }

    void guadagna(int soldi) {
      denaro += soldi;
    }

    // Postcondition: false se il denaro non è sufficiente, true se tutto apposto
    bool spendi(int soldi) {
      bool tr = false;
      if (soldi <= denaro) {
        denaro -= soldi;
        tr = true;
      }
      return tr;
    }

    void cambiaArma(Arma a) {
      arma = a;
    }
};