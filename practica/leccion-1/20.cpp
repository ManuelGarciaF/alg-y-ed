#include <iostream>

using namespace std;

int main() {
  int a;

  int pos = 0;     // Numeros positivos.
  int sumaPos = 0; // Suma de los numeros positivos.
  int neg = 0;     // Numeros negativos.
  int par = 0;     // Numeros pares.
  int tot = 0;     // Numeros totales.

  cin >> a;
  while (a != 0) {

    tot++;
    if (a > 0) {
      pos++;
      sumaPos += a;
    } else {
      neg++;
    }

    if (a % 2 == 0) {
      par++;
    }

    cin >> a;
  }

  // Se debe castear los valores a double para poder usar la division de numeros
  // flotantes.
  double porcentajePar = ((double)par / (double)tot);
  double promedioPos = (double)sumaPos / (double)pos;
  double porcentajeNeg = ((double)neg / (double)tot);

  cout << "Positivos: " << pos << endl;
  cout << "Negativos: " << neg << endl;
  cout << "Porcentaje de pares: " << porcentajePar << endl;
  cout << "Promedio de los numeros positivos: " << promedioPos << endl;
  cout << "Porcentaje de numeros negativos: " << porcentajeNeg << endl;
}
