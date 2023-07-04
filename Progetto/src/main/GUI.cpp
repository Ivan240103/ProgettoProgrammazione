#include "GUI.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

GUI::GUI(){}

//Stampa il personaggio in una determinata posizione e in una determinata finestra
void GUI::stampaPersonaggio(WINDOW *finestra, int y, int x){
    mvwaddch(finestra, y, x, this->personaggio);
}

//Metodo che crea la finestra di gioco
WINDOW* GUI::creaFinestra(){
    
    WINDOW *finestra = newwin(this->altezza, this->larghezza, 10, 10);
    box(finestra, 0,0);
    wrefresh(finestra);
    keypad(finestra, true);

    return finestra;
}

//Metodo che stampa una mappa casuale
void GUI::stampaMappa(WINDOW* win){
    srand(time(0));
    int v1 = rand() % 4;
    int v2 = rand() % 4;
    int v3 = rand() % 4;
    int v4 = rand() % 4;
    int v5 = rand() % 4;
    creaMappa(0,1, win);
    creaMappa(v1,11, win);
    creaMappa(v2,21, win);
    creaMappa(v3,31, win);
    creaMappa(v4,41, win);
    creaMappa(v5,51, win);
    creaMappa(0,61, win);
}

//Metodo per gestire i movimenti a seconda del tasto scelto
int GUI::getmv(WINDOW* finestra){

    int scelta = wgetch(finestra);
    switch (scelta)
    {
    case 32:
        mvup(finestra);
        break;
    case 97:
        mvleft(finestra);
        break;
    case 100:
        mvright(finestra);
        break;
    case 101:
        n.creaNegozio();
        break;
    }
    
    return scelta;

}

//Metodo salto
void GUI::mvup(WINDOW* finestra){

    int ch1 = mvwinch(finestra,p.getY()-1, p.getX())& A_CHARTEXT;
    int ch2 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
    if((ch1==' ') && (ch2!=' ')){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');

    p.salta();
    stampaPersonaggio(finestra, p.getY(), p.getX());
    if(p.getY()<1){
        p.setY(1);
    }
    }
    if(ch2==' '){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');

    p.muoviGiu();
    
    if(p.getY() > this->altezza-2){
        p.setY(this->altezza-2);
    }
    }
}

//Metodo muovi a sinistra
void GUI::mvleft(WINDOW* finestra){

    int ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
    if(ch1==' '){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');
    
    p.muoviSx();
    if(p.getX()<1){
        p.setX(1);
    }
    }
}

//Metodo muovi a destra
void GUI::mvright(WINDOW* finestra){

    int ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;

    if(ch1==' '){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');

    p.muoviDx();
    if(p.getX()>this->larghezza-2){
        p.setX(this->larghezza-2);
    }
    }else if(ch1 == '#'){
        mvwaddch(finestra, 20, 70, ' ');
        wrefresh(finestra);
        werase(finestra);
        box(finestra, 0, 0);
        p.resetPosizione();
        
        stampaMappa(finestra);
    }

}

//Metodo muovi in basso
void GUI::mvdown(WINDOW* finestra){

    mvwaddch(finestra, p.getY(), p.getX(), ' ');

    p.muoviGiu();
    
    if(p.getY() > (this->altezza)-2){
        p.setY(this->altezza-2);
    }

}

//Metodo gravità
void GUI::gravita(WINDOW* finestra){
    int gravita=0;
    nodelay(finestra, TRUE);
    //faccio un do-while, perchè così il personaggio viene fatto vedere subito sullo schermo
    do{
        mvwaddch(finestra, 18, 71, '#');
        wrefresh(finestra);
        usleep(50000);
        int ch1 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
        if((gravita%2 == 0) && (ch1==' ')){
            mvdown(finestra);
            stampaPersonaggio(finestra, p.getY(), p.getX());
            wrefresh(finestra);
        }

        stampaPersonaggio(finestra, p.getY(), p.getX());
        getmv(finestra);

        wrefresh(finestra);
        gravita++;

    }while(1==1);
}

//Metodo che crea una mappa casuale
void GUI::creaMappa(int det, int mv, WINDOW* win){
    switch (det){
        case 0:
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            break;
        case 1:
            mvwprintw(win, 17,mv+1, "===");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            break;
        case 2:
            mvwprintw(win, 16,mv+3, "==");
            mvwprintw(win, 17,mv+2, "===");
            mvwprintw(win, 18,mv+1, "====");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            break;
        case 3:
            mvwprintw(win, 16,mv+1, "[?]");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            break;
    }
}


