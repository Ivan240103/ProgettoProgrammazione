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
    // per salvare e caricare i dati
    GestoreFile gf;
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
    // se true il protagonista è rivolto a destra, false a sinistra
    bool versoDestra;
  
  public:
    Protagonista();

    Stringa getNome();

    int getVita();

    int getDenaro();

    Arma getArma();

    int getPunti();

    bool isVersoDestra();

    int getDifficolta();

    bool prendiDanno(int danno);

    int infliggiDanno();

    void guadagna(int soldi);

    bool spendi(int soldi);

    void cambiaArma(Arma a);

    void aggiungiPunti(int p);

    void rigenera();

    Stringa toString();

    void salva();
};

#endif