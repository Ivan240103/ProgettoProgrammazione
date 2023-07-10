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
    //ivan
    int v = rand() % 100;
    l=Livello(v);
    //ivan
    creaMappa(0,1, win);
    creaMappa( (v*7)%9 ,11, win);
    creaMappa( (v*5)%9 ,21, win);
    creaMappa( (v+6)%9 ,31, win);
    creaMappa( (v*8)%9 ,41, win);
    creaMappa( (v*3)%9 ,51, win);
    creaMappa(0,61, win);

    game.aggiungiLivello(l);

}

//Metodo per gestire i movimenti a seconda del tasto scelto
bool uscita = false;
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
    case 120:
        esci(finestra);
        break;
    case 119:
        attacco(p.getArma(), finestra);
        break;
    }
    
    return scelta;

}

//Metodo salto
bool isJump = false;
int contSalto = 0;
void GUI::mvup(WINDOW* finestra){

    isJump = true;

    int ch1 = mvwinch(finestra,p.getY()-1, p.getX())& A_CHARTEXT;
    int ch2 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
    if((ch1==' ') && (ch2!=' ')){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');
    int contatore = 0;

    p.salta();
    stampaPersonaggio(finestra, p.getY(), p.getX());
    
    }
}

//Metodo muovi a sinistra
void GUI::mvleft(WINDOW* finestra){
    p.setVersoDestra(false);
    int ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
    if(ch1==' '){
    mvwaddch(finestra, p.getY(), p.getX(), ' ');
    
    p.muoviSx();
    if(p.getX()<1){
        p.setX(1);
    }
    }else if(ch1=='#'){
        game.muoviIndietro();
        
        creaMappa(0,1, finestra);
        creaMappa((game.attuale->l.getId()*7)%9 ,11, finestra);
        creaMappa((game.attuale->l.getId()*5)%9 ,21, finestra);
        creaMappa((game.attuale->l.getId()+6)%9 ,31, finestra);
        creaMappa((game.attuale->l.getId()*8)%9 ,41, finestra);
        creaMappa((game.attuale->l.getId()*3)%9 ,51, finestra);
        creaMappa(0,61, finestra);

    }
}

