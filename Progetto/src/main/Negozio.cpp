#include "Negozio.hpp"

//Metodo che stampa le info del protagonista
void Negozio::stampaInfo(WINDOW* finestra) {
  // cancella le precedenti
  mvwprintw(finestra, 20,45,"                         ");
  // scrive le nuove
  mvwprintw(finestra, 20,45,"VITA: ");
  mvwprintw(finestra, 20,51,"%d  ", pr->getVita());
  mvwprintw(finestra, 20,56,"DENARO: ");
  mvwprintw(finestra, 20,64,"%d", pr->getDenaro());
}

//Metodo che stampa il negozio
// Precondition: standout = categoria attuale (0 armi, 1 pot, 2 vita)
void Negozio::stampaNegozio(int standout, WINDOW* finestra){
  mvwprintw(finestra, 0,31," NEGOZIO ");
  if (standout == 0) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 2,2,"ARMI");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 2,2,"ARMI");
  }
  if (standout == 1) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 2,29,"POTENZIAMENTI");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 2,29,"POTENZIAMENTI");
  }
  if (standout == 2) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 2,66,"VITA");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 2,66,"VITA");
  }  
  mvwprintw(finestra, 4,1,"______________________________________________________________________");
  for(int i = 5; i<=20; i++){
    mvwprintw(finestra, i,21,"|");
  }
  stampaInfo(finestra);
}

//Metodo che stampa le armi
// Precondition: standout = arma attuale (0 spada, 1 palla, 2 arco)
void Negozio::stampaArmi(int standout, WINDOW* finestra){
  if (standout == 0) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 6,2,"SPADA");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 6,2,"SPADA");
  }
  if (standout == 1) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 8,2,"PALLA CHIODATA");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 8,2,"PALLA CHIODATA");
  }
  if (standout == 2) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 10,2,"ARCO");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 10,2,"ARCO");
  }
}

//Metodo che stampa i potenziamenti
// Precondition: standout = pot attuale (3 ultradanno1, 4 ultradanno3, 5 superscudo1, 6 superscudo3)
void Negozio::stampaPotenziamenti(int standout, WINDOW* finestra){
  if (standout == 3) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 6,2,"ULTRA DANNO 1");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 6,2,"ULTRA DANNO 1");
  }
  if (standout == 4) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 8,2,"ULTRA DANNO 3");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 8,2,"ULTRA DANNO 3");
  }
  if (standout == 5) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 10,2,"SUPER SCUDO 1");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 10,2,"SUPER SCUDO 1");
  }
  if (standout == 6) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 12,2,"SUPER SCUDO 3");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 12,2,"SUPER SCUDO 3");
  }
}

//Metodo che stampa la vita
// Precondition: standout = vita attuale (7 +25, 8 +50, 9 +100)
void Negozio::stampaVita(int standout, WINDOW* finestra){
  if (standout == 7) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 6,2,"+25");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 6,2,"+25");
  }
  if (standout == 8) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 8,2,"+50");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 8,2,"+50");
  }
  if (standout == 9) {
    wattron(finestra, A_STANDOUT);
    mvwprintw(finestra, 10,2,"+100");
    wattroff(finestra, A_STANDOUT);
  } else {
    mvwprintw(finestra, 10,2,"+100");
  }
}

