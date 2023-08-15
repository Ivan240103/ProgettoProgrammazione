/*
 Nemico Scheletro
 Scaglia delle frecce verso sinistra
*/

#ifndef SCHELETRO_CPP
#define SCHELETRO_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Scheletro : public Nemico {

  public:
    // costruttore
    Scheletro(int x = 1, int y = 1) : Nemico(Stringa((char*) "Scheletro"), '{', 20, 4, 6, true, 30, x, y, true) {}
};

#endif