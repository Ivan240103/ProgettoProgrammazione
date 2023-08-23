#include "Potenziamento.hpp"

// costruttore default
Potenziamento::Potenziamento() {}

// costruttore
Potenziamento::Potenziamento(Stringa nome, int costo, int durata) {
  this->nome = nome;
  this->costo = costo;
  this->durata = durata;
}

// GETTERS

Stringa Potenziamento::getNome(){
  return nome;
}

int Potenziamento::getCosto(){
  return costo;
}

int Potenziamento::getDurata(){
  return durata;
}

// consuma il potenziamento
// Postcondition: diminuisce la durata di 1
void Potenziamento::riduciDurata() {
  if (durata > 0) {
    durata--;
  }
}