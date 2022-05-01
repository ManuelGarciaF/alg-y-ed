#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  long total = 1;
  for (int i = 1; i <= a; i++) {
    total = total * i;
  }

  cout << a << "! = " << total << endl;

  return 0;
}
