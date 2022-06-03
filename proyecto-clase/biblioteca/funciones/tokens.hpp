#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include "strings.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

int tokenCount(string s, char sep) {
  int count = 0;

  if (length(s) > 0) {
    count++;
  }

  for (int i = 0; i < length(s); i++) {
    if (s[i] == sep) {
      count++;
    }
  }
  return count;
}

void addToken(string &s, char sep, string t) {
  if (!(length(s) == 0)) {
    s += sep;
  }
  s += t;
}

string getTokenAt(string s, char sep, int i) {
  for (int j = 0; j < i; j++) {
    // Remover el primer item del token.
    s = substring(s, indexOf(s, sep) + 1, length(s));
  }

  // Si es el ultimo elemento entonces es simplemente la cadena restante.
  if (indexOf(s, sep) < 0) {
    return s;
  }
  return substring(s, 0, indexOf(s, sep));
}

// Esta es la manera menos eficiente posible, pero la mas facil.
void removeTokenAt(string &s, char sep, int i) {
  string original = s;

  // Volver a armar la cadena.
  s = "";
  for (int j = 0; j < tokenCount(original, sep); j++) {
    // Saltear el elemento a remover.
    if (j == i) {
      continue;
    }

    // Agregar cada token a la cadena nueva.
    addToken(s, sep, getTokenAt(original, sep, j));
  }
}

void setTokenAt(string &s, char sep, string t, int i) {
  string original = s;

  // Volver a armar la cadena.
  s = "";
  for (int j = 0; j < tokenCount(original, sep); j++) {
    // Cambiar el token.
    if (j == i) {
      addToken(s, sep, t);
      continue;
    }

    // Agregar cada token a la cadena nueva.
    addToken(s, sep, getTokenAt(original, sep, j));
  }
}

int findToken(string s, char sep, string t) {
  // Iterar sobre cada token
  for (int i = 0; i < tokenCount(s, sep); i++) {
    // Si el token es el correcto, devolver su posicion.
    if (getTokenAt(s, sep, i) == t) {
      return i;
    }
  }
  // Si no se encontro.
  return -1;
}

#endif
