/*
 Classe main da cui viene avviato il gioco
*/

#include <iostream>
using namespace std;
#include "Negozio.hpp"
#include "../elementi/personaggi/Protagonista.hpp"

int main() {
  char protName[10] = "Cosimo";
  Protagonista p = Protagonista(protName);
  
  cout<<"Nome: "<<p.getNome().s<<endl;
  cout<<"Danno arma: "<<p.getArma().getDanno()<<endl;
  
  return 0;
}