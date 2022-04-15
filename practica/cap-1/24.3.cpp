#include <iostream>

using namespace std;

int main() {
  int n;

  int menor = 0;
  for (int i = 0; i < 100; i++) {
    cin >> n;

    // Volver a n el mayor si es mayor que el actual.
    menor = (n < menor) ? n : menor;
  }

  cout << menor << endl;

  return 0;
}
