#include <iostream>

using namespace std;

void fechaDividir(int f, int &a, int &m, int &d);

int main() {
  int f;
  cin >> f;
  int a, m, d;
  fechaDividir(f, a, m, d);
  cout << a << " " << m << " " << d << endl;

  return 0;
}

void fechaDividir(int f, int &a, int &m, int &d) {
  a = f / 10000;
  m = (f / 100) % 100;
  d = f % 100;
}
