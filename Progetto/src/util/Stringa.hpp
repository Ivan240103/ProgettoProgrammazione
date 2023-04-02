/*
 Classe per gestire le stringhe come array di char
*/

#ifndef STRINGA_HPP
#define STRINGA_HPP

#include <cstring>

const int MAX_LENGTH = 200;

class Stringa {
  
  public:
    char s[MAX_LENGTH];

    Stringa();
    
    Stringa(char str[]);
};

#endif