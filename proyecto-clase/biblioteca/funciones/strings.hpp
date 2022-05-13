#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int length(string s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

int charCount(string s, char c) {
  int count = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      count++;
    }
  }
  return count;
}

string substring(string s, int d, int h) {
  string sub = "";
  int len = h - d;
  for (int i = 0; i < len; i++) {
    sub = sub + s[d + i];
  }
  return sub;
}

string substring(string s, int d) { return substring(s, d, length(s)); }

int indexOf(string s, char c, int offSet) {
  int i = offSet;
  while (s[i] != c) {
    // Si i es 1 más q el indice mas alto c no esta contenido.
    if (i == length(s)) {
      return -1;
    }
    i++;
  }
  return i;
}

int indexOf(string s, char c) { return indexOf(s, c, 0); }

int indexOf(string s, string toSearch, int offset) {
  // Iterar sobre s
  for (int i = 0; s[i] != '\0'; i++) {
    // Evitar error de indexación fuera de rango.
    if (i + length(toSearch) > length(s)) {
      return -1;
    }

    // Comparar el substring de s[i] hasta el largo de toSearch con toSearch
    if (substring(s, i, i + length(toSearch)) == toSearch) {
      return i;
    }
  }
  return -1;
}

int indexOf(string s, string toSearch) { return indexOf(s, toSearch, 0); }

int lastIndexOf(string s, char c) {
  int pos = -1;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      pos = i;
    }
  }
  return pos;
}

int indexOfN(string s, char c, int n) {
  int count = 1;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      if (count == n) {
        return i;
      } else {
        count++;
      }
    }
  }

  return -1;
}

int charToInt(char c) {
  // En caso de ser un numero
  if (c >= 48 && c <= 57) {
    return (int)c - 48;
  }
  // En caso de ser letra mayuscula
  else if (c >= 65 && c <= 90) {
    return (int)c - 55;
  }
  // En caso de ser letra minuscula
  else if (c >= 97 && c <= 122) {
    return (int)c - 87;
  }
  return -1;
}

char intToChar(int i) {
  // i esta entre 0-9 o 65-90
  // Caso que i sea numero
  if (i >= 0 && i <= 9) {
    return (char)(i + 48);

  }
  // Caso que i sea una letra
  else if (i >= 10 && i <= 35) {
    return (char)(i + 55);
  }
  return '\0';
}

int getDigit(int n, int i) {
  for (int j = 0; j < i; j++) {
    n = n / 10;
  }
  return n % 10;
}

int digitCount(int n) {
  int count = 1;
  while (n / 10 != 0) {
    n = n / 10;
    count++;
  }

  return count;
}

string intToString(int i) {
  string str;
  int digitos = digitCount(i);
  for (int j = 0; j < digitos; j++) {
    // Agregar el ultimo digito a la string al comienzo.
    str = intToChar(i % 10) + str;

    // Remover el ultimo digito de i.
    i = i / 10;
  }

  // Revertir la string obtenida.
  return str;
}

int stringToInt(string s, int b) {
  int sum = 0;
  int exponent = 0;
  for (int i = length(s) - 1; i >= 0; i--) {
    sum += pow(b, exponent) * charToInt(s[i]);
    exponent++;
  }
  return sum;
}

int stringToInt(string s) { return stringToInt(s, 10); }

string charToString(char c) {
  string s = "";
  s += c;
  return s;
}

char stringToChar(string s) { return s[0]; }

string stringToString(string s) { return s; }

string doubleToString(double d) {
  string s = "";

  int pEntera = (int)d;

  // Solo admite hasta 9 digitos luego de el punto.
  int pFraccionaria = (d - pEntera) * 1000000000;

  s += intToString(pEntera);
  s += ".";
  s += intToString(pFraccionaria);

  // Remover caracteres del final de la string hasta que el ultimo no sea 0.
  while (s[length(s) - 1] == '0') {
    s.pop_back();
  }

  return s;
}

double stringToDouble(string s) {
  double d = 0;

  int indexPunto = indexOf(s, '.');
  int pEntera = stringToInt(substring(s, 0, indexPunto));
  int pFraccionaria = stringToInt(substring(s, indexPunto + 1));

  d += pEntera;

  // Multiplicar la parte fraccionaria  por 10^-n, siendo n la cantidad de
  // digitos de pFraccionaria.
  d += (double)pFraccionaria * pow(10, -(digitCount(pFraccionaria)));

  return d;
}

bool isEmpty(string s) { return (s[0] == '\0'); }

bool startsWith(string s, string x) {
  return (substring(s, 0, length(x)) == x);
}

bool endsWith(string s, string x) {
  return substring(s, length(s) - length(x)) == x;
}

bool contains(string s, char c) {
  for (int i = 0; i < length(s); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

string replace(string s, char oldChar, char newChar) {
  while (contains(s, oldChar)) {
    s[indexOf(s, oldChar)] = newChar;
  }
  return s;
}

string insertAt(string s, int pos, char c) {
  string sFinal = "";
  sFinal += substring(s, 0, pos);
  sFinal += c;
  sFinal += substring(s, pos);
  return sFinal;
}

string removeAt(string s, int pos) {
  string sFinal = "";
  sFinal += substring(s, 0, pos);
  sFinal += substring(s, pos + 1);
  return sFinal;
}

string ltrim(string s) {
  while (s[0] == ' ') {
    // Remover el primer caracter.
    s = substring(s, 1);
  }
  return s;
}

string rtrim(string s) {
  while (s[length(s) - 1] == ' ') {
    // Remover el ultimo caracter.
    s = substring(s, 0, length(s) - 2);
  }
  return s;
}

string trim(string s) { return rtrim(ltrim(s)); }

string replicate(char c, int n) {
  string s = "";
  for (int i = 0; i < n; i++) {
    s += c;
  }
  return s;
}

string spaces(int n) { return replicate(' ', n); }

string lpad(string s, int n, char c) {
  int padLength = n - length(s);
  return replicate(c, padLength) + s;
}

string rpad(string s, int n, char c) {
  int padLength = n - length(s);
  return s + replicate(c, padLength);
}

string cpad(string s, int n, char c) {
  int padLength = (n - length(s)) / 2;
  return replicate(c, padLength) + s + replicate(c, padLength);
}

bool isDigit(char c) { return (charToInt(c) < 10 && charToInt(c) >= 0); }

bool isLetter(char c) { return charToInt(c) >= 10; }

bool isUpperCase(char c) { return ((int)c >= 65 && (int)c <= 90); }

bool isLowerCase(char c) { return (c >= 97 && c <= 122); }

char toUpperCase(char c) {
  if (!(isLetter(c) && isLowerCase(c))) {
    return c;
  }

  // Realizar la conversion segun la tabla ascii.
  return ((int)c - 32);
}

char toLowerCase(char c) {
  if (!(isLetter(c) && isUpperCase(c))) {
    return c;
  }

  // Realizar la conversion segun la tabla ascii.
  return ((int)c + 32);
}

string toUpperCase(string s) {
  for (int i = 0; i < length(s); i++) {
    s[i] = toUpperCase(s[i]);
  }
  return s;
}

string toLowerCase(string s) {
  for (int i = 0; i < length(s); i++) {
    s[i] = toLowerCase(s[i]);
  }
  return s;
}

int cmpString(string a, string b) {
  if (a > b) {
    return 1;
  }
  if (a < b) {
    return -1;
  }
  return 0;
}

int cmpDouble(double a, double b) {
  if (a > b) {
    return 1;
  }
  if (a < b) {
    return -1;
  }
  return 0;
}

#endif
