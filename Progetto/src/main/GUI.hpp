/*
Classe per gestire la grafica del gioco
*/

#ifndef GUI_HPP
#define GUI_HPP

#include <ncurses.h>

#include "../util/GestoreFile.hpp"
#include "../util/Stringa.hpp"
#include "../elementi/personaggi/Protagonista.hpp"
#include "Negozio.hpp"


class GUI{

    protected:
     int altezza = 22, larghezza = 72;
     char personaggio = '@';
    
    public:

    GestoreFile gf = GestoreFile();
    Protagonista p = Protagonista(gf);
    Negozio n = Negozio();
    
    WINDOW* creaFinestra();

    GUI();

    void stampaPersonaggio(WINDOW *finestra, int y, int x);

    void stampaMappa(WINDOW* win);

    void creaMappa(int det, int mv, WINDOW* win);

    int getmv(WINDOW* finestra);
    
    void mvup(WINDOW* finestra);

    void mvleft(WINDOW* finestra);

    void mvright(WINDOW* finestra);

    void mvdown(WINDOW* finestra);

    void gravita(WINDOW* finestra);
};

#endif