#include "Protagonista.hpp"

// costruttore default
Protagonista::Protagonista() {}

// costruttore
Protagonista::Protagonista(GestoreFile &gf) {
  gf.apriInput(gf.getFileProtagonista());

  this->nome = gf.leggiParola();
  this->simbolo = '@';
  this->vita = gf.leggiParola().toInt();
  this->denaro = gf.leggiParola().toInt();
  Stringa f_arma_tmp = gf.leggiParola();
  if (f_arma_tmp.compareTo(Stringa((char*) "Spada")) == 0) {
    this->arma = Spada();
  } else if (f_arma_tmp.compareTo(Stringa((char*) "PallaChiodata")) == 0) {
    this->arma = PallaChiodata();
  } else if (f_arma_tmp.compareTo(Stringa((char*) "Arco")) == 0) {
    this->arma = Arco();
  } else {
    this->arma = Bastone();
  }
  Stringa f_pot = gf.leggiParola();
  int f_durataPot = gf.leggiParola().toInt();
  if (f_pot.compareTo(Stringa((char*) "UltraDanno")) == 0) {
    this->potenziamento = UltraDanno(f_durataPot);
  } else if (f_pot.compareTo(Stringa((char*) "SuperScudo")) == 0) {
    this->potenziamento = SuperScudo(f_durataPot);
  } else {
    this->potenziamento = Potenziamento(f_pot);
  }
  this->punti = gf.leggiParola().toInt();
  this->x = gf.leggiParola().toInt();
  this->y = gf.leggiParola().toInt();
  this->versoDestra = gf.leggiParola().toInt();

  gf.chiudiInput();
}

// GETTERS

Stringa Protagonista::getNome() {
  return nome;
}

char Protagonista::getSimbolo() {
  return simbolo;
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

Potenziamento Protagonista::getPotenziamento() {
  return potenziamento;
}

int Protagonista::getPunti() {
  return punti;
}

int Protagonista::getX() {
  return x;
}

int Protagonista::getY() {
  return y;
}

bool Protagonista::isVersoDestra() {
  return versoDestra;
}

void Protagonista::setX(int x){
  this->x = x;
}

void Protagonista::setY(int y){
  this->y = y;
}

void Protagonista::setVersoDestra(bool verso){
  versoDestra = verso;
}

// aumenta la vita al protagonista
void Protagonista::aumentaVita(int vita){
  this->vita += vita;
}

// riduce la vita al protagonista
void Protagonista::prendiDanno(int danno) {
  // se ha il potenziamento non prende danno
  if (!(potenziamento.getNome().compareTo(Stringa((char*) "SuperScudo")) == 0 && potenziamento.getDurata() > 0)) {
    vita -= danno;
    if (vita < 0) {
      vita = 0;
    }
  }
}

// Postcondition: danno causabile dal protagonista
int Protagonista::infliggiDanno() {
  // se ha il potenziamento deve uccidere in un colpo
  if (potenziamento.getNome().compareTo(Stringa((char*) "UltraDanno")) == 0 && potenziamento.getDurata() > 0) {
    return 1000;
  } else {
    return arma.getDanno();
  }
}

// incrementa il denaro
void Protagonista::guadagna(int soldi) {
  denaro += soldi;
}

// decrementa il denaro
// Postcondition: false se il denaro non è sufficiente, true se è abbastanza
bool Protagonista::spendi(int soldi) {
  bool tr = false;
  if (soldi <= denaro) {
    denaro -= soldi;
    tr = true;
  }
  return tr;
}

// sostituisce l'arma in dotazione
void Protagonista::cambiaArma(Arma a) {
  arma = a;
}

// sostituisce il potenziamento equipaggiato
void Protagonista::cambiaPotenziamento(Potenziamento p) {
  potenziamento = p;
}

// riduce la durata del potenziamento di uno
void Protagonista::riduciDurataPot() {
  potenziamento.riduciDurata();
}

// incrementa i punti
void Protagonista::aggiungiPunti(int p) {
  punti += p;
}

// sposta il protagonista a destra
// Precondition: quantità x di cui spostarlo
void Protagonista::muoviDx(int spost) {
  x += spost;
  versoDestra = true;
}

// sposta il protagonista a sinistra
// Precondition: quantità x di cui spostarlo
void Protagonista::muoviSx(int spost) {
  x -= spost;
  versoDestra = false;
}

// sposta il protagonista in alto
// Precondition: quantità y di cui spostarlo
void Protagonista::salta(int spost) {
  y -= spost;
}

// sposta il protagonista in basso
// Precondition: quantità y di cui spostarlo
void Protagonista::muoviGiu(int spost) {
  y += spost;
}

// riporta il protagonista nella posizione iniziale
void Protagonista::resetPosizione() {
  x = 3;
  y = 3;
}

// rigenera il protagonista dopo la morte
void Protagonista::rigenera() {
  vita = 100;
  punti = 0;
  resetPosizione();
}

// salva il protagonista sul suo file
void Protagonista::salva(GestoreFile &gf) {
  Stringa ts = nome;
  ts.concat(',');
  ts.concat(vita);
  ts.concat(',');
  ts.concat(denaro);
  ts.concat(',');
  ts.concat(arma.getNome());
  ts.concat(',');
  ts.concat(potenziamento.getNome());
  ts.concat(',');
  ts.concat(potenziamento.getDurata());
  ts.concat(',');
  ts.concat(punti);
  ts.concat(',');
  ts.concat(x);
  ts.concat(',');
  ts.concat(y);
  ts.concat(',');
  if (versoDestra) {
    ts.concat(1);
  } else {
    ts.concat(0);
  }
  gf.apriOutput(gf.getFileProtagonista());
  gf.scrivi(ts);
  gf.chiudiOutput();
}