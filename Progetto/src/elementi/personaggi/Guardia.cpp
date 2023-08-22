/*
 Nemico Guardia
 Causa danno a contatto
*/

#ifndef GUARDIA_CPP
#define GUARDIA_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Guardia : public Nemico {

  public:
    // costruttore
    Guardia(int x = 1, int y = 1) : Nemico(Stringa((char*) "Guardia"), 'G', 40, 5, 8, 50, x, y, true) {}
};

#endif