#include "Fecha.hpp"

Fecha fecha(int d, int m, int a) { return {d, m, a}; }

std::string fechaToString(Fecha f) {
  return std::to_string(f.dia) + "/" + std::to_string(f.mes) + "/" +
         std::to_string(f.anio);
}
