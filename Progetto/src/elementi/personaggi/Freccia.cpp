/*
 Nemico freccia
 Scagliato dal nemico Scheletro
 Causa danno a contatto e poi scompare
*/

#ifndef FRECCIA_CPP
#define FRECCIA_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Freccia : public Nemico {

  public:
    // costruttore
    Freccia(int x = 1, int y = 1, char simbolo = '-', bool sx = true) : Nemico(Stringa((char*) "Freccia"), simbolo, 1, 4, 6, false, 10, x, y, sx) {}
};

#endif