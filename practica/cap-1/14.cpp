#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  for (int i = a - 1; i > 1; i--) {
    if (a % i == 0) {
      cout << a << " no es primo ya que es divisible por " << i << endl;
      return 0;
    }
  }
  cout << a << " es primo." << endl;

  return 0;
}
