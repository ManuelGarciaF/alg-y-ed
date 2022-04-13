#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  if (a != 0) {
    cout << a << " / " << b << " = " << a / b << endl;
  }
}
