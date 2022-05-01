#include <iostream>

using namespace std;

bool esPrimo(int n);

int main() {
  int a = 0;
  cin >> a;

  int actual = 1;
  int totales = 0; // Numeros primos impresos.
  while (totales < a) {
    if (esPrimo(actual)) {
      cout << actual << " ";
      totales++;
    }
    actual++;
  }
  cout << endl;

  return 0;
}

bool esPrimo(int n) {
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
