#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;

  if (b == 0) {
    cout << "E: No se puede dividir por 0." << endl;
    return 1;
  }

  cout << a << "/" << b << " = " << a / b << endl;

  return 0;
}
