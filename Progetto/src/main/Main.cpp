/*
 Classe main da cui viene avviato il gioco
*/
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h> 
#include <time.h>   
#include <iostream>

using namespace std;

#include "Gioco.hpp"
#include "Negozio.hpp"
#include "GUI.hpp"
#include "../elementi/personaggi/Protagonista.hpp"
#include "../util/GestoreFile.hpp"

int main() {
  
  GestoreFile gf = GestoreFile();
  Protagonista p = Protagonista(gf);
  Gioco g = Gioco();
  GUI gu = GUI();
  
  
  initscr();
  noecho();
  cbreak();
  curs_set(0);
    
  WINDOW* finestra = gu.creaFinestra();
  wrefresh(finestra);
  nodelay(finestra, TRUE);

  gu.stampaMappa(finestra);

  gu.gravita(finestra);

  endwin();
  
}