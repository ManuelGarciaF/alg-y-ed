#ifndef _MAIN
#define _MAIN

#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Stack.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  // Hola :)
  string s = "Esto es una prueba";
  int p = indexOf(s, "una");
  cout << p << endl; // muestra: 8
  p = indexOf(s, "jamon");
  cout << p << endl; // muestra: algun valor negativo
  return 0;
}

#endif
