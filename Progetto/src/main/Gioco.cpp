/*
 Classe main da cui viene avviato il gioco
*/

#include <iostream>
using namespace std;
#include "Negozio.hpp"
#include "../elementi/personaggi/Protagonista.hpp"

int main() {
  Protagonista p = Protagonista("Cosimo");
  Negozio shop = Negozio();
  
  return 0;
}