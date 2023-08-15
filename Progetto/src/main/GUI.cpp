#include "GUI.hpp"

// metodo per creare una mappa con pattern casuale
// Precondition: nuovo = true se bisogna creare i nemici (livello nuovo)
void GUI::creaMappa(int det, int mv, WINDOW* win, bool nuovo){
    int v = rand() % 3;
    switch (det){
        case 0:
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            break;
        case 1:
            mvwprintw(win, 18, mv, "  ===     ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 17, mv+4, v);
            }
            break;
        case 2:
            mvwprintw(win, 17, mv, "     ===  ");
            mvwprintw(win, 18, mv, "  ========");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 16, mv+7, v);
            }
            break;
        case 3:
            mvwprintw(win, 15, mv, "    ==    ");
            mvwprintw(win, 16, mv, "   ====   ");
            mvwprintw(win, 17, mv, "  ======  ");
            mvwprintw(win, 18, mv, "==========");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 14, mv+5, v);
            }
            break;
        case 4:
            mvwprintw(win, 18, mv, "  =  =    ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 18, mv+8, v);
            }
            break;
        case 5:
            mvwprintw(win, 17, mv, "  ======= ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 18, mv+5, v);
            }
            break;
        case 6:
        	mvwprintw(win, 17, mv, "   =      ");
            mvwprintw(win, 18, mv, "  ===     ");
			mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 18, mv+8, v);
            }
            break;
        case 7:
            mvwprintw(win, 17, mv, "   =      ");
            mvwprintw(win, 18, mv, "  ======  ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 18, mv+8, v);
            }
            break;
        case 8:	
            mvwprintw(win, 17, mv, "      =   ");
            mvwprintw(win, 18, mv, "    ====  ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 18, mv+1, v);
            }
            break;
        case 9:	
            mvwprintw(win, 17, mv, "      =   ");
            mvwprintw(win, 18, mv, "  =  ===  ");
            mvwprintw(win, 19, mv, "==========");
            mvwprintw(win, 20, mv, "==========");
            if (nuovo) {
                creaNemico(win, 17, mv+3, v);
            }
            break;
    }
}

//Metodo che stampa la mappa relativa al livello
// Precondition: nuovo = true se bisogna creare i nemici (livello nuovo)
void GUI::stampaMappa(WINDOW* win, bool nuovo){
    //TODO: controllare gestione dei livelli (numero e forza dei nemici...)
    creaMappa(0,1, win, nuovo);
    creaMappa((game.attuale->l.getId()*7)%9 ,11, win, nuovo);
    creaMappa((game.attuale->l.getId()*5)%9 ,21, win, nuovo);
    creaMappa((game.attuale->l.getId()*6)%9 ,31, win, nuovo);
    creaMappa((game.attuale->l.getId()*8)%9 ,41, win, nuovo);
    creaMappa((game.attuale->l.getId()*3)%9 ,51, win, nuovo);
    creaMappa(0,61, win, nuovo);
    stampaNemici(win);
}

//Stampa il protagonista in una determinata posizione e in una determinata finestra
void GUI::stampaProtagonista(WINDOW *finestra, int y, int x){
    mvwaddch(finestra, y, x, p.getSimbolo());
}

//Metodo che crea i nemici e li aggiunge al livello
void GUI::creaNemico(WINDOW* win, int y, int x, int random){
    Goblin gob;
    Scheletro schel;
    Freccia f;
    Guardia gua;
    switch(random){
        case 0:
            gob = Goblin(x,y);
            game.attuale->l.inserisciNemicoTesta(gob);
            break;
        case 1:
            schel = Scheletro(x,y);
            f = Freccia(x-1,y);
            game.attuale->l.inserisciNemicoTesta(f);
            game.attuale->l.inserisciNemicoTesta(schel);
            break;
        case 2:
            gua = Guardia(x,y);
            game.attuale->l.inserisciNemicoTesta(gua);
            break;
    }
}

// stampa tutti i nemici del livello
void GUI::stampaNemici(WINDOW* finestra) {
    Nemico nem = Nemico(Stringa((char*) "tmp"));
    game.attuale->l.appoggio = game.attuale->l.hnemici;
    while (game.attuale->l.appoggio != NULL) {
        nem = game.attuale->l.appoggio->nem;
        mvwaddch(finestra, nem.getY(), nem.getX(), nem.getSimbolo());
        game.attuale->l.appoggio = game.attuale->l.appoggio->succ;
    }
}

