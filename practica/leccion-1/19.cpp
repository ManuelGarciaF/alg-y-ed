#include <iostream>

using namespace std;

int main() {
  int v;

  int doce = 0;         // Valores menores o iguales a 12.
  int veinticuatro = 0; // Valores mayores a 12 y menores o iguales a 24.
  int treintaYSeis = 0; // Valores mayores a 24 y menores o iguales a 36.
  int cero = 0;         // Valores iguales a 0.

  while (v >= 0) {
    cin >> v;

    if (v == 0) {
      cero++;
      continue;
    }

    if (v <= 12) {
      doce++;
      continue;
    }

    if (v <= 24) {
      veinticuatro++;
      continue;
    }

    if (v <= 36) {
      treintaYSeis++;
      continue;
    }
  }

  cout << "(v <= 12):" << doce << endl;
  cout << "(12 < v <= 24):" << veinticuatro << endl;
  cout << "(24 < v <= 36):" << treintaYSeis << endl;
  cout << "(v == 0):" << cero << endl;

  return 0;
}
