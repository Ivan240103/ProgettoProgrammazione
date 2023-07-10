/*
 Nemico Scheletro
 Causa danno solo tramite contatto
*/

#ifndef SCHELETRO_CPP
#define SCHELETRO_CPP

#include <ncurses.h>
#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Scheletro : public Nemico {

  public:
    // costruttore
    Scheletro(int x=1, int y=1 ) : Nemico(Stringa((char*) "Scheletro"),'{', 10, 2, 4, false, 10, x, y, true) {}
};

#endif