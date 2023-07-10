/*
 Classe padre per tutti i nemici del gioco
 Tutti i nemici causano danno se ci si entra in contatto
 Il danno causato è casuale tra un valore minimo e massimo
*/

#ifndef NEMICO_HPP
#define NEMICO_HPP

#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "../../util/Stringa.hpp"

class Nemico {
  
  protected:
    // nome del nemico
    Stringa nome;
    //Simbolo del personaaggio
    char simbolo;
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
    //variabile per vedere se la edstra o la sinistra è libera
    bool sx;
  public:
    Nemico(
      Stringa nome,
      char simbolo = ' ',
      int vita = 10,
      int minDanno = 1,
      int maxDanno = 1,
      bool distanza = false,
      int ricompensa = 20,
      int x=1 ,
      int y=1,
      bool sx=true
    );

    Stringa getNome();

    char getSimbolo();

    bool getSx();

    void setSx(bool valore);

    int getVita();

    int getDanno();

    bool isDistanza();

    int getRicompensa();

    int getX();

    void setX(int x);

    void setY(int y);

    void MuoviSuGiu(int sposta);

    int getY();

    bool prendiDanno(int danno);

    void muoviDx(int spost = 1);

    void muoviSx(int spost = 1);

    // DEBUG: rimuovere quando non servirà più
    Stringa toString();

    Stringa getData();
};

#endif