/*
 Nemico Scheletro
 Scaglia delle frecce verso sinistra, non si muove
 Causa danno a distanza
*/

#ifndef SCHELETRO_CPP
#define SCHELETRO_CPP

#include "Nemico.hpp"

class Scheletro : public Nemico {

  public:
    // costruttore
    Scheletro(int x = 3, int y = 3) : Nemico(Stringa((char*) "Scheletro"), '{', 20, 4, 7, 30, x, y, true) {}
};

#endif