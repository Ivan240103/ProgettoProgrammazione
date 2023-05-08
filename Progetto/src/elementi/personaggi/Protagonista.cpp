#include "Protagonista.hpp"

// costruttore
Protagonista::Protagonista() {
  this->gf = GestoreFile();
  gf.apriInput(gf.getFileProtagonista());

  this->nome = gf.leggiParola();
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
  this->punti = gf.leggiParola().toInt();
  this->versoDestra = gf.leggiParola().toInt();

  gf.chiudiInput();
}

// GETTERS

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

int Protagonista::getPunti() {
  return punti;
}

bool Protagonista::isVersoDestra() {
  return versoDestra;
}

// Postcondition: difficoltà del livello iniziale in base alle condizioni
int Protagonista::getDifficolta() {
  return arma.getCoeff() + vita % 10;
}

// riduce la vita al protagonista
// Postcondition: true se è ancora vivo, false se è morto
bool Protagonista::prendiDanno(int danno) {
  vita -= danno;
  if (vita <= 0) {
    vita = 0;
    return false;
  } else {
    return true;
  }
}

// decrementa il denaro
// Postcondition: danno causabile dal protagonista
int Protagonista::infliggiDanno() {
  return arma.getDanno();
}

// incrementa il denaro
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

// sostituisce l'arma in dotazione
void Protagonista::cambiaArma(Arma a) {
  arma = a;
}

// incrementa i punti
void Protagonista::aggiungiPunti(int p) {
  punti += p;
}

// rigenera il protagonista dopo la morte
void Protagonista::rigenera() {
  vita = 100;
  punti = 0;
}

// Postcondition: descrizione del protagonista
Stringa Protagonista::toString() {
  Stringa tr = nome;
  tr.concat(Stringa((char*) " - Vita: "));
  tr.concat(vita);
  tr.concat(Stringa((char*) ", Denaro: "));
  tr.concat(denaro);
  tr.concat(Stringa((char*) ", Arma: "));
  tr.concat(arma.getNome());
  tr.concat(Stringa((char*) ", Punti: "));
  tr.concat(punti);
  if (versoDestra) {
    tr.concat(Stringa((char*) ", VersoDestra: true\n"));
  } else {
    tr.concat(Stringa((char*) ", VersoDestra: false\n"));
  }
  return tr;
}

// salva il protagonista su file
void Protagonista::salva() {
  Stringa ts = nome;
  ts.concat(',');
  ts.concat(vita);
  ts.concat(',');
  ts.concat(denaro);
  ts.concat(',');
  ts.concat(arma.getNome());
  ts.concat(',');
  ts.concat(punti);
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