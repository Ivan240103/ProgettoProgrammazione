/*
 Nemico Scheletro
 Causa danno solo tramite contatto
*/

#ifndef SCHELETRO_CPP
#define SCHELETRO_CPP

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Scheletro : public Nemico {

  public:
    // costruttore
    Scheletro() : Nemico(Stringa((char*) "Scheletro"), 10, 2, 4, false, 10) {}
};

#endif