/*
 Classe padre per tutti i nemici del gioco
 Tutti i nemici causano danno se ci si entra in contatto
 Il danno causato è casuale tra un valore minimo e massimo
*/

#ifndef NEMICO_HPP
#define NEMICO_HPP

#include <cstdlib>
#include <ctime>
#include "../../util/Stringa.hpp"

class Nemico {
  
  protected:
    // nome del nemico
    Stringa nome;
    // vita residua
    int vita;
    // danno causabile
    int danno;
    // se è true il nemico può colpire a distanza
    bool distanza;
    // denaro dato al protagonista dopo l'uccisione
    int ricompensa;
    // coordinate (x,y) della posizione a schermo
    int x, y;

  public:
    Nemico(
      Stringa nome,
      int vita = 10,
      int minDanno = 1,
      int maxDanno = 1,
      bool distanza = false,
      int ricompensa = 20,
      int x = 1,
      int y = 1
    );

    Stringa getNome();

    int getVita();

    int getDanno();

    bool isDistanza();

    int getRicompensa();

    int getX();

    int getY();

    bool prendiDanno(int danno);

    void muoviDx(int spost = 1);

    void muoviSx(int spost = 1);
    
    void salta(int spost = 1);

    // DEBUG: rimuovere quando non servirà più
    Stringa toString();

    Stringa getData();
};

#endif