//Metodo per gestire l'azione a seconda del tasto scelto
// Postcondition: true se il gioco prosegue, false per uscire
// TODO: controllare utilizzo del negozio
bool GUI::getAction(WINDOW* finestra){
    bool prosegui = true;
    int scelta = wgetch(finestra);
    switch (scelta){
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
            prosegui = false;
            break;
        case 119:
            attacco(finestra);
            break;
    }
    return prosegui;
}

//Metodo salto
void GUI::mvup(WINDOW* finestra){
    isJump = true;
    int ch1 = mvwinch(finestra,p.getY()-1, p.getX())& A_CHARTEXT;
    int ch2 = mvwinch(finestra,p.getY()+1, p.getX())& A_CHARTEXT;
    if((ch1==' ') && (ch2!=' ')){
        mvwaddch(finestra, p.getY(), p.getX(), ' ');
        p.salta();
        stampaProtagonista(finestra, p.getY(), p.getX());
    }
}

//Metodo muovi a sinistra
void GUI::mvleft(WINDOW* finestra){
    p.setVersoDestra(false);
    int ch1 = mvwinch(finestra, p.getY(), p.getX()-1)& A_CHARTEXT;
    if(ch1==' '){
        mvwaddch(finestra, p.getY(), p.getX(), ' ');
        p.muoviSx();
        if(p.getX() < 1){
            p.setX(1);
        }
    }else if(ch1=='#'){
        if (game.muoviIndietro()) {
            // indietro di livello
            mvwaddch(finestra, 20, 70, ' ');
            wrefresh(finestra);
            werase(finestra);
            box(finestra, 0, 0);
            p.resetPosizione();
            stampaMappa(finestra);
        }
    }
}

//Metodo muovi a destra
void GUI::mvright(WINDOW* finestra){
    p.setVersoDestra(true);
    int ch1 = mvwinch(finestra, p.getY(), p.getX()+1)& A_CHARTEXT;
    if(ch1==' '){
        mvwaddch(finestra, p.getY(), p.getX(), ' ');
        p.muoviDx();
        if(p.getX() > this->larghezza-2){
            p.setX(this->larghezza-2);
        }
    }else if(ch1 == '#'){
        bool ultimo = game.attuale->succ == NULL;
        if (game.muoviAvanti()) {
            mvwaddch(finestra, 20, 70, ' ');
            wrefresh(finestra);
            werase(finestra);
            box(finestra, 0, 0);
            p.resetPosizione();
            stampaMappa(finestra, ultimo);
        }
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

//Metodo per definire gli spostamenti dei nemici
void GUI::movimentiNemico(WINDOW* finestra){
    game.attuale->l.appoggio = game.attuale->l.hnemici;
    while(game.attuale->l.hnemici != NULL){
        if(game.attuale->l.hnemici->nem.getSimbolo() == 'G'){
            int ch1 = mvwinch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
            int ch2 = mvwinch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch3 = mvwinch(finestra, game.attuale->l.hnemici->nem.getY()+1, game.attuale->l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch4 = mvwinch(finestra, game.attuale->l.hnemici->nem.getY()+1, game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' ' && game.attuale->l.hnemici->nem.getSx()==true && ch4!=' '){
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                game.attuale->l.hnemici->nem.muoviSx();
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
            }else{
                game.attuale->l.hnemici->nem.setSx(false);
                if(ch1=='@' && hit==false){
                    p.prendiDanno(game.attuale->l.hnemici->nem.getDanno());
                    hit=true;
                }else if(ch2==' ' && ch3!=' '){
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.muoviDx();
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }else{
                    game.attuale->l.hnemici->nem.setSx(true);
                    if(ch2=='@' && hit==false){
                        p.prendiDanno(game.attuale->l.hnemici->nem.getDanno());
                        hit=true;
                    }
                }
            }
        }else if(game.attuale->l.hnemici->nem.getSimbolo() == 'S'){
            int ch1 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
            int ch2 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch3 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY()+1, game.attuale->l.hnemici->nem.getX()+1)& A_CHARTEXT;
            int ch4 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY()+1, game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' ' && p.getX()<game.attuale->l.hnemici->nem.getX() && ch4!=' '){
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                game.attuale->l.hnemici->nem.muoviSx();
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
            }else{
                if(ch1=='@' && hit==false){
                    p.prendiDanno(game.attuale->l.hnemici->nem.getDanno());
                    hit=true;
                }else if(ch4==' '){
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.muoviSx();
                    game.attuale->l.hnemici->nem.MuoviSuGiu(1);
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }
                if(ch2==' ' && p.getX()>game.attuale->l.hnemici->nem.getX() && ch3!=' '){
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.muoviDx();
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }else{
                    if(ch2=='@' && hit==false){
                        p.prendiDanno(game.attuale->l.hnemici->nem.getDanno());
                        hit=true;
                    }
                    if(ch3==' '){
                        mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                        game.attuale->l.hnemici->nem.muoviDx();
                        game.attuale->l.hnemici->nem.MuoviSuGiu(1);
                        mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                    }
                }
            }
        }else if(game.attuale->l.hnemici->nem.getSimbolo() == '{'){
            int tmpx = game.attuale->l.hnemici->nem.getX()-1;
            int tmpy = game.attuale->l.hnemici->nem.getY();
            game.attuale->l.hnemici = game.attuale->l.hnemici->succ;
            int ch1 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
            if(ch1==' '){
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                game.attuale->l.hnemici->nem.muoviSx();
                mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
            }else{
                if(ch1=='@' && hit==false){
                    p.prendiDanno(game.attuale->l.hnemici->nem.getDanno());
                    hit=true;
                }else{
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.setX(tmpx);
                    game.attuale->l.hnemici->nem.setY(tmpy);
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }
            }
        }else if(game.attuale->l.hnemici->nem.getSimbolo() == '+'){
            // TODO: controllare su che lista lavora controllaCasella()
            if(!game.attuale->l.hnemici->nem.getSx()){
                int ch1 = mvwinch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()+1)& A_CHARTEXT;
                if(ch1==' '){
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.muoviDx();
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }else{
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.prendiDanno(1);
                    controlloCasella(finestra, ch1, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()+1);
                }
            }else{
                int ch1 = mvwinch(finestra,game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()-1)& A_CHARTEXT;
                if(ch1==' '){
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.muoviSx();
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), game.attuale->l.hnemici->nem.getSimbolo());
                }else{
                    mvwaddch(finestra, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX(), ' ');
                    game.attuale->l.hnemici->nem.prendiDanno(1);
                    controlloCasella(finestra, ch1, game.attuale->l.hnemici->nem.getY(), game.attuale->l.hnemici->nem.getX()-1);
                }
            }
        }
        game.attuale->l.hnemici = game.attuale->l.hnemici->succ;
    }
    game.attuale->l.hnemici = game.attuale->l.appoggio;
    // TODO: rimozione nemici (se non viene fatta da controllaCasella())
}

