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
    // Comparar el substring de s[i] hasta el largo de toSearch con toSearch
    if (substring(s, s[i], length(toSearch)) == toSearch) {
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

// TODO: Ultimo realizado
int stringToInt(string s, int b) {
  int sum = 0;
  for (int i = length(s); i > 0; i--) {
    /* sum += pow() */
  }
  return 0;
}

int stringToInt(string s) { return 0; }

string charToString(char c) { return ""; }

char stringToChar(string s) { return 'X'; }

string stringToString(string s) { return ""; }

string doubleToString(double d) { return ""; }

double stringToDouble(string s) { return 1.1; }

bool isEmpty(string s) { return true; }

bool startsWith(string s, string x) { return true; }

bool endsWith(string s, string x) { return true; }

bool contains(string s, char c) { return true; }

string replace(string s, char oldChar, char newChar) { return ""; }

string insertAt(string s, int pos, char c) { return ""; }

string removeAt(string s, int pos) { return ""; }

string ltrim(string s) { return ""; }

string rtrim(string s) { return ""; }

string trim(string s) { return ""; }

string replicate(char c, int n) { return ""; }

string spaces(int n) { return ""; }

string lpad(string s, int n, char c) { return ""; }

string rpad(string s, int n, char c) { return ""; }

string cpad(string s, int n, char c) { return ""; }

bool isDigit(char c) { return true; }

bool isLetter(char c) { return true; }

bool isUpperCase(char c) { return true; }

bool isLowerCase(char c) { return true; }

char toUpperCase(char c) { return 'X'; }

char toLowerCase(char c) { return 'X'; }

string toUpperCase(string s) { return ""; }

string toLowerCase(string s) { return ""; }

int cmpString(string a, string b) { return 0; }

int cmpDouble(double a, double b) { return 0; }

#endif
