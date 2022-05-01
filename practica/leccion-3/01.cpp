#include <iostream>

struct Fraccion {
  double numerador;
  double denominador;
};

Fraccion fraccion(double numerador, double denominador) {
  return {numerador, denominador};
}

std::string fraccionToString(Fraccion f) {
  return std::to_string(f.numerador) + " / " + std::to_string(f.denominador);
}

double fraccionToDouble(Fraccion f) { return f.numerador / f.denominador; }

int main() {
  Fraccion f1 = fraccion(2, 3);
  std::cout << fraccionToString(f1) << std::endl;
  std::cout << fraccionToDouble(f1) << std::endl;
  return 0;
}
