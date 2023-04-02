#include "Negozio.hpp"

// costruttore
Negozio::Negozio() {}

// Postcondition: arma dalla posizione scelta
Arma Negozio::vendiArma(int position) {
  return armi[position];
}