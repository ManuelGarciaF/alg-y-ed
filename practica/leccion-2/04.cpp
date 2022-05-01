#include <iostream>

using namespace std;

int fechaUnificar(int a, int m, int d);

int main() {
  int a, m, d;
  cin >> a >> m >> d;
  cout << fechaUnificar(a, m, d) << endl;

  return 0;
}

int fechaUnificar(int a, int m, int d) { return a * 10000 + m * 100 + d; }
