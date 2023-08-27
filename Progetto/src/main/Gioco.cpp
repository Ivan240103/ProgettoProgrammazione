#include "Gioco.hpp"

// cerca se l'id passato è già presente
// Postcondition: true se l'id esiste, false altrimenti
bool Gioco::cercaIdLivello(int id) {
  pliv mv = hlivelli;
  bool esiste = false;
  while (mv != NULL && !esiste) {
    if (mv->l.getId() == id) {
      esiste = true;
    } else {
      mv = mv->succ;
    }
  }
  return esiste;
}

// aggiunge un nuovo livello creato da zero come ultimo
// nemici vengono aggiunti da un altro metodo
void Gioco::creaLivello() {
  pliv nuovo = new liv;
  int id;
  // l'id deve essere univoco
  do {
    id = rand()%100 + 1;
  } while (cercaIdLivello(id));
  nuovo->l = Livello(id, false);
  nuovo->prec = attuale;
  if (hlivelli == NULL) {
    hlivelli = nuovo;
  } else {
    attuale->succ = nuovo;
  }
}

// inserimento in coda di un livello esistente
void Gioco::aggiungiLivello(Livello livello) {
  pliv nuovo = new liv;
  nuovo->l = livello;
  if (hlivelli == NULL) {
    hlivelli = nuovo;
  } else {
    pliv mv = hlivelli;
    while (mv->succ != NULL) {
      mv = mv->succ;
    }
    nuovo->prec = mv;
    mv->succ = nuovo;
  }
}

// imposta il puntatore attuale al livello in cui si trova il proagonista
void Gioco::setAttuale() {
  pliv mv = hlivelli;
  while (!mv->l.isAttuale()) {
    mv = mv->succ;
  }
  attuale = mv;
}

// elimina i salvataggi della partita precedente
void Gioco::eliminaSalvataggi(GestoreFile &gf) {
  gf.apriOutput(gf.getFilePartita());
  gf.scrivi(Stringa((char*) ""));
  gf.chiudiOutput();
}

// resetta lo stato della parita
void Gioco::resetta(GestoreFile &gf) {
  eliminaSalvataggi(gf);
  // creazione primo livello
  Livello primo = Livello(0, true);
  aggiungiLivello(primo);
  setAttuale();
}

// carica i dati salvati su file per riprendere la partita
void Gioco::caricaSalvataggi(GestoreFile &gf) {
  int f_id, f_vita, f_danno, f_ricompensa, f_x, f_y;
  char f_simbolo;
  bool prosegui, f_attuale, f_sx;
  gf.apriInput(gf.getFilePartita());
  Stringa input = gf.leggiParola();
  do {
    // livello appena caricato
    f_id = gf.leggiParola().toInt();
    f_attuale = gf.leggiParola().toInt();
    Livello livello = Livello(f_id, f_attuale);
    // aggiunta dei nemici
    do {
      prosegui = true;
      input = gf.leggiParola();
      if (input.compareTo(Stringa((char*) "@")) == 0 || input.compareTo(Stringa((char*) "#")) == 0) {
        // fine livello o fine file
        prosegui = false;
      } else {
        // nemici da caricare
        f_simbolo = gf.leggiParola().s[0];
        f_vita = gf.leggiParola().toInt();
        f_danno = gf.leggiParola().toInt();
        f_ricompensa = gf.leggiParola().toInt();
        f_x = gf.leggiParola().toInt();
        f_y = gf.leggiParola().toInt();
        f_sx = gf.leggiParola().toInt();
        Nemico n = Nemico(input, f_simbolo, f_vita, f_danno, f_danno, f_ricompensa, f_x, f_y, f_sx);
        livello.inserisciNemico(n);
      }
    } while (prosegui);
    // aggiunta livello alla lista
    aggiungiLivello(livello);
  } while (input.compareTo(Stringa((char*) "#")) != 0);
  setAttuale();
  gf.chiudiInput();
}

// costruttore default
Gioco::Gioco() {}

// costruttore
// Precondition: reset true se bisogna ricominciare la partita dal primo livello
// false se si carica quella precedente da file
Gioco::Gioco(GestoreFile &gf, bool reset) {
  this->hlivelli = NULL;
  this->attuale = NULL;
  if (reset) {
    resetta(gf);
  } else {
    caricaSalvataggi(gf);
  }
}

// sposta il protagonista nel livello successivo se possibile
// Postcondition: true se si è mosso, false altrimenti
bool Gioco::muoviAvanti() {
  bool mosso = false;
  if (attuale->l.isTerminato()) {
    if (attuale->succ == NULL) {
      creaLivello();
    }
    attuale->l.protagonistaAddios();
    attuale = attuale->succ;
    attuale->l.protagonistaArriva();
    mosso = true;
  }
  return mosso;
}

// sposta il protagonista nel livello precedente se possibile
// Postcondition: true se si è mosso, false altrimenti
bool Gioco::muoviIndietro() {
  bool mosso = false;
  if (attuale->prec != NULL) {
    attuale->l.protagonistaAddios();
    attuale = attuale->prec;
    attuale->l.protagonistaArriva();
    mosso = true;
  }
  return mosso;
}

// rimuove i nemici con zero di vita dal livello attuale
void Gioco::rimuoviNemici() {
  attuale->l.rimuoviNemici();
}

// Postcondition: numero dei livelli affrontati
int Gioco::numeroLivelli() {
  int n = 0;
  pliv mv = hlivelli;
  while (mv != NULL) {
    n++;
    mv = mv->succ;
  }
  return n;
}

// salva la partita su file
void Gioco::salva(GestoreFile &gf) {
  eliminaSalvataggi(gf);
  gf.apriOutput(gf.getFilePartita(), true);
  pliv mv = hlivelli;
  while (mv != NULL) {
    mv->l.salva(gf);
    mv = mv->succ;
  }
  gf.scrivi(Stringa((char*) "#"));
  gf.chiudiOutput();
}