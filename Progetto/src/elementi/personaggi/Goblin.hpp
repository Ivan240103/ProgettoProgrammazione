/*
 Nemico Goblin
 Causa danno nelle caselle adiacenti (una sola)
*/

#include "Nemico.hpp"

class Goblin : public Nemico {
  
  public:
    // costruttore
    Goblin() : Nemico("Goblin", 20, 4, 6, false, 5) {}
};