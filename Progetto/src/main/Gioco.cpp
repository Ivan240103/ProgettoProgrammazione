#include "Gioco.hpp"
// DEBUG: rimuovere quando non servirà più
#include <iostream>

// aggiunge un nuovo livello come ultimo
void Gioco::creaLivello(int id) {
  pliv nuovo = new liv;
  nuovo->l = Livello(id, false);
  // algoritmo greedy per generare i nemici
  while (id > 0) {
    if (id >= 5) {
      nuovo->l.inserisciNemico(Guardia());
      id -= 5;
    } else if (id >= 2) {
      nuovo->l.inserisciNemico(Goblin());
      id -= 2;
    } else {
      nuovo->l.inserisciNemico(Scheletro());
      id--;
    }
  }
  nuovo->prec = attuale;
  if (hlivelli == NULL) {
    hlivelli = nuovo;
  } else {
    attuale->succ = nuovo;
  }
}

// inserimento in coda di un nuovo livello
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
void Gioco::resetta(int diffPrimoLivello, GestoreFile &gf) {
  // elimina il salvataggio della partita precedente
  eliminaSalvataggi(gf);
  // creazione primo livello
  creaLivello(diffPrimoLivello);
  attuale = hlivelli;
  attuale->l.protagonistaArriva();
}

// carica i dati salvati su file per riprendere la partita
void Gioco::caricaSalvataggi(GestoreFile &gf) {
  int f_id, f_vita, f_mindanno, f_maxdanno, f_ricompensa, f_x, f_y;
  bool prosegui, f_attuale, f_distanza;
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
        f_vita = gf.leggiParola().toInt();
        f_mindanno = gf.leggiParola().toInt();
        f_maxdanno = gf.leggiParola().toInt();
        f_distanza = gf.leggiParola().toInt();
        f_ricompensa = gf.leggiParola().toInt();
        f_x = gf.leggiParola().toInt();
        f_y = gf.leggiParola().toInt();
        Nemico n = Nemico(input, f_vita, f_mindanno, f_maxdanno, f_distanza, f_ricompensa, f_x, f_y);
        livello.inserisciNemico(n);
      }
    } while (prosegui);
    // aggiunta livello alla lista
    aggiungiLivello(livello);
  } while (input.compareTo(Stringa((char*) "#")) != 0);
  setAttuale();
  gf.chiudiInput();
}

Gioco::Gioco() {}

Gioco::Gioco(GestoreFile &gf, bool reset, int diffPrimoLivello) {
  this->hlivelli = NULL;
  this->attuale = NULL;
  if (reset) {
    resetta(diffPrimoLivello, gf);
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
      creaLivello(attuale->l.getId() + 1);
    }
    attuale->l.protagonistaAddios();
    attuale = attuale->succ;
    attuale->l.protagonistaArriva();
    mosso = true;
  }
  return mosso;
}

// sposta il protagonista nel livello precedente
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

void Gioco::rimuoviNemici() {
  attuale->l.rimuoviNemici();
}

void Gioco::debug() {
  /* pliv mv = hlivelli;
  while (mv != NULL) {
    mv->l.debug();
    mv = mv->succ;
  } */
  cout<<"Attuale: "<<endl;
  attuale->l.debug();
}

bool Gioco::attaccaNemico(int dannoSubito) {
  return attuale->l.attaccaNemico(dannoSubito);
}

Nemico Gioco::getPrimoNemico() {
  return attuale->l.getPrimoNemico();
}