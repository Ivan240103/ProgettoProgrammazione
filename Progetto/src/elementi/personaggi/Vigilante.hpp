/*
 Nemico Vigilante
 Causa danno a distanza
*/

#include "Nemico.hpp"

class Vigilante : public Nemico {
  
  public:
    // costruttore
    Vigilante() : Nemico("Vigilante", 40, 5, 8, true, 10) {}
};