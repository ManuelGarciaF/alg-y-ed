#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;

  int mayor = a > b ? a : b;

  cout << mayor << " es mayor." << endl;

  return 0;
}
