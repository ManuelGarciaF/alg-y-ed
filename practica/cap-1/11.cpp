
#include <iostream>

using namespace std;

int main() {
  int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  cout << "Ingresar el numero correspondiente a un mes y a un año"
       << "separados por espacios:" << endl;
  int mes, anio;
  cin >> mes >> anio;

  if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
    dias[1] += 1;
  }

  cout << "Hay " << dias[mes - 1] << " días en ese mes" << endl;
}
