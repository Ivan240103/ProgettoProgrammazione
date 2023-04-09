#include "Protagonista.hpp"

// costruttore
Protagonista::Protagonista(Stringa nome) {
  this->nome = nome;
  this->vita = 100;
  this->denaro = 0;
  this->arma = Bastone();
  this->versoDestra = true;
}

Stringa Protagonista::getNome() {
  return nome;
}

int Protagonista::getVita() {
  return vita;
}

int Protagonista::getDenaro() {
  return denaro;
}

Arma Protagonista::getArma() {
  return arma;
}

bool Protagonista::isVersoDestra() {
  return versoDestra;
}

void Protagonista::guadagna(int soldi) {
  denaro += soldi;
}

// Postcondition: false se il denaro non è sufficiente, true se tutto apposto
bool Protagonista::spendi(int soldi) {
  bool tr = false;
  if (soldi <= denaro) {
    denaro -= soldi;
    tr = true;
  }
  return tr;
}

void Protagonista::cambiaArma(Arma a) {
  arma = a;
}

Stringa Protagonista::toString() {
  Stringa tr = nome;
  tr.concat(Stringa((char*) " - Vita: "));
  tr.concat(vita);
  tr.concat(Stringa((char*) ", Denaro: "));
  tr.concat(denaro);
  tr.concat(Stringa((char*) ", Arma: "));
  tr.concat(arma.getNome());
  if (versoDestra) {
    tr.concat(Stringa((char*) ", VersoDestra: true\n"));
  } else {
    tr.concat(Stringa((char*) ", VersoDestra: false\n"));
  }
  return tr;
}

Stringa Protagonista::getData() {
  Stringa tr = nome;
  tr.concat(',');
  tr.concat(vita);
  tr.concat(',');
  tr.concat(denaro);
  tr.concat(',');
  tr.concat(arma.getNome());
  if (versoDestra) {
    tr.concat(Stringa((char*) ",true\n"));
  } else {
    tr.concat(Stringa((char*) ",false\n"));
  }
  return tr;
}