#include "Arma.hpp"

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