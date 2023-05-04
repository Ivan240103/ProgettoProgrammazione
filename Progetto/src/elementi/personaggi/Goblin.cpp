/*
 Nemico Goblin
 Causa danno nelle caselle adiacenti dx e sx (una sola alla volta)
*/

#ifndef GOBLIN_CPP
#define GOBLIN_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Goblin : public Nemico {

  public:
    // costruttore
    Goblin() : Nemico(Stringa((char*) "Goblin"), 20, 4, 6, false, 30) {}
};

#endif