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
    Freccia(char simbolo = '-', int danno = 4, int x = 1, int y = 1, bool sx = true) 
      : Nemico(Stringa((char*) "Freccia"), simbolo, 1, danno, danno, 0, x, y, sx) {}
};

#endif