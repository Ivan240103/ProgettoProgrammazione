/*
 Classe che definisce il protagonista controllato dall'utente
*/

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include "../armi/Bastone.cpp"
#include "../armi/Spada.cpp"
#include "../armi/PallaChiodata.cpp"
#include "../armi/Arco.cpp"
#include "../../util/Stringa.hpp"
#include "../../util/GestoreFile.hpp"

class Protagonista {
  
  protected:
    // nome del protagonista
    Stringa nome;
    // vita residua
    int vita;
    // denaro disponibile
    int denaro;
    // arma equipaggiata
    Arma arma = Arma(Stringa((char*) "tmp"));
    // punti ottenuti
    int punti;
    // coordinate (x, y) della posizione a schermo
    int x, y;
    // se true il protagonista è rivolto a destra, false a sinistra
    bool versoDestra;
  
  public:
    Protagonista(GestoreFile &gf);

    Stringa getNome();

    int getVita();

    int getDenaro();

    Arma getArma();

    int getPunti();

    int getX();

    int getY();

    bool isVersoDestra();

    int getDifficolta();

    bool prendiDanno(int danno);

    int infliggiDanno();

    void guadagna(int soldi);

    bool spendi(int soldi);

    void cambiaArma(Arma a);

    void aggiungiPunti(int p);

    void muoviDx(int spost = 1);

    void muoviSx(int spost = 1);

    void salta(int spost = 1);

    void resetPosizione();

    void rigenera();

    // DEBUG: rimuovere quando non servirà più
    Stringa toString();

    void salva(GestoreFile &gf);
};

#endif