#include "Potenziamento.hpp"

// costruttore
Potenziamento::Potenziamento(Stringa nome, int costo, int durata) {
  this->nome = nome;
  this->costo = costo;
  this->durata = durata;
}

//Metodo che restituisce il nome del potenziamento
Stringa Potenziamento::getNome(){
  return nome;
}

//Metodo che restituisce il costo
int Potenziamento::getCosto(){
  return costo;
}

//Metodo che restisuisce la durata
int Potenziamento::getDurata(){
  return durata;
}