/*
 Nemico Guardia
 Causa danno a distanza
*/

#ifndef GUARDIA_CPP
#define GUARDIA_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Guardia : public Nemico {

  public:
    // costruttore
    Guardia(int x = 1, int y = 1) : Nemico(Stringa((char*) "Guardia"), 40, 5, 8, true, 50, x, y) {}
};

#endif