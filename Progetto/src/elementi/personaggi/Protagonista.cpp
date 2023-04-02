#include "Protagonista.hpp"

// costruttore
Protagonista::Protagonista(Stringa nome) {
  this->nome = nome;
  this->vita = 100;
  this->denaro = 0;
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