//Metodo muovi a destra
void GUI::mvright(WINDOW* finestra){

    p.setVersoDestra(true);
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

//Metodo dal quale viene avviato il gioco, e che contiene tutti i metodi che rispecchiano una dinamica reale
bool hit = false;
void GUI::gioco(WINDOW* finestra){
    int gravita=0;
    nodelay(finestra, TRUE);
    do{
        //controllo se il protagonista ha ancora vita
        if(p.getVita()<=0){
           werase(finestra);
           box(finestra, 0, 0);
           wrefresh(finestra);
           p.resetPosizione(); 
           mvwprintw(finestra, 9 ,30, " -----------");
           mvwprintw(finestra, 10,30, "| GAME OVER |");
           mvwprintw(finestra, 11,30, " ----------- ");
           mvwprintw(finestra, 15,20, "per uscire dal gioco premere 'x'");
           int scelta;
           while(scelta!=120){
           scelta=wgetch(finestra);
           }
           esci(finestra);
        }
        //stampo i valori vita e denaro in modo tale che ogni volta si modifichino con i soldi ottenuti o la vita tolta
        mvwprintw(finestra, 2,2, "   ");
        mvwprintw(finestra, 2,2, "%d", p.getVita());
        mvwprintw(finestra, 2,5, "/100 <3");
        mvwprintw(finestra, 2,65, "%d", p.getDenaro());
        mvwprintw(finestra, 2,70, "$");
        //fermo la gravità quando salto per 6 frame in modo tale da farlo sembrare più reale
        if((isJump == true)&&(contSalto<6)){
            contSalto++;
        }
        if(contSalto == 6){
            isJump = false;
            contSalto = 0;
        }
        //stampo la fine e il livello prima rispetto al livello attuale
        mvwaddch(finestra, 18, 0, '#');
        mvwaddch(finestra, 18, 71, '#');
        wrefresh(finestra);
        usleep(50000);
        //attivo la gravità per far cadere il protagonista
        int ch1 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
        if((gravita%2 == 0) && (ch1==' ') && (isJump == false)){
            mvdown(finestra);
            stampaPersonaggio(finestra, p.getY(), p.getX());
            wrefresh(finestra);
        }
        //attivo i movimenti dei nemici, si muovono ogni 10 frame, in modo tale che il protagonista riesca a scappare
        if(gravita%10==0){
            movimentiNemico(finestra);
        }
        //rendo il giocatore invincibile, dopo che ha preso danno, per 30 frame
        if(gravita%30==0){
            hit=false;
        }

        stampaPersonaggio(finestra, p.getY(), p.getX());
        getmv(finestra);

        wrefresh(finestra);
        gravita++;

    }while(uscita == false);
}

//Metodo che stampa i nemici
void GUI::creaNemico(WINDOW* win, int y, int x, int random){

Goblin gob;
Scheletro scet;
Guardia gua;
Freccia f;

switch(random){
    case 0:
        gob = Goblin(x,y);
        l.inserisciNemico(gob);
        mvwaddch(win, y, x, gob.getSimbolo());
        break;
    case 1:
        scet = Scheletro(x,y);
        f = Freccia(x-1,y);
        l.inserisciNemico(f);
        l.inserisciNemico(scet);
        mvwaddch(win, y, x, scet.getSimbolo());
        break;
    case 2:
        gua = Guardia(x,y);
        l.inserisciNemico(gua);
        mvwaddch(win, y, x, gua.getSimbolo());
        break;
}
}

void GUI::creaMappa(int det, int mv, WINDOW* win){
    srand(time(0));
    int v1 = rand() % 3;
    int v2 = rand() % 3;
    int v3 = rand() % 3;
    int v4 = rand() % 3;
    int v5 = rand() % 3;
    int v6 = rand() % 3;
    int v7 = rand() % 3;
    switch (det){
        case 0:
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+5, v1);
            break;
        case 1:
            mvwprintw(win, 18,mv, "  ===     ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 17, mv+4, v2);
            break;
        case 2:
            mvwprintw(win, 17,mv, "     ===  ");
            mvwprintw(win, 18,mv, "  ========");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 16, mv+7, v3);
            break;
        case 3:
            mvwprintw(win, 15,mv, "    ==    ");
            mvwprintw(win, 16,mv, "   ====   ");
            mvwprintw(win, 17,mv, "  ======  ");
            mvwprintw(win, 18,mv, "==========");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 14, mv+5, v4);
            break;
        case 4:
            mvwprintw(win, 18,mv, "  =  =    ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+8, v5);
            break;
        case 5:
            mvwprintw(win, 17,mv, "  ======= ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+5, v6);
            break;
        case 6:
        	mvwprintw(win, 17,mv, "   =      ");
            mvwprintw(win, 18,mv, "  ===     ");
			mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+8, v7);
            break;
        case 7:
            mvwprintw(win, 17,mv, "   =      ");
            mvwprintw(win, 18,mv, "  ======  ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+8, v1);
            break;
        case 8:	
            mvwprintw(win, 17,mv, "      =   ");
            mvwprintw(win, 18,mv, "    ====  ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 18, mv+1, v3);
            break;
        case 9:	
            mvwprintw(win, 17,mv, "      =   ");
            mvwprintw(win, 18,mv, "  =  ===  ");
            mvwprintw(win, 19,mv, "==========");
            mvwprintw(win, 20,mv, "==========");
            creaNemico(win, 17, mv+3, v5);
            break;
    }
}


//Metodo per definire gli spostamenti dei nemici
void GUI::movimentiNemico(WINDOW* finestra){
    
    l.appoggio = l.hnemici;
    while(l.hnemici != NULL){
        
        if(l.hnemici->nem.getSimbolo() == 'G'){
            int ch1 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()-1)& A_CHARTEXT;
            int ch2 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch3 = mvwinch(finestra,l.hnemici->nem.getY()+1, l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch4 = mvwinch(finestra,l.hnemici->nem.getY()+1, l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' '&& l.hnemici->nem.getSx()==true && ch4!=' '){
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()-1, l.hnemici->nem.getSimbolo());
                l.hnemici->nem.muoviSx();
            }else{
                l.hnemici->nem.setSx(false);
                if(ch1=='@' && hit==false){
                    p.prendiDanno(l.hnemici->nem.getDanno());
                    hit=true;
                }else if(ch2==' ' && ch3!=' '){
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()+1, l.hnemici->nem.getSimbolo());
                    l.hnemici->nem.muoviDx();
                }else{
                    l.hnemici->nem.setSx(true);
                    if(ch2=='@' && hit==false){
                    p.prendiDanno(l.hnemici->nem.getDanno());
                    hit=true;
                    }
                }
            }
        }else 
        
        if(l.hnemici->nem.getSimbolo() == 'S'){
            int ch1 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()-1)& A_CHARTEXT;
            int ch2 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch3 = mvwinch(finestra,l.hnemici->nem.getY()+1, l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch4 = mvwinch(finestra,l.hnemici->nem.getY()+1, l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' ' && p.getX()<l.hnemici->nem.getX() && ch4!=' '){
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()-1, l.hnemici->nem.getSimbolo());
                l.hnemici->nem.muoviSx();
            }else{
                if(ch1=='@' && hit==false){
                    p.prendiDanno(l.hnemici->nem.getDanno());
                    hit=true;
                }else 
                if(ch4==' '){
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                    mvwaddch(finestra, l.hnemici->nem.getY()+1, l.hnemici->nem.getX()-1, l.hnemici->nem.getSimbolo());
                    l.hnemici->nem.muoviSx();
                    l.hnemici->nem.MuoviSuGiu(1);
                }
                if(ch2==' ' && p.getX()>l.hnemici->nem.getX() && ch3!=' '){
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()+1, l.hnemici->nem.getSimbolo());
                    l.hnemici->nem.muoviDx();
                }else{
                    if(ch2=='@' && hit==false){
                    p.prendiDanno(l.hnemici->nem.getDanno());
                    hit=true;
                    }
                    if(ch3==' '){
                        mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                        mvwaddch(finestra, l.hnemici->nem.getY()+1, l.hnemici->nem.getX()+1, l.hnemici->nem.getSimbolo());
                        l.hnemici->nem.muoviDx();
                        l.hnemici->nem.MuoviSuGiu(1);
                    }
                }
            }
        }else

        if(l.hnemici->nem.getSimbolo() == '{'){
            int tmpx = l.hnemici->nem.getX()-1;
            int tmpy = l.hnemici->nem.getY();
            l.hnemici = l.hnemici->succ;
            int ch1 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' '){
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()-1, l.hnemici->nem.getSimbolo());
                l.hnemici->nem.muoviSx();
            }else{
                if(ch1=='@' && hit==false){
                    p.prendiDanno(l.hnemici->nem.getDanno());
                    hit=true;
                }else{
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                l.hnemici->nem.setX(tmpx);
                l.hnemici->nem.setY(tmpy);
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), l.hnemici->nem.getSimbolo());
                }
            }
        }else

        if(l.hnemici->nem.getSimbolo() == '+'){
            if(l.hnemici->nem.getSx()==false){
                int tmpx = l.hnemici->nem.getX()+1;
                int tmpy = l.hnemici->nem.getY();
                int ch1 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()+1)& A_CHARTEXT;
                if(ch1==' '){
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()+1, l.hnemici->nem.getSimbolo());
                l.hnemici->nem.muoviDx();
                }else{
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                    l.hnemici->nem.prendiDanno(1);
                    l.hnemici = l.appoggio;
                    l.rimuoviNemici();
                    controlloCasella(finestra, ch1, p.getArma(), tmpy, tmpx);
                }
            }else if(l.hnemici->nem.getSx()==true){
                int tmpx = l.hnemici->nem.getX()-1;
                int tmpy = l.hnemici->nem.getY();
                int ch1 = mvwinch(finestra,l.hnemici->nem.getY(), l.hnemici->nem.getX()-1)& A_CHARTEXT;
                if(ch1==' '){
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX()-1, l.hnemici->nem.getSimbolo());
                l.hnemici->nem.muoviSx();
                }else{
                    mvwaddch(finestra, l.hnemici->nem.getY(), l.hnemici->nem.getX(), ' ');
                    l.hnemici->nem.prendiDanno(1);
                    l.hnemici = l.appoggio;
                    l.rimuoviNemici();
                    controlloCasella(finestra, ch1, p.getArma(), tmpy, tmpx);
                }
            }
        }
        l.hnemici = l.hnemici->succ;
    }
    l.hnemici = l.appoggio;
}

