#include <iostream>

using namespace std;

int main() {
  int n;

  int mayor = 0;
  for (int i = 0; i < 100; i++) {
    do {
      cin >> n;
    } while (n <= 0);

    // Volver a n el mayor si es mayor que el actual.
    mayor = (n > mayor) ? n : mayor;
  }

  cout << mayor << endl;

  return 0;
}
