#include <iostream>
#include <stdlib.h>

using namespace std;

int diferencia_fechas(int a, int b);

int main() {
  cout << "Ingresar separadas por espacios, 2 fechas y la fecha actual en "
          "formato AAAAMMDD"
       << endl;
  int a, b, actual;
  cin >> a;
  cin >> b;
  cin >> actual;

  if (a == b) {
    cout << "Ambas fechas son iguales." << endl;
    return 0;
  }

  cout << diferencia_fechas(a, actual) << endl;
  cout << diferencia_fechas(b, actual) << endl;

  // Comparar la diferencia de cada fecha con la actual y determinar la más
  // cercana.
  int fecha_mas_cercana =
      (diferencia_fechas(a, actual) > diferencia_fechas(b, actual)) ? b : a;

  cout << fecha_mas_cercana << " es más cercano." << endl;

  return 0;
}

// Devuelve en formato AAAAMMDD la diferencia entre las fechas proveidas.
int diferencia_fechas(int a, int b) {

  // Separar ambas fechas en sus componentes.
  int anio_a = a / 10000;
  int mes_a = (a / 100) % 100;
  int dia_a = a % 100;

  int anio_b = b / 10000;
  int mes_b = (b / 100) % 100;
  int dia_b = b % 100;

  int anio_final = abs(anio_a - anio_b);
  int mes_final = abs(mes_a - mes_b);

  // Si uno de los años era bisiesto, se debe restar un día mas, o un día menos,
  // por lo que no se puede sacar el valor absoludo todavia.
  int dia_final = dia_a - dia_b;
  // Checkear si a es año bisiesto.
  if ((anio_a % 4 == 0 && anio_a % 100 != 0) || (anio_a % 400 == 0)) {
    dia_final += 1;
  }
  // Checkear si b es año bisiesto.
  if ((anio_b % 4 == 0 && anio_b % 100 != 0) || (anio_b % 400 == 0)) {
    dia_final -= 1;
  }
  dia_final = abs(dia_final);

  // Recomponer la fecha.
  return anio_final * 10000 + mes_final * 100 + dia_final;
}
