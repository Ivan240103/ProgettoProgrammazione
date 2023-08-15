#include "Arma.hpp"

// costruttore
Arma::Arma(Stringa nome, int danno, int costo, bool distanza, bool intorno, int coeff) {
  this->nome = nome;
  this->danno = danno;
  this->costo = costo;
  this->distanza = distanza;
  this->intorno = intorno;
  this->coeff = coeff;
}

// GETTERS

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

int Arma::getCoeff() {
  return coeff;
}

void Arma::setDanno(int danno){
  this->danno+=danno;
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
    tr.concat(Stringa((char*) ", Intorno: true"));
  } else {
    tr.concat(Stringa((char*) ", Intorno: false"));
  }
  tr.concat(Stringa((char*) ", Coefficiente: "));
  tr.concat(coeff);
  tr.concat('\n');
  return tr;
}