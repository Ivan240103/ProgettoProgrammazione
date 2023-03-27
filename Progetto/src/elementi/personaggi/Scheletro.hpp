/*
 Nemico Scheletro
 Causa danno solo tramite contatto
*/

#include "Nemico.hpp"

class Scheletro : public Nemico {
  
  public:
    // costruttore
    Scheletro() : Nemico("Scheletro", 10, 2, 4, false, 3) {}
};