#include "Nemico.hpp"

// costruttore
Nemico::Nemico(Stringa nome, char simbolo, int vita, int minDanno, int maxDanno, int ricompensa, int x, int y, bool sx) {
  this->nome = nome;
  this->simbolo = simbolo;
  this->vita = vita;
  this->danno = rand() % (maxDanno - minDanno + 1) + minDanno;
  this->ricompensa = ricompensa;
  this->x = x;
  this->y = y;
  this->sx = sx;
}

// GETTERS

Stringa Nemico::getNome() {
  return nome;
}

char Nemico::getSimbolo() {
  return simbolo;
}

int Nemico::getVita() {
  return vita;
}

int Nemico::getDanno() {
  return danno;
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

bool Nemico::getSx(){
  return sx;
}

void Nemico::setX(int x){
  this->x = x;
}

void Nemico::setY(int y){
  this->y = y;
}

void Nemico::setSx(bool valore){
  this->sx = valore;
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

void Nemico::MuoviSuGiu(int sposta){
  this->y += sposta;
}

// Precondition: quantità x di cui spostarlo
void Nemico::muoviDx(int spost) {
  x += spost;
}

// Precondition: quantità x di cui spostarlo
void Nemico::muoviSx(int spost) {
  x -= spost;
}

// Postcondition: dati da salvare su file
Stringa Nemico::getData() {
  Stringa ts = nome;
  ts.concat(',');
  ts.concat(simbolo);
  ts.concat(',');
  ts.concat(vita);
  ts.concat(',');
  ts.concat(danno);
  ts.concat(',');
  ts.concat(ricompensa);
  ts.concat(',');
  ts.concat(x);
  ts.concat(',');
  ts.concat(y);
  ts.concat(',');
  ts.concat(sx);
  ts.concat('\n');
  return ts;
}