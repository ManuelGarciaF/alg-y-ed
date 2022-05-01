#include <iostream>

using namespace std;

double factorial(int n);

int main() {
  int a;
  cin >> a;

  for (int i = 1; i <= a; ++i) {
    cout << factorial(i) << endl;
  }

  return 0;
}

double factorial(int n) {
  int sum = 1;
  for (int i = 1; i <= n; ++i) {
    sum *= i;
  }
  return sum;
}
