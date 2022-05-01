#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int total = 0;
  if (a >= 0) {
    for (int i = 0; i < a; i++) {
      total += b;
    }
  } else {
    for (int i = 0; i < -a; i++) {
      total -= b;
    }
  }

  cout << a << "*" << b << " = " << total << endl;
  return 0;
}
