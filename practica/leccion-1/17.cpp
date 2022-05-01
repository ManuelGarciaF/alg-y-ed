#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  int desfaso = 0;
  for (int i = 0; i < a; i++) {
    // Agregar al desfaso si el actual seria multiplo de 3.
    // Se aplica un desfaso a i para poder "saltear" numeros que son multiplos
    // de 3.
    if (((i + desfaso) * 5) % 3 == 0) {
      desfaso++;
    }

    cout << (i + desfaso) * 5 << " ";
  }
  cout << endl;

  return 0;
}
