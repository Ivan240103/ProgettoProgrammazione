#include "Negozio.hpp"
#include <ncurses.h>

// costruttore
Negozio::Negozio() {}

// Postcondition: arma dalla posizione scelta
Arma Negozio::vendiArma(int position) {
  return armi[position];
}

// Postcondition: elenco delle armi nel negozio
Stringa Negozio::mostraArticoli() {
  Stringa elenco = Stringa();
  for (int i = 0; i < NUM_ARMI; i++) {
    elenco.concat(i);
    elenco.concat(')');
    elenco.concat(' ');
    elenco.concat(armi[i].toString());
  }
  return elenco;
}

//Metodo che stampa il negozio
void Negozio::stampaNegozio(WINDOW* negozio){
  mvwprintw(negozio, 0,32,"NEGOZIO");
  mvwprintw(negozio, 2,2,"ARMI");
  mvwprintw(negozio, 2,29,"POTENZIAMENTI");
  mvwprintw(negozio, 2,66,"VITA");
  mvwprintw(negozio, 4,1,"______________________________________________________________________");
  for(int i = 5; i<=20; i++){
    mvwprintw(negozio, i,21,"|");
  }
}

//Metodo che riempie la schermata del negozio
void Negozio::creaNegozio(){
  WINDOW* negozio = newwin(22, 72, 10, 10);
  box(negozio, 0,0);
  wrefresh(negozio);
  keypad(negozio, true);

  mvwprintw(negozio, 0,32,"NEGOZIO");
  wattron(negozio, A_STANDOUT);
  mvwprintw(negozio, 2,2,"ARMI");
  wattroff(negozio, A_STANDOUT);
  mvwprintw(negozio, 2,29,"POTENZIAMENTI");
  mvwprintw(negozio, 2,66,"VITA");
  mvwprintw(negozio, 4,1,"______________________________________________________________________");
  for(int i = 5; i<=20; i++){
    mvwprintw(negozio, i,21,"|");
  }
  int contatore=0;
  int scelta;
  armiNegozio(negozio, scelta);

  while(scelta!=120){
      scelta=wgetch(negozio);
      switch (scelta){
      case KEY_RIGHT:
          stampaNegozio(negozio);
         if(contatore==0){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 2,29,"POTENZIAMENTI");
              wattroff(negozio, A_STANDOUT);
              contatore++;
          }else if(contatore==1){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 2,66,"VITA");
              wattroff(negozio, A_STANDOUT);
              contatore++;
          }
          break;
      case KEY_LEFT:
          stampaNegozio(negozio);
          if(contatore==2){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 2,29,"POTENZIAMENTI");
              wattroff(negozio, A_STANDOUT);
              contatore-=1;
          }else if(contatore==1){
                wattron(negozio, A_STANDOUT);
                mvwprintw(negozio, 2,2,"ARMI");
                wattroff(negozio, A_STANDOUT);
                armiNegozio(negozio, scelta);
                contatore-=1;
              }
          break;
      }
  }
}

//Metodo che stampa le armi
void Negozio::stampaArmi(WINDOW* negozio){
  mvwprintw(negozio, 6,2,"SPADA");
  mvwprintw(negozio, 8,2,"PALLA CHIODATA");
  mvwprintw(negozio, 10,2,"ARCO");
}

//Metodo che stampa le caratteristiche degli oggetti del negozio
void Negozio::caratteristiche(int scelta, WINDOW* negozio){
  switch (scelta){
    case 0: 
      mvwprintw(negozio, 5,26,"              ");
      mvwprintw(negozio, 6,26,"|               ");
      mvwprintw(negozio, 7,26,"|");
      mvwprintw(negozio, 8,26,"|                ");
      mvwprintw(negozio, 7,25,"=");
      mvwprintw(negozio, 7,27,"=======>        ");
      mvwprintw(negozio, 10,25,"Danno:");
      mvwprintw(negozio, 10,33, "%d", s.getDanno());
      mvwprintw(negozio, 11,25,"Costo:");
      mvwprintw(negozio, 11,33, "%d", s.getCosto());
    break;
    case 1:
      mvwprintw(negozio, 5,26,"           ___");
      mvwprintw(negozio, 6,26,"          /   \\");
      mvwprintw(negozio, 7,25,"o-o-o-o-o-|     |");
      mvwprintw(negozio, 8,26,"          \\___/");       
      mvwprintw(negozio, 10,25,"Danno:");
      mvwprintw(negozio, 10,33, "%d", p.getDanno());
      mvwprintw(negozio, 11,25,"Costo:");
      mvwprintw(negozio, 11,33, "%d", p.getCosto());
    break;
    case 2:
      mvwprintw(negozio, 5,26,"  __            ");
      mvwprintw(negozio, 6,26," /  |           ");
      mvwprintw(negozio, 7,25,"<|---|-           ");
      mvwprintw(negozio, 8,26," \\__|              ");       
      mvwprintw(negozio, 10,25,"Danno:");
      mvwprintw(negozio, 10,33, "%d", p.getDanno());
      mvwprintw(negozio, 11,25,"Costo:");
      mvwprintw(negozio, 11,33, "%d", p.getCosto());
    break;
  }
}

//Metodo che cancella il menu della categoria dell'articolo scelto da comprare
void Negozio::cancellaMenu(WINDOW* negozio){
  for(int i=6; i<=20; i++){
    for(int j=2; j<=70; j++){
      mvwprintw(negozio, i,j," ");
    }
  }
  
  for(int i = 5; i<=20; i++){
    mvwprintw(negozio, i,21,"|");
  }
}

//Metodo che stampa il menu delle armi
void Negozio::armiNegozio(WINDOW* negozio, int &scelta){
  wattron(negozio, A_STANDOUT);
  mvwprintw(negozio, 6,2,"SPADA");
  wattroff(negozio, A_STANDOUT);
  mvwprintw(negozio, 8,2,"PALLA CHIODATA");
  mvwprintw(negozio, 10,2,"ARCO");
  

  int contatore=0;
  caratteristiche(contatore, negozio);
  while((scelta!=10)&&(scelta!=KEY_RIGHT)&&(scelta!=120)){
    scelta=wgetch(negozio);
      switch (scelta){
      case KEY_DOWN:
          stampaArmi(negozio);
         if(contatore==0){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 8,2,"PALLA CHIODATA");
              wattroff(negozio, A_STANDOUT);
              contatore++;
              caratteristiche(contatore, negozio);
          }else if(contatore==1){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 10,2,"ARCO");
              wattroff(negozio, A_STANDOUT);
              contatore++;
              caratteristiche(contatore, negozio);
          }
          break;
      case KEY_UP:
          stampaArmi(negozio);
          if(contatore==2){
              wattron(negozio, A_STANDOUT);
              mvwprintw(negozio, 8,2,"PALLA CHIODATA");
              wattroff(negozio, A_STANDOUT);
              contatore-=1;
              caratteristiche(contatore, negozio);
          }else if(contatore==1){
                wattron(negozio, A_STANDOUT);
                mvwprintw(negozio, 6,2,"SPADA");
                wattroff(negozio, A_STANDOUT);
                contatore-=1;
                caratteristiche(contatore, negozio);
              }
          break;
      }
  }
  cancellaMenu(negozio);
  
}
