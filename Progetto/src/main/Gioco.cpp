#include "Gioco.hpp"

// aggiunge un nuovo livello come ultimo
void Gioco::aggiungiLivello(int id) {
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

// elimina i salvataggi della partita precedente
void Gioco::eliminaSalvataggi() {
  gf.apriOutput(gf.getFilePartita());
  gf.scrivi(Stringa((char*) ""));
  gf.chiudiOutput();
}

Gioco::Gioco(bool reset, int diffPrimoLivello) {
  this->gf = GestoreFile();
  hlivelli = NULL;
  attuale = NULL;
  if (reset) {
    // elimina il salvataggio della partita precedente
    eliminaSalvataggi();
    // creazione primo livello
    aggiungiLivello(diffPrimoLivello);
    attuale = hlivelli;
    attuale->l.protagonistaArriva();
  } else {
    // TODO: recuperare i dati precedenti e ricreare la lista dei livelli
  }
}

// sposta il protagonista nel livello successivo se possibile
void Gioco::muoviAvanti() {
  if (attuale->l.isTerminato()) {
    if (attuale->succ == NULL) {
      aggiungiLivello(attuale->l.getId() + 1);
    }
    attuale->l.protagonistaAddios();
    attuale = attuale->succ;
    attuale->l.protagonistaArriva();
  }
}

// sposta il protagonista nel livello precedente
void Gioco::muoviIndietro() {
  if (attuale->prec != NULL) {
    attuale = attuale->prec;
  }
}

// salva la partita su file
void Gioco::salva() {
  gf.apriOutput(gf.getFilePartita(), true);
  pliv mv = hlivelli;
  while (mv != NULL) {
    mv->l.salva(gf);
    mv = mv->succ;
  }
  gf.chiudiOutput();
}