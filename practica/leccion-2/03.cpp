#include <iostream>

using namespace std;

bool fechaEsAnioBisiesto(int a);
int fechaDiasMes(int m, int a);

int main() {
  int a, m;
  cout << "Ingresar un año y un mes en formato AAAA MM:" << endl;
  cin >> a >> m;
  cout << fechaDiasMes(m, a) << endl;
  return 0;
}

bool fechaEsAnioBisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

int fechaDiasMes(int m, int a) {
  switch (m) {
  case 1:
    return 31;
  case 2:
    if (fechaEsAnioBisiesto(a)) {
      return 29;
    } else {
      return 28;
    }
  case 3:
    return 31;
  case 4:
    return 30;
  case 5:
    return 31;
  case 6:
    return 30;
  case 7:
    return 31;
  case 8:
    return 31;
  case 9:
    return 30;
  case 10:
    return 31;
  case 11:
    return 30;
  case 12:
    return 31;
  default:
    return -1;
  }
}
