/*
 Nemico Goblin
 Causa danno nelle caselle adiacenti dx e sx (una sola)
*/

#include "Nemico.hpp"
#include "../../util/Stringa.hpp"

class Goblin : public Nemico {

  protected:
    char nome[10] = "Goblin";
  
  public:
    // costruttore
    Goblin() : Nemico(Stringa(nome), 20, 4, 6, false, 5) {}
};