#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;

  if ( a == b && a == c ) {
    cout << "equilatero" << endl;
  } else if ( a == b || b == c ) {
    cout << "isosceles" << endl;
  } else {
    cout << "escaleno" << endl;
  }

  return 0;
}
