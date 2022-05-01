#include <iostream>

using namespace std;

int main() {
  int a;

  int sumaMayor = 0; // Suma de los mayores de 100.
  int mayores = 0;   // Cantidad de numeros mayores de 100.

  int sumaMenor = 0; // Suma de los menores de -10.
  int menores = 0;   // Cantidad de numeros menores de -10.

  for (int i = 0; i < 10; i++) {
    cin >> a;
    if (a > 100) {
      mayores++;
      sumaMayor += a;
    }
    if (a < -10) {
      menores++;
      sumaMenor += a;
    }
  }

  double promedioMayores = (double)sumaMayor / (double)mayores;
  double promedioMenores = (double)sumaMenor / (double)menores;

  cout << "Promedio de los mayores: " << promedioMayores << endl;
  cout << "Promedio de los menores: " << promedioMenores << endl;

  return 0;
}
