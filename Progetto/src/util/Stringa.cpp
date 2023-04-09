#include "Stringa.hpp"

// Postcondition: peso della cifra più significativa
int Stringa::pesoPiuSignificativo(int n) {
  // si assume ci sia almeno una cifra (anche se 0)
  int peso = 0;
  while (n > 9) {
    n /= 10;
    peso++;
  }
  return peso;
}

// trasforma un intero nella sua rappresentazione in char[]
// Precondition: intero da convertire, array in cui convertirlo
void Stringa::intToCharArray(int n, char c[]) {
  int div = pow(10, pesoPiuSignificativo(n));
  int i = 0;
  while (div > 0) {
    c[i] = n / div + 48;
    n = n % div;
    div /= 10;
    i++;
  }
  c[i] = '\0';
}

Stringa::Stringa() {
  strncpy(this->s, (char*) "", MAX_LENGTH);
}

Stringa::Stringa(char str[])  {
  strncpy(this->s, str, MAX_LENGTH);
}

// concatena una stringa al valore salvato
void Stringa::concat(Stringa str) {
  strncat(s, str.s, MAX_LENGTH - 1);
}

// concatena un carattere al valore salvato
void Stringa::concat(char c) {
  char ctmp[2] = {c, '\0'};
  strncat(s, ctmp, MAX_LENGTH - 1);
}

// concatena un intero al valore salvato
void Stringa::concat(int n) {
  char strN[16] = "";
  intToCharArray(n, strN);
  strncat(s, strN, MAX_LENGTH - 1);
}