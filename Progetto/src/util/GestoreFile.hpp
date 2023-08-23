/*
 Classe per gestire l'accesso ai file in lettura/scrittura
*/

#ifndef GESTOREFILE_HPP
#define GESTOREFILE_HPP

#include <fstream>
using namespace std;
#include "Stringa.hpp"

class GestoreFile {

  protected:
    // stream di input
    ifstream in;
    // stream di output
    ofstream out;
    // percorsi dei file di memoria
    Stringa fileProtagonista, filePartita;
  
  public:
    GestoreFile();

    Stringa getFileProtagonista();

    Stringa getFilePartita();

    void apriInput(Stringa path);

    void apriOutput(Stringa path, bool app = false);

    void chiudiInput();

    void chiudiOutput();

    Stringa leggiParola();

    void scrivi(Stringa str);
};

#endif