#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  int actual;
  for (int i = 1; i <= a; i++) {
    actual = 1;

    // Realizar el factorial de i.
    for (int j = i; j > 1; j--) {
      actual = actual * j;
    }
    cout << actual << " ";
  }
  cout << endl;

  return 0;
}