//Metodo che attacca i nemici
void GUI::attacco(WINDOW* finestra){
    if(p.getArma().getNome().compareTo(Stringa((char*) "Bastone"))==0){
        attaccoBastone(finestra);
    }
    else if(p.getArma().getNome().compareTo(Stringa((char*) "Spada"))==0){
        attaccoSpada(finestra);
    }
    else if(p.getArma().getNome().compareTo(Stringa((char*) "PallaChiodata"))==0){
        attaccoPalla(finestra);
    }
    else if(p.getArma().getNome().compareTo(Stringa((char*) "Arco"))==0){
        attaccoArco(finestra);
    }
}

//Metodo che fa l'attacco con il bastone
void GUI::attaccoBastone(WINDOW* finestra){
    if(p.isVersoDestra()){
        int ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()+1);
    }else{
        int ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()-1);
    }
}

//Metodo che fa l'attacco con la spada
void GUI::attaccoSpada(WINDOW* finestra){
    if(p.isVersoDestra()){
        int ch1 = mvwinch(finestra,p.getY(), p.getX()+1)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()+1);
        ch1 = mvwinch(finestra,p.getY(), p.getX()+2)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()+2);
    }else{
        int ch1 = mvwinch(finestra,p.getY(), p.getX()-1)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()-1);
        ch1 = mvwinch(finestra,p.getY(), p.getX()-2)& A_CHARTEXT;
        controlloCasella(finestra,ch1, p.getY(), p.getX()-2);
    }   
}

