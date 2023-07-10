/*
 Nemico freccia
 Causa danno a distanza
*/

#ifndef FRECCIA_CPP
#define FRECCIA_CPP

#include <ncurses.h>
#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Freccia : public Nemico {

  public:
    // costruttore
    Freccia(int x=1 , int y=1, char simbolo = '-', bool sx = true ) : Nemico(Stringa((char*) "Freccia"), simbolo, 1, 2, 4, false, 10, x, y, sx) {}
};

#endif