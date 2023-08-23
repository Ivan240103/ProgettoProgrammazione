#include "Livello.hpp"

// rimuove il nemico in testa alla lista
void Livello::rimuoviTesta() {
  pnodo tmp = hnemici->succ;
  delete hnemici;
  hnemici = tmp;
}

// costruttore
Livello::Livello(int id, bool attuale) {
  this->id = id;
  this->attuale = attuale;
  this->hnemici = NULL;
}

// GETTERS

int Livello::getId() {
  return id;
}

bool Livello::isAttuale() {
  return attuale;
}

// il protagonista entra nel livello
void Livello::protagonistaArriva() {
  attuale = true;
}

// il protagonista lascia il livello
void Livello::protagonistaAddios() {
  attuale = false;
}

// aggiunge un nemico al livello in coda
void Livello::inserisciNemico(Nemico n) {
  pnodo tmp = new nodo;
  tmp->nem = n;
  if (hnemici == NULL) {
    tmp->succ = hnemici;
    hnemici = tmp;
  } else {
    pnodo mv = hnemici;
    while (mv->succ != NULL) {
      mv = mv->succ;
    }
    mv->succ = tmp;
  }
}

// rimuove tutti i nemici con 0 di vita
void Livello::rimuoviNemici() {
  while (hnemici != NULL && hnemici->nem.getVita() == 0) {
    rimuoviTesta();
  }
  if (hnemici != NULL) {
    pnodo mv = hnemici;
    while (mv->succ != NULL) {
      if (mv->succ->nem.getVita() == 0) {
        pnodo tmp = mv->succ->succ;
        delete mv->succ;
        mv->succ = tmp;
      } else {
        mv = mv->succ;
      }
    }
  }
}

// Postcondition: true se sono stati uccisi tutti i nemici, false altrimenti
bool Livello::isTerminato() {
  rimuoviNemici();
  return hnemici == NULL;
}

// salva il livello su file
// Precondition: il file deve essere già aperto e il chiamante
// deve occuparsi della sua chiusura
void Livello::salva(GestoreFile &gf) {
  Stringa scr = Stringa((char*) "@,");
  scr.concat(id);
  scr.concat(',');
  if (attuale) {
    scr.concat(1);
  } else {
    scr.concat(0);
  }
  scr.concat('\n');
  gf.scrivi(scr);
  pnodo mv = hnemici;
  while (mv != NULL) {
    gf.scrivi(mv->nem.getData());
    mv = mv->succ;
  }
}