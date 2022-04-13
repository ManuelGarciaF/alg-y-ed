#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;

  if (a > b) {
    cout << a << " Es mayor" << endl;
  } else if (a < b) {
    cout << b << " Es mayor" << endl;
  } else {
    cout << "Son iguales" << endl;
  }

  return 0;
}
