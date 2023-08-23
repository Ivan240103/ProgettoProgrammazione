/*
 Nemico Goblin
 Insegue il protagonista, non può saltare
 Causa danno a contatto
*/

#ifndef GOBLIN_CPP
#define GOBLIN_CPP

#include "Nemico.hpp"

class Goblin : public Nemico {

  public:
    // costruttore
    Goblin(int x = 3, int y = 3) : Nemico(Stringa((char*) "Goblin"), 'S', 10, 2, 5, 15, x, y, true) {}
};

#endif