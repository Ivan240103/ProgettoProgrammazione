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

// costruttore default
Stringa::Stringa() {
  strncpy(this->s, (char*) "", MAX_LENGTH);
}

// costruttore
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
  char strN[10] = "";
  intToCharArray(n, strN);
  strncat(s, strN, MAX_LENGTH - 1);
}

// compara due stringhe
int Stringa::compareTo(Stringa cmp) {
  return strncmp(s, cmp.s, MAX_LENGTH);
}

// Postcondition: valore intero della stringa
int Stringa::toInt() {
  // si assume che una singola cifra ci sia sempre (anche solo 0)
  int m = -1, n = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    m++;
  }
  m = pow(10, m);
  for (int i = 0; s[i] != '\0'; i++) {
    n = n + (s[i] - 48) * m;
    m /= 10;
  }
  return n;
}