#include "Nemico.hpp"

// costruttore
Nemico::Nemico(Stringa nome, int vita, int minDanno, int maxDanno, bool distanza, int ricompensa, int x, int y) {
  this->nome = nome;
  this->vita = vita;
  srand(time(0));
  this->danno = rand() % (maxDanno - minDanno + 1) + minDanno;
  this->distanza = distanza;
  this->ricompensa = ricompensa;
  this->x = x;
  this->y = y;
}

// GETTERS

Stringa Nemico::getNome() {
  return nome;
}

int Nemico::getVita() {
  return vita;
}

int Nemico::getDanno() {
  return danno;
}

bool Nemico::isDistanza() {
  return distanza;
}

int Nemico::getRicompensa() {
  return ricompensa;
}

int Nemico::getX() {
  return x;
}

int Nemico::getY() {
  return y;
}

// riduce la vita al nemico
// Postcondition: true se è ancora vivo, false se è morto
bool Nemico::prendiDanno(int danno) {
  vita -= danno;
  if (vita <= 0) {
    vita = 0;
    return false;
  } else {
    return true;
  }
}

// Precondition: quantità x di cui spostarlo
void Nemico::muoviDx(int spost) {
  x += spost;
}

// Precondition: quantità x di cui spostarlo
void Nemico::muoviSx(int spost) {
  x -= spost;
}

// Precondition: quantità y di cui spostarlo
void Nemico::salta(int spost) {
  y += spost;
}

// Postcondition: descrizione del nemico
Stringa Nemico::toString() {
  Stringa tr = nome;
  tr.concat(Stringa((char*) " - Vita: "));
  tr.concat(vita);
  tr.concat(Stringa((char*) ", Danno: "));
  tr.concat(danno);
  if (distanza) {
    tr.concat(Stringa((char*) ", Distanza: true, Ricompensa: "));
  } else {
    tr.concat(Stringa((char*) ", Distanza: false, Ricompensa: "));
  }
  tr.concat(ricompensa);
  tr.concat(Stringa((char*) ", ("));
  tr.concat(x);
  tr.concat(',');
  tr.concat(y);
  tr.concat(')');
  tr.concat('\n');
  return tr;
}

// Postcondition: dati da salvare su file
Stringa Nemico::getData() {
  Stringa ts = nome;
  ts.concat(',');
  ts.concat(vita);
  ts.concat(',');
  ts.concat(danno);
  ts.concat(',');
  ts.concat(danno);
  ts.concat(',');
  if (distanza) {
    ts.concat(1);
  } else {
    ts.concat(0);
  }
  ts.concat(',');
  ts.concat(ricompensa);
  ts.concat(',');
  ts.concat(x);
  ts.concat(',');
  ts.concat(y);
  ts.concat('\n');
  return ts;
}