/*
Classe per gestire la grafica del gioco
*/

#ifndef GUI_HPP
#define GUI_HPP

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Gioco.hpp"
#include "Livello.hpp"
#include "Negozio.hpp"
#include "../elementi/personaggi/Protagonista.hpp"
#include "../elementi/personaggi/Nemico.hpp"
#include "../elementi/personaggi/Goblin.cpp"
#include "../elementi/personaggi/Scheletro.cpp"
#include "../elementi/personaggi/Freccia.cpp"
#include "../elementi/personaggi/Guardia.cpp"
#include "../util/GestoreFile.hpp"

class GUI{

    protected:
        // altezza e larghezza della finestra di gioco
        int altezza = 22, larghezza = 72;
        // TODO: a cosa servono hit e isJump ???
        bool hit = false, isJump = false;
        // TODO: a cosa serve contSalto ???
        int contSalto = 0;

        GestoreFile gf = GestoreFile();
        Protagonista p = Protagonista(gf);
        Gioco game;

        void creaMappa(int det, int mv, WINDOW* win, bool nuovo = false);

        void stampaMappa(WINDOW* win, bool nuovo = false);

        void stampaProtagonista(WINDOW *finestra, int y, int x);

        void creaNemico(WINDOW* finestra, int y, int x, int random);

        void stampaNemici(WINDOW* finestra);

        bool getAction(WINDOW* finestra);
        
        void mvup(WINDOW* finestra);

        void mvleft(WINDOW* finestra);

        void mvright(WINDOW* finestra);

        void mvdown(WINDOW* finestra);

        void movimentiNemico(WINDOW* finestra);

        void attacco(WINDOW* finestra);

        void attaccoBastone(WINDOW* finestra);

        void attaccoSpada(WINDOW* finestra);

        void attaccoPalla(WINDOW* finestra);

        void attaccoArco(WINDOW* finestra);

        void controlloCasella(WINDOW* finestra, int ch, int y, int x);
        
        void esci(WINDOW* finestra, bool morto);
    
    public:

        GUI();
        
        WINDOW* creaFinestra();

        void gioco(WINDOW* finestra);
};

#endif