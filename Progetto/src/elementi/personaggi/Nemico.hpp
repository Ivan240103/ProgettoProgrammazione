/*
 Classe padre per tutti i nemici del gioco
 Tutti i nemici causano danno se ci si entra in contatto
 Il danno causato è casuale tra un valore minimo e massimo
*/

#ifndef NEMICO_HPP
#define NEMICO_HPP

#include <cstdlib>
#include "../../util/Stringa.hpp"

class Nemico {
  
  protected:
    // nome del nemico
    Stringa nome;
    // simbolo del personaaggio a schermo
    char simbolo;
    // vita residua
    int vita;
    // danno causabile
    int danno;
    // denaro dato al protagonista dopo l'uccisione
    int ricompensa;
    // coordinate (x,y) della posizione a schermo
    int x, y;
    // variabile per vedere se la destra o la sinistra è libera
    bool sx;

  public:
    Nemico(
      Stringa nome,
      char simbolo = '?',
      int vita = 10,
      int minDanno = 1,
      int maxDanno = 1,
      int ricompensa = 20,
      int x = 1 ,
      int y = 1,
      bool sx = true
    );

    Stringa getNome();

    char getSimbolo();

    int getVita();

    int getDanno();

    int getRicompensa();

    int getX();

    int getY();

    bool getSx();

    void setX(int x);

    void setY(int y);

    void setSx(bool valore);

    bool prendiDanno(int danno);

    void MuoviSuGiu(int sposta);

    void muoviDx(int spost = 1);

    void muoviSx(int spost = 1);

    Stringa getData();
};

#endif