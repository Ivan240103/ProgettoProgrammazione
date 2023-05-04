#include "Livello.hpp"

// rimuove il nemico in testa alla lista
void Livello::rimuoviTesta() {
  if (hnemici != NULL) {
    pnodo tmp = hnemici->succ;
    delete hnemici;
    hnemici = tmp;
  }
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

// aggiunge un nemico al livello
void Livello::inserisciNemico(Nemico n) {
  pnodo tmp = new nodo;
  tmp->nem = n;
  tmp->succ = hnemici;
  hnemici = tmp;
}

// rimuove tutti i nemici con 0 di vita
void Livello::rimuoviNemici() {
  while (hnemici != NULL && hnemici->nem.getVita() == 0) {
    rimuoviTesta();
  }
  if (hnemici != NULL /*&& hnemici->succ != NULL*/) {
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