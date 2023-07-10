/*
Classe per gestire la grafica del gioco
*/

#ifndef GUI_HPP
#define GUI_HPP

#include <ncurses.h>

#include "../util/GestoreFile.hpp"
#include "../util/Stringa.hpp"
#include "../elementi/personaggi/Protagonista.hpp"
#include "../elementi/personaggi/Nemico.hpp"
#include "../elementi/personaggi/Goblin.cpp"
#include "../elementi/personaggi/Guardia.cpp"
#include "../elementi/personaggi/Scheletro.cpp"
#include "../elementi/personaggi/Freccia.cpp"
#include "Negozio.hpp"
#include "Livello.hpp"
#include "Gioco.hpp"
#include "../elementi/personaggi/Nemico.hpp"

class GUI{

    protected:
     int altezza = 22, larghezza = 72;
     char personaggio = '@';
    
    public:

    GestoreFile gf = GestoreFile();
    Protagonista p = Protagonista(gf);
    Negozio n = Negozio(p);
    Livello l;
    Stringa string = Stringa();
    Gioco game = Gioco();
    
    WINDOW* creaFinestra();

    GUI();

    void stampaPersonaggio(WINDOW *finestra, int y, int x);

    void creaNemico(WINDOW* finestra, int y, int x, int random);

    void stampaMappa(WINDOW* win);

    void creaMappa(int det, int mv, WINDOW* win);

    int getmv(WINDOW* finestra);

    void movimentiNemico(WINDOW* finestra);
    
    void mvup(WINDOW* finestra);

    void mvleft(WINDOW* finestra);

    void mvright(WINDOW* finestra);

    void mvdown(WINDOW* finestra);

    void gioco(WINDOW* finestra);

    void esci(WINDOW* finestra);

    void attacco(Arma arma, WINDOW* finestra);

    void attaccoBastone(Arma arma,WINDOW* finestra);

    void controlloCasella(WINDOW* finestra, int ch, Arma arma, int y, int x);

    void attaccoPalla(Arma arma,WINDOW* finestra);

    void attaccoSpada(Arma arma,WINDOW* finestra);

    void attaccoArco(Arma arma,WINDOW* finestra);
};

#endif