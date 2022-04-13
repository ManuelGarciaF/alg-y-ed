#include <iostream>
#include <vector>

using namespace std;

int main() {
  long unsigned int a;
  cin >> a;

  vector<int> primos;

  int actual = 1;
  bool primo;

  // Repetir hasta llenar la lista.
  while (primos.size() < a) {
    // Asumir que el numero puede ser primo
    primo = true;

    // Iterar sobre todos los valores por los que el num actual puede ser
    // divisible.
    for (int i = actual; i > 1; i--) {

      // Si es divisible, y no es si mismo, marcar que no es primo.
      if (actual % i == 0 && actual != i) {
        primo = false;
        break;
      }
    }

    if (primo) {
      primos.push_back(actual);
    }

    actual++;
  }

  cout << "Primos: ";
  for (long unsigned int i = 0; i < primos.size(); i++) {
    cout << primos[i] << " ";
  }
  cout << endl;

  return 0;
}
