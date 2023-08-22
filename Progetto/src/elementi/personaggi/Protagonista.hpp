/*
 Classe che definisce il protagonista controllato dall'utente
*/

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include "../armi/Bastone.cpp"
#include "../armi/Spada.cpp"
#include "../armi/PallaChiodata.cpp"
#include "../armi/Arco.cpp"
#include "../potenziamenti/UltraDanno.cpp"
#include "../potenziamenti/SuperScudo.cpp"
#include "../../util/Stringa.hpp"
#include "../../util/GestoreFile.hpp"

class Protagonista {
  
  protected:
    // nome del protagonista
    Stringa nome;
    // simbolo del protagonista
    char simbolo;
    // vita residua
    int vita;
    // denaro disponibile
    int denaro;
    // arma equipaggiata
    Arma arma = Arma();
    // durata residua del potenziamento
    Potenziamento potenziamento = Potenziamento(Stringa((char*) "tmp"));
    // punti ottenuti
    int punti;
    // coordinate (x, y) della posizione a schermo
    int x, y;
    // se true il protagonista è rivolto a destra, false a sinistra
    bool versoDestra;
  
  public:
    Protagonista();

    Protagonista(GestoreFile &gf);

    Stringa getNome();

    char getSimbolo();

    int getVita();

    int getDenaro();

    Arma getArma();

    Potenziamento getPotenziamento();

    int getPunti();

    int getX();

    int getY();

    bool isVersoDestra();
    
    void setX(int x);

    void setY(int y);

    void setVersoDestra(bool verso);

    void aumentaVita(int vita);

    bool prendiDanno(int danno);

    int infliggiDanno();

    void guadagna(int soldi);

    bool spendi(int soldi);

    void cambiaArma(Arma a);

    void cambiaPotenziamento(Potenziamento p);

    void riduciDurataPot();

    void aggiungiPunti(int p);

    void muoviDx(int spost = 1);

    void muoviSx(int spost = 1);

    void muoviGiu(int spost = 1);

    void salta(int spost = 1);

    void resetPosizione();

    void rigenera();

    void salva(GestoreFile &gf);
};

#endif