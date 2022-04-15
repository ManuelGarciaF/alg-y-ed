#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  int anterior = 0;
  int actual = 1;
  int temp;

  for (int i = 0; i < a; i++) {
    cout << actual << " ";

    // Guardar el valor previo a la suma.
    temp = actual;

    // Sumar el numero anterior al actual.
    actual += anterior;

    // Actualizar el número anterior.
    anterior = temp;
  }
  cout << endl;

  return 0;
}
