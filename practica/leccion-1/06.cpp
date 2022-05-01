#include <iostream>

using namespace std;

int menor(int a, int b, int c);
int medio(int a, int b, int c);
int mayor(int a, int b, int c);

int main() {
  int a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;

  cout << "el menor es: " << menor(a, b, c) << endl;
  cout << "el del medio es: " << medio(a, b, c) << endl;
  cout << "el menor es: " << mayor(a, b, c) << endl;

}

int menor(int a, int b, int c) {
  if ( a < b && a < c ) {
    return a;
  }
  if ( b < c ) {
    return b;
  }
  return c;
}

int medio(int a, int b, int c) {
  if ( (a < b && a > c) || (a > b && a < c)) {
    return a;
  }
  if ( (b < a && b > c) || (b > a && b < c) ) {
    return b;
  }
  return c;
}

int mayor(int a, int b, int c) {
  if ( a > b && a > c ) {
    return a;
  }
  if ( b > c ) {
    return b;
  }
  return c;
}
