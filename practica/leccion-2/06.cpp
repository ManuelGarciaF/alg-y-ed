#include <iostream>

using namespace std;

int today();

int main() {
  cout << today() << endl;
  return 0;
}

void getDate(int &dia, int &mes, int &anio) {
  time_t timestamp;
  time(&timestamp);
  struct tm *fechaActual = localtime(&timestamp);
  dia = fechaActual->tm_mday;
  mes = fechaActual->tm_mon + 1;
  anio = fechaActual->tm_year + 1900;
}

int today() {
  int d, m, a;
  getDate(d, m, a);
  return a * 10000 + m * 100 + d;
}
