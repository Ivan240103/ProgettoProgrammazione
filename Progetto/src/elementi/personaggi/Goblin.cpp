/*
 Nemico Goblin
 Causa danno a contatto
*/

#ifndef GOBLIN_CPP
#define GOBLIN_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Goblin : public Nemico {

  public:
    // costruttore
    Goblin(int x = 1, int y = 1) : Nemico(Stringa((char*) "Goblin"), 'S', 10, 2, 4, 15, x, y, true) {}
};

#endif