//Metodo che stampa le caratteristiche degli articoli del negozio
// Precondition: articolo di cui stampare le caratteristiche
void Negozio::caratteristiche(int articolo, WINDOW* finestra){
  switch (articolo){
    case 0: 
      mvwprintw(finestra, 5,26,"              ");
      mvwprintw(finestra, 6,26,"|               ");
      mvwprintw(finestra, 7,26,"|");
      mvwprintw(finestra, 8,26,"|                ");
      mvwprintw(finestra, 7,25,"=");
      mvwprintw(finestra, 7,27,"=======>        ");
      mvwprintw(finestra, 10,25,"Danno:   ");
      mvwprintw(finestra, 10,33, "%d", s.getDanno());
      mvwprintw(finestra, 11,25,"Costo:");
      mvwprintw(finestra, 11,33, "%d ", s.getCosto());
      break;
    case 1:
      mvwprintw(finestra, 5,26,"           ___");
      mvwprintw(finestra, 6,26,"          /   \\");
      mvwprintw(finestra, 7,25,"o-o-o-o-o-|     |");
      mvwprintw(finestra, 8,26,"          \\___/");       
      mvwprintw(finestra, 10,25,"Danno:   ");
      mvwprintw(finestra, 10,33, "%d", p.getDanno());
      mvwprintw(finestra, 11,25,"Costo:");
      mvwprintw(finestra, 11,33, "%d ", p.getCosto());
      break;
    case 2:
      mvwprintw(finestra, 5,26,"  __            ");
      mvwprintw(finestra, 6,26," /  |           ");
      mvwprintw(finestra, 7,25,"<|---|-           ");
      mvwprintw(finestra, 8,26," \\__|              ");       
      mvwprintw(finestra, 10,25,"Danno:   ");
      mvwprintw(finestra, 10,33, "%d", a.getDanno());
      mvwprintw(finestra, 11,25,"Costo:");
      mvwprintw(finestra, 11,33, "%d", a.getCosto());
      break;
    case 3:
      mvwprintw(finestra, 6,23,"        *         ");
      mvwprintw(finestra, 7,23,"       ***        ");
      mvwprintw(finestra, 8,23,"      ** **       ");
      mvwprintw(finestra, 9,23,"     **   **      ");       
      mvwprintw(finestra, 11,25,"Livelli:");
      mvwprintw(finestra, 11,35, "%d", u1.getDurata());
      mvwprintw(finestra, 12,25,"Costo:");
      mvwprintw(finestra, 12,33, "%d", u1.getCosto());
      break;
    case 4:
      mvwprintw(finestra, 6,23,"        *         ");
      mvwprintw(finestra, 7,23,"       ***        ");
      mvwprintw(finestra, 8,23,"      ** **       ");
      mvwprintw(finestra, 9,23,"     **   **      ");       
      mvwprintw(finestra, 11,25,"Livelli:");
      mvwprintw(finestra, 11,35, "%d", u3.getDurata());
      mvwprintw(finestra, 12,25,"Costo:");
      mvwprintw(finestra, 12,33, "%d", u3.getCosto());
      break;
    case 5:
      mvwprintw(finestra, 6,23,"      __A__       ");
      mvwprintw(finestra, 7,23,"     \\     /      ");
      mvwprintw(finestra, 8,23,"      \\   /       ");
      mvwprintw(finestra, 9,23,"       \\_/        ");       
      mvwprintw(finestra, 11,25,"Livelli:");
      mvwprintw(finestra, 11,35, "%d", ss1.getDurata());
      mvwprintw(finestra, 12,25,"Costo:");
      mvwprintw(finestra, 12,33, "%d", ss1.getCosto());
      break;
    case 6:
      mvwprintw(finestra, 6,23,"      __A__       ");
      mvwprintw(finestra, 7,23,"     \\     /      ");
      mvwprintw(finestra, 8,23,"      \\   /       ");
      mvwprintw(finestra, 9,23,"       \\_/        ");       
      mvwprintw(finestra, 11,25,"Livelli:");
      mvwprintw(finestra, 11,35, "%d", ss3.getDurata());
      mvwprintw(finestra, 12,25,"Costo:");
      mvwprintw(finestra, 12,33, "%d", ss3.getCosto());
      break;
    case 7:
      mvwprintw(finestra, 6,23,"       ::         ");
      mvwprintw(finestra, 7,23,"     ::::::       ");
      mvwprintw(finestra, 8,23,"       ::         ");
      mvwprintw(finestra, 9,23,"                  ");       
      mvwprintw(finestra, 10,25,"Vita:  +25 ");
      mvwprintw(finestra, 11,25,"Costo:  200");
      break;
    case 8:
      mvwprintw(finestra, 6,23,"       ::         ");
      mvwprintw(finestra, 7,23,"     ::::::       ");
      mvwprintw(finestra, 8,23,"       ::         ");
      mvwprintw(finestra, 9,23,"                  ");       
      mvwprintw(finestra, 10,25,"Vita:  +50 ");
      mvwprintw(finestra, 11,25,"Costo:  350");
      break;
    case 9:
      mvwprintw(finestra, 6,23,"       ::         ");
      mvwprintw(finestra, 7,23,"     ::::::       ");
      mvwprintw(finestra, 8,23,"       ::         ");
      mvwprintw(finestra, 9,23,"                  ");       
      mvwprintw(finestra, 10,25,"Vita:  +100");
      mvwprintw(finestra, 11,25,"Costo:  650");
      break;
  }
}