//Metodo per uscire dal gioco
void GUI::esci(WINDOW* finestra){
    p.salva(gf);
    game.salva(gf);
    uscita = true;
    endwin();
}

//Metodo che attacca i nemici
void GUI::attacco(Arma arma, WINDOW* finestra){
    if(arma.getNome().compareTo(Stringa((char*) "Bastone"))==0){
        attaccoBastone(arma, finestra);
    }
    else if(arma.getNome().compareTo(Stringa((char*) "PallaChiodata"))==0){
        attaccoPalla(arma, finestra);
    }
    else if(arma.getNome().compareTo(Stringa((char*) "Spada"))==0){
        attaccoSpada(arma, finestra);
    }
    else if(arma.getNome().compareTo(Stringa((char*) "Arco"))==0){
        attaccoArco(arma, finestra);
    }

}

//Metodo che fa l'attacco con il bastone
void GUI::attaccoBastone(Arma arma,WINDOW* finestra){
    if(p.isVersoDestra()){
            int ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()+1);
        }else{
            int ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()-1);
        }
}

//Metodo che fa l'attacco con la mazza
void GUI::attaccoPalla(Arma arma,WINDOW* finestra){
        int ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;
        int ch2 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
        int ch3 = mvwinch(finestra,p.getY()-1, p.getX())& A_CHARTEXT;
        int ch4 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
        int ch5 = mvwinch(finestra,p.getY()-1, p.getX()+1)& A_CHARTEXT;
        int ch6 = mvwinch(finestra,p.getY()-1, p.getX()-1)& A_CHARTEXT;
        int ch7 = mvwinch(finestra,p.getY()+1, p.getX()-1)& A_CHARTEXT;
        int ch8 = mvwinch(finestra,p.getY()+1, p.getX()+1)& A_CHARTEXT;
        
        controlloCasella(finestra,ch1, arma,p.getY(), p.getX()+1);
        controlloCasella(finestra,ch2, arma,p.getY(), p.getX()-1);
        controlloCasella(finestra,ch3, arma,p.getY()-1, p.getX());
        controlloCasella(finestra,ch4, arma,p.getY()+1, p.getX());
        controlloCasella(finestra,ch5, arma,p.getY()-1, p.getX()+1);
        controlloCasella(finestra,ch6, arma,p.getY()-1, p.getX()-1);
        controlloCasella(finestra,ch7, arma,p.getY()+1, p.getX()-1);
        controlloCasella(finestra,ch8, arma,p.getY()+1, p.getX()+1);
        
}

