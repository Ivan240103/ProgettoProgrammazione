#include "Arma.hpp"

// costruttore
Arma::Arma() {
  this->nome = Stringa((char*) "temp");
  this->danno = 5;
  this->costo = 100;
  this->distanza = false;
  this->intorno = false;
}

// costruttore
Arma::Arma(Stringa nome, int danno = 5, int costo = 100, bool distanza = false, bool intorno = false) {
  this->nome = nome;
  this->danno = danno;
  this->costo = costo;
  this->distanza = distanza;
  this->intorno = intorno;
}

Stringa Arma::getNome() {
  return nome;
}

int Arma::getDanno() {
  return danno;
}

int Arma::getCosto() {
  return costo;
}

bool Arma::isDistanza() {
  return distanza;
}

bool Arma::isIntorno() {
  return intorno;
}

// Postcondition: descrizione dell'arma
Stringa Arma::toString() {
  Stringa tr = nome;
  tr.concat(Stringa((char*) " - Danno: "));
  tr.concat(danno);
  tr.concat(Stringa((char*) ", Costo: "));
  tr.concat(costo);
  if (distanza) {
    tr.concat(Stringa((char*) ", Distanza: true"));
  } else {
    tr.concat(Stringa((char*) ", Distanza: false"));
  }
  if (intorno) {
    tr.concat(Stringa((char*) ", Intorno: true\n"));
  } else {
    tr.concat(Stringa((char*) ", Intorno: false\n"));
  }
  return tr;
}

Stringa Arma::getData() {
  Stringa tr = nome;
  tr.concat(',');
  tr.concat(danno);
  tr.concat(',');
  tr.concat(costo);
  if (distanza) {
    tr.concat(Stringa((char*) ",true"));
  } else {
    tr.concat(Stringa((char*) ",false"));
  }
  if (intorno) {
    tr.concat(Stringa((char*) ",true\n"));
  } else {
    tr.concat(Stringa((char*) ",false\n"));
  }
  return tr;
}