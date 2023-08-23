/*
 Classe per gestire le stringhe come array di char
*/

#ifndef STRINGA_HPP
#define STRINGA_HPP

#include <cstring>
#include <cmath>

const int MAX_LENGTH = 100;

class Stringa {

  protected:
    int pesoPiuSignificativo(int n);

    void intToCharArray(int n, char c[]);
  
  public:
    // stringa memorizzata
    char s[MAX_LENGTH];

    Stringa();
    
    Stringa(char str[]);

    void concat(Stringa s);

    void concat(char c);

    void concat(int n);

    int compareTo(Stringa cmp);

    int toInt();
};

#endif