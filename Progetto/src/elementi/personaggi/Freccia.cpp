/*
 Nemico freccia
 Scagliato dal nemico Scheletro o dall'arco del protagonista
 Causa danno a contatto e poi scompare
*/

#ifndef FRECCIA_CPP
#define FRECCIA_CPP

#include "Nemico.hpp"

class Freccia : public Nemico {

  public:
    // costruttore
    Freccia(char simbolo = '-', int danno = 4, int x = 3, int y = 3, bool sx = true) 
      : Nemico(Stringa((char*) "Freccia"), simbolo, 1, danno, danno, 0, x, y, sx) {}
};

#endif