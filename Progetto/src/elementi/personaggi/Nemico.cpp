#include "Nemico.hpp"

// costruttore
Nemico::Nemico(Stringa nome, int vita = 10, int minDanno = 1, int maxDanno = 1, bool distanza = false, int ricompensa = 2) {
  this->nome = nome;
  this->vita = vita;
  srand(time(0));
  this->danno = rand() % (maxDanno - minDanno + 1) + minDanno;
  this->distanza = distanza;
  this->ricompensa = ricompensa;
}

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

Stringa Nemico::getData() {
  Stringa tr = nome;
  tr.concat(',');
  tr.concat(vita);
  tr.concat(',');
  tr.concat(danno);
  tr.concat(',');
  tr.concat(danno);
  if (distanza) {
    tr.concat(Stringa((char*) ",true,"));
  } else {
    tr.concat(Stringa((char*) ",false,"));
  }
  tr.concat(ricompensa);
  tr.concat('\n');
  return tr;
}