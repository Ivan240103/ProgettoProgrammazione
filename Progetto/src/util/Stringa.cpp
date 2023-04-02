#include "Stringa.hpp"

Stringa::Stringa() {}

Stringa::Stringa(char str[])  {
  strncpy(this->s, str, MAX_LENGTH);
}