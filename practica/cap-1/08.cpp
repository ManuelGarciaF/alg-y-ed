#include <iostream>

using namespace std;

int main() {
  int fecha;
  cin >> fecha;

  // Fecha: aaaammdd
  //        20220408
  
  // Remover los ultimos 4 digitos.
  int a = fecha / 10000;

  // Remover los ultimos 2 digitos y tomar los primeros 2 del resultado.
  int m = (fecha / 100) % 100;

  // Tomar solo los ultimos 2 digitos.
  int d = fecha % 100;

  cout << "El año es: " << a << endl;
  cout << "El mes es: " << m << endl;
  cout << "El día es: " << d << endl;

  return 0;
}