//Metodo che fa l'attacco con la palla chiodata
void GUI::attaccoPalla(WINDOW* finestra){
    int ch1 = mvwinch(finestra, p.getY(), p.getX()+1)& A_CHARTEXT;
    int ch2 = mvwinch(finestra, p.getY(), p.getX()-1)& A_CHARTEXT;
    int ch3 = mvwinch(finestra, p.getY()-1, p.getX())& A_CHARTEXT;
    int ch4 = mvwinch(finestra, p.getY()+1, p.getX())& A_CHARTEXT;
    int ch5 = mvwinch(finestra, p.getY()-1, p.getX()+1)& A_CHARTEXT;
    int ch6 = mvwinch(finestra, p.getY()-1, p.getX()-1)& A_CHARTEXT;
    int ch7 = mvwinch(finestra, p.getY()+1, p.getX()-1)& A_CHARTEXT;
    int ch8 = mvwinch(finestra, p.getY()+1, p.getX()+1)& A_CHARTEXT;
    
    controlloCasella(finestra, ch1, p.getY(), p.getX()+1);
    controlloCasella(finestra, ch2, p.getY(), p.getX()-1);
    controlloCasella(finestra, ch3, p.getY()-1, p.getX());
    controlloCasella(finestra, ch4, p.getY()+1, p.getX());
    controlloCasella(finestra, ch5, p.getY()-1, p.getX()+1);
    controlloCasella(finestra, ch6, p.getY()-1, p.getX()-1);
    controlloCasella(finestra, ch7, p.getY()+1, p.getX()-1);
    controlloCasella(finestra, ch8, p.getY()+1, p.getX()+1);
}

//Metodo che fa l'attacco con l'arco
void GUI::attaccoArco(WINDOW* finestra){
    Freccia f = Freccia(p.getX(), p.getY(), '+', !p.isVersoDestra());
    mvwaddch(finestra,f.getY(), f.getX(), f.getSimbolo());
    game.attuale->l.inserisciNemicoCoda(f);
}

//Metodo di controllo casella per l'attacco al nemico
// Precondition: finestra, carattere nella casella, coordinate della casella
// TODO: utilizzo di una lista tmp all'interno del livello attuale (?)
void GUI::controlloCasella(WINDOW* finestra, int ch, int y, int x){
    bool colpito = false;
    game.attuale->l.appoggio = game.attuale->l.hnemici;
    if(ch=='G' || ch=='S' || ch=='{'){
        while(game.attuale->l.hnemici!=NULL && !colpito) {
            if(game.attuale->l.hnemici->nem.getX()==x && game.attuale->l.hnemici->nem.getY()==y){
                if(!game.attuale->l.hnemici->nem.prendiDanno(p.infliggiDanno())){
                    // nemico morto
                    mvwaddch(finestra, y, x, ' ');
                    p.guadagna(game.attuale->l.hnemici->nem.getRicompensa());
                    // se era uno scheletro elimina anche le frecce
                    if(game.attuale->l.hnemici->nem.getSimbolo()=='{'){
                        mvwaddch(finestra,game.attuale->l.hnemici->succ->nem.getY(), game.attuale->l.hnemici->succ->nem.getX(), ' ');
                        game.attuale->l.hnemici->succ->nem.prendiDanno(1);
                    }
                }
                colpito = true;
            }
            game.attuale->l.hnemici = game.attuale->l.hnemici->succ;
        }
    }
    game.attuale->l.hnemici = game.attuale->l.appoggio;
    game.attuale->l.rimuoviNemici();
}

//Metodo per uscire dal gioco
void GUI::esci(WINDOW* finestra, bool morto = true){
    if (morto) {
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
    }
    p.salva(gf);
    game.salva(gf);
    endwin();
}

GUI::GUI() {
    if (p.getVita() <= 0) {
        this->game = Gioco(this->gf, true);
    } else {
        this->game = Gioco(this->gf, false);
    }
}

//Metodo che crea la finestra di gioco
WINDOW* GUI::creaFinestra(){
    WINDOW *finestra = newwin(this->altezza, this->larghezza, 10, 10);
    box(finestra, 0,0);
    wrefresh(finestra);
    keypad(finestra, true);
    return finestra;
}

//Metodo dal quale viene avviato il gioco, e che contiene tutti i metodi che rispecchiano una dinamica reale
void GUI::gioco(WINDOW* finestra){
    bool prosegui = true;
    int gravita=0;
    nodelay(finestra, TRUE);
    stampaMappa(finestra);
    do{
        //stampo i valori vita e denaro in modo tale che ogni volta si modifichino con i soldi ottenuti o la vita tolta
        mvwprintw(finestra, 2,2, "   ");
        mvwprintw(finestra, 2,2, "%d", p.getVita());
        mvwprintw(finestra, 2,5, "/100 <3");
        // TODO: stampa di nome + punti del protagonista
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
            stampaProtagonista(finestra, p.getY(), p.getX());
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

        stampaProtagonista(finestra, p.getY(), p.getX());
        prosegui = getAction(finestra);

        wrefresh(finestra);
        gravita++;

    }while(p.getVita()>0 && prosegui);
    esci(finestra, p.getVita()<=0);
}