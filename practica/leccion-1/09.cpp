#include <iostream>

using namespace std;

int main() {
  int d, m, a;
  cout << "Ingresar la fecha en números." << endl;
  cout << "Día: ";
  cin >> d;
  cout << "Mes: ";
  cin >> m;
  cout << "Año: ";
  cin >> a;

  int f = d + 100*m + 10000*a;

  cout << f << endl;

  return 0;
}
