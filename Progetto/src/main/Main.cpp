/*
 Classe main da cui viene avviato il gioco
*/
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "GUI.hpp"

using namespace std;

int main() {
  srand(time(0));

  GUI g = GUI();
  
  initscr();
  noecho();
  cbreak();
  curs_set(0);
    
  WINDOW* finestra = g.creaFinestra();
  wrefresh(finestra);
  nodelay(finestra, TRUE);

  g.gioco(finestra);
}