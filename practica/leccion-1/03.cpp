#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;

  int quinto = a / 5;

  int resto = a - (a / 5) * 5;

  int septimo = quinto / 7;

  cout << "1/5 a: " << quinto << endl;
  cout << "resto de a/5: " << resto << endl;
  cout << "1/7 de 1/5 a: " << septimo << endl;

  return 0;
}
