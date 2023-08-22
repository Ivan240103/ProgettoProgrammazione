#include "Arma.hpp"

// costruttore default
Arma::Arma() {}

// costruttore
Arma::Arma(Stringa nome, int danno, int costo) {
  this->nome = nome;
  this->danno = danno;
  this->costo = costo;
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