/*
 Nemico Guardia
 Causa danno a distanza
*/

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Guardia : public Nemico {

  public:
    // costruttore
    Guardia() : Nemico(Stringa((char*) "Guardia"), 40, 5, 8, true, 10) {}
};