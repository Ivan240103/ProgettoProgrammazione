/*
 Classe main per resettare il database in caso di errori

 Autori: Ivan De Simone, Nicolò Tambini, Tommaso Merighi
*/

#include <iostream>
#include "Gioco.hpp"

int main() {
  GestoreFile gf = GestoreFile();
  // reset file partita
  Gioco g = Gioco(gf, true);
  g.salva(gf);
  // reset file protagonista
  Stringa s = Stringa((char*) "Ajeje,100,0,Bastone,tmp,0,0,3,3,1");
  gf.apriOutput(gf.getFileProtagonista());
  gf.scrivi(s);
  gf.chiudiOutput();

  cout<<"Database restored"<<endl;
}