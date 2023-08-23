/*
 Nemico Guardia
 Si muove orizzontalmente
 Causa danno a contatto
*/

#ifndef GUARDIA_CPP
#define GUARDIA_CPP

#include "Nemico.hpp"

class Guardia : public Nemico {

  public:
    // costruttore
    Guardia(int x = 3, int y = 3) : Nemico(Stringa((char*) "Guardia"), 'G', 40, 6, 8, 50, x, y, true) {}
};

#endif