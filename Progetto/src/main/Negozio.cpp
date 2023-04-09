#include "Negozio.hpp"

// costruttore
Negozio::Negozio() {}

// Postcondition: arma dalla posizione scelta
Arma Negozio::vendiArma(int position) {
  return armi[position];
}

// Postcondition: elenco delle armi nel negozio
Stringa Negozio::mostraArticoli() {
  Stringa elenco = Stringa();
  for (int i = 0; i < NUM_ARMI; i++) {
    elenco.concat(i);
    elenco.concat(Stringa((char*) ") "));
    elenco.concat(armi[i].toString());
  }
  return elenco;
}