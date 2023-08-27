/*
 Classe main da cui viene avviato il gioco

 Autori: Ivan De Simone, Nicolò Tambini, Tommaso Merighi
*/

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
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