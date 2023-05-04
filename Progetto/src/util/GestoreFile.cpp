#include "GestoreFile.hpp"

// costruttore
GestoreFile::GestoreFile() {
  this->fileProtagonista = Stringa((char*) "../../db/protagonista.txt");
  this->filePartita = Stringa((char*) "../../db/partita.txt");
}

// GETTERS

Stringa GestoreFile::getFileProtagonista() {
  return fileProtagonista;
}

Stringa GestoreFile::getFilePartita() {
  return filePartita;
}

// apre il file di input
void GestoreFile::apriInput(Stringa path) {
  in.open(path.s);
}

// apre il file di output
void GestoreFile::apriOutput(Stringa path) {
  out.open(path.s);
}

// chiude il file di input aperto
void GestoreFile::chiudiInput() {
  in.close();
}

// chiude il file di output aperto
void GestoreFile::chiudiOutput() {
  out.close();
}

// legge una parola (sequenza di caratteri fino ad una virgola
// o all fine del file)
// Postcondition: parola letta
Stringa GestoreFile::leggiParola() {
  Stringa lettura = Stringa((char*) "");
  char c;
  do {
    in.get(c);
    if (c != ',' && !in.eof()) {
      lettura.concat(c);
    } else {
      lettura.concat('\0');
    }
  } while (c != ',' && !in.eof());
  return lettura;
}

// scrive una stringa sul file aperto
void GestoreFile::scrivi(Stringa str) {
  out<<str.s;
}
