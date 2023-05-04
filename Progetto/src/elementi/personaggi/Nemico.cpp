#include "Nemico.hpp"

// costruttore
Nemico::Nemico(Stringa nome, int vita, int minDanno, int maxDanno, bool distanza, int ricompensa) {
  this->nome = nome;
  this->vita = vita;
  srand(time(0));
  this->danno = rand() % (maxDanno - minDanno + 1) + minDanno;
  this->distanza = distanza;
  this->ricompensa = ricompensa;
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
  tr.concat('\n');
  return tr;
}

// Postcondition: dati da salvare su file
Stringa Nemico::getData() {
  Stringa tr = nome;
  tr.concat(',');
  tr.concat(vita);
  tr.concat(',');
  tr.concat(danno);
  tr.concat(',');
  tr.concat(danno);
  tr.concat(',');
  if (distanza) {
    tr.concat(1);
  } else {
    tr.concat(0);
  }
  tr.concat(',');
  tr.concat(ricompensa);
  tr.concat('\n');
  return tr;
}