//Metodo che fa l'attacco con la spada
void GUI::attaccoSpada(Arma arma,WINDOW* finestra){
    if(p.isVersoDestra()){
            int ch1 = mvwinch(finestra,p.getY(), p.getX()+2)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()+2);
            ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()+1);
        }else{
            int ch1 = mvwinch(finestra,p.getY(), p.getX()-2)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()-2);
            ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
            controlloCasella(finestra,ch1, arma,p.getY(), p.getX()-1);
        }
}

//Metodo che fa l'attacco con l'arco
void GUI::attaccoArco(Arma arma,WINDOW* finestra){
    if(p.isVersoDestra()){
        Freccia f = Freccia(p.getX(), p.getY(), '+', false);
        mvwaddch(finestra,f.getY(), f.getX(), f.getSimbolo());
        l.inserisciNemico(f);
    }else{
        Freccia f = Freccia(p.getX(), p.getY(), '+', true);
        mvwaddch(finestra,f.getY(), f.getX(), f.getSimbolo());
        l.inserisciNemico(f);
    }
}

//Metodo di controllo casella
void GUI::controlloCasella(WINDOW* finestra, int ch, Arma arma, int y, int x){
    l.appoggio = l.hnemici;
    if(ch=='G' || ch=='S' || ch=='{'){
            while(l.hnemici!=NULL){
                if(l.hnemici->nem.getX()==x && l.hnemici->nem.getY()==y){
                     l.hnemici->nem.prendiDanno(arma.getDanno());
                    if(l.hnemici->nem.getVita()==0){
                        mvwaddch(finestra,y, x, ' ');
                        p.guadagna(l.hnemici->nem.getRicompensa());
                        if(l.hnemici->nem.getSimbolo()=='{'){
                            mvwaddch(finestra,l.hnemici->succ->nem.getY(), l.hnemici->succ->nem.getX(), ' ');
                            l.hnemici->succ->nem.prendiDanno(1);
                        }
                    }
                }
                l.hnemici=l.hnemici->succ;
            }
    }
    l.hnemici = l.appoggio;
    l.rimuoviNemici();
}