//Metodo che gestisce il menu delle armi
// Postcondition: true se bisogna cambiare categoria, false altrimenti
bool Negozio::armiNegozio(WINDOW* finestra, int &scelta){
  int contatore=0;

  scelta=0;
  stampaArmi(contatore, finestra);
  caratteristiche(contatore, finestra);

  while((scelta!=10)&&(scelta!=KEY_RIGHT)&&(scelta!=101)){
    scelta=wgetch(finestra);
    // eliminazione 'denaro insufficiente'
    int ch = mvwinch(finestra, 17, 40)& A_CHARTEXT;
    if (ch != ' ') {
      mvwprintw(finestra, 17,40,"                        ");
    }
    switch (scelta){
      case KEY_DOWN:
        if(contatore==0 || contatore==1){
          contatore++;
          stampaArmi(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
      case KEY_UP:
        if(contatore==2 || contatore==1){
          contatore--;
          stampaArmi(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
    }
  }

  // acquisto
  if(scelta==10){
    if(contatore==0){
      if(pr->spendi(s.getCosto())){
        pr->cambiaArma(s);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==1){
      if(pr->spendi(p.getCosto())){
        pr->cambiaArma(p);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==2){
      if(pr->spendi(a.getCosto())){
        pr->cambiaArma(a);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }
  }

  cancellaMenu(finestra);
  stampaInfo(finestra);

  return scelta == KEY_RIGHT || scelta == 10;
}

//Metodo che gestisce il menu dei potenziamenti
// Postcondition: true se bisogna cambiare categoria, false altrimenti
bool Negozio::potenziamentiNegozio(WINDOW* finestra, int &scelta){
  int contatore=3;
  
  scelta=0;
  stampaPotenziamenti(contatore, finestra);
  caratteristiche(contatore, finestra);

  while((scelta!=10)&&(scelta!=KEY_RIGHT)&&(scelta!=KEY_LEFT)&&(scelta!=101)){
    scelta=wgetch(finestra);
    // eliminazione 'denaro insufficiente'
    int ch = mvwinch(finestra, 17, 40)& A_CHARTEXT;
    if (ch != ' ') {
      mvwprintw(finestra, 17,40,"                        ");
    }
    switch (scelta){
      case KEY_DOWN:
        if(contatore==3 || contatore==4 || contatore==5){
          contatore++;
          stampaPotenziamenti(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
      case KEY_UP:
        if(contatore==6 || contatore==5 || contatore==4){
          contatore--;
          stampaPotenziamenti(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
    }
  }

  // acquisto
  if(scelta==10){
    if(contatore==3){
      if(pr->spendi(u1.getCosto())){
        pr->cambiaPotenziamento(u1);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==4){
      if(pr->spendi(u3.getCosto())){
        pr->cambiaPotenziamento(u3);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==5){
      if(pr->spendi(ss1.getCosto())){
        pr->cambiaPotenziamento(ss1);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==6){
      if(pr->spendi(ss3.getCosto())){
        pr->cambiaPotenziamento(ss3);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }
  }

  cancellaMenu(finestra);
  stampaInfo(finestra);

  return scelta == KEY_LEFT || scelta == KEY_RIGHT || scelta == 10;
}

//Metodo che gestisce il menu della vita
// Postcondition: true se bisogna cambiare categoria, false altrimenti
bool Negozio::vitaNegozio(WINDOW* finestra, int &scelta){
  int contatore=7;

  scelta=0;
  stampaVita(contatore, finestra);
  caratteristiche(contatore, finestra);

  while((scelta!=10)&&(scelta!=KEY_LEFT)&&(scelta!=101)){
    scelta=wgetch(finestra);
    // eliminazione 'denaro insufficiente'
    int ch = mvwinch(finestra, 17, 40)& A_CHARTEXT;
    if (ch != ' ') {
      mvwprintw(finestra, 17,40,"                        ");
    }
    switch (scelta){
      case KEY_DOWN:
        if(contatore==7 || contatore==8){
          contatore++;
          stampaVita(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
      case KEY_UP:
        if(contatore==9 || contatore==8){
          contatore--;
          stampaVita(contatore, finestra);
          caratteristiche(contatore, finestra);
        }
        break;
    }
  }

  // acquisto
  if(scelta==10){
    if(contatore==7){
      if(pr->spendi(200)){
        pr->aumentaVita(25);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==8){
      if(pr->spendi(350)){
        pr->aumentaVita(50);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }else if(contatore==9){
      if(pr->spendi(650)){
        pr->aumentaVita(100);
      }else{
        mvwprintw(finestra, 17,40,"NON HAI ABBASTANZA SOLDI");
      }
    }
  }

  cancellaMenu(finestra);
  stampaInfo(finestra);

  return scelta == KEY_LEFT || scelta == 10;
}

//Metodo che cancella il menu della categoria dell'articolo scelto da comprare
void Negozio::cancellaMenu(WINDOW* finestra){
  for(int i=5; i<=16; i++){
    for(int j=2; j<=70; j++){
      mvwprintw(finestra, i,j," ");
    }
  }
  
  for(int i = 5; i<=20; i++){
    mvwprintw(finestra, i,21,"|");
  }
}

// costruttore default
Negozio::Negozio() {}

// costruttore
Negozio::Negozio(Protagonista* pr) {
  this->pr = pr;
}

//Metodo che riempie la schermata del negozio
void Negozio::creaNegozio(){
  int contatore = 0, scelta = 0;
  bool mv = false;

  WINDOW* negozio = newwin(22, 72, 10, 10);
  box(negozio, 0,0);
  wrefresh(negozio);
  keypad(negozio, true);

  stampaNegozio(0, negozio);
  mv = armiNegozio(negozio, scelta);

  while(scelta!=101){
    if (!mv) {
      scelta=wgetch(negozio);
    }
    switch(scelta) {
      case KEY_RIGHT:
        if(contatore==0){
          contatore++;
          stampaNegozio(contatore, negozio);
          mv = potenziamentiNegozio(negozio, scelta);
        }else if(contatore==1){
          contatore++;
          stampaNegozio(contatore, negozio);
          mv = vitaNegozio(negozio, scelta);
        }
        break;
      case KEY_LEFT:
        if(contatore==2){
          contatore--;
          stampaNegozio(contatore, negozio);
          mv = potenziamentiNegozio(negozio, scelta);
        }else if(contatore==1){
          contatore--;
          stampaNegozio(contatore, negozio);
          mv = armiNegozio(negozio, scelta);
        }
        break;
      case 10:
        stampaNegozio(contatore, negozio);
        scelta = 0;
        if (contatore == 0) {
          mv = armiNegozio(negozio, scelta);
        } else if (contatore == 1) {
          mv = potenziamentiNegozio(negozio, scelta);
        } else {
          mv = vitaNegozio(negozio, scelta);
        }
        break;
    }
  }
}