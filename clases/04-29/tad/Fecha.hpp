#include <iostream>
struct Fecha {
  int dia;
  int mes;
  int anio;
};

Fecha fecha(int d, int m, int a);

std::string fechaToString(Fecha f);
