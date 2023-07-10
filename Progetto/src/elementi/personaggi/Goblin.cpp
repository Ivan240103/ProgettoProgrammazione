/*
 Nemico Goblin
 Causa danno nelle caselle adiacenti dx e sx (una sola alla volta)
*/

#ifndef GOBLIN_CPP
#define GOBLIN_CPP

#include <ncurses.h>
#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Goblin : public Nemico {

  public:
    // costruttore
    Goblin(int x=1 , int y=1 ) : Nemico(Stringa((char*) "Goblin"),'S', 20, 4, 6, false, 30, x, y, true) {}
};

#endif