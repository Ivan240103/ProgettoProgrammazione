/*
 Classe padre per tutti i nemici del gioco
 Tutti i nemici causano danno se ci si entra in contatto
 Il danno causato è casuale tra un valore minimo e massimo
*/

#include <cstring>
#include <cstdlib>
#include <ctime>

#define NOME_NEM 20

class Nemico {
  
  protected:
    char nome[NOME_NEM];
    int vita;
    int danno;
    // se è true il nemico può colpire a distanza
    bool distanza;
    // denaro dato al protagonista dopo l'uccisione
    int ricompensa;

  public:
    // costruttore
    Nemico(char nome[], int vita = 10, int minDanno = 1, int maxDanno = 1, bool distanza = false, int ricompensa = 2) {
      strncpy(this->nome, nome, NOME_NEM);
      this->vita = vita;
      srand(time(0));
      this->danno = rand() % (maxDanno - minDanno + 1) + minDanno;
      this->distanza = distanza;
      this->ricompensa = ricompensa;
    }

    void getNome(char n[]) {
      strncpy(n, nome, NOME_NEM);
    }

    int getVita() {
      return vita;
    }

    int getDanno() {
      return danno;
    }

    bool isDistanza() {
      return distanza;
    }

    int getRicompensa() {
      return ricompensa;
    }
};