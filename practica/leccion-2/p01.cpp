#include <iostream>

using namespace std;

void datosPlan(char tipoAbono, double &precioPlan, int &minLibres,
               double &cargoExcedente);

int toMin(int t);
void excedente(double precio, int minLibres, double valorMinutoExcedente,
               int minutosUtilizados, int &minutosExcedidos,
               double &importeAAbonar);

int main() {
  int numCelular, tiempoUso;
  string nombreAbonado, direccionAbonado;
  char tipoAbono;
  for (int i = 0; i < 3; i++) {
    switch (i) {
    case 0:
      cout << "Turno: mañana" << endl;
      break;
    case 1:
      cout << "Turno: tarde" << endl;
      break;
    case 2:
      cout << "Turno: noche" << endl;
      break;
    }

    cout << "Abonado   Dirección      Min. Libres  Min. Exced.   Total a abonar"
         << endl;

    do {
      cin >> numCelular >> nombreAbonado >> direccionAbonado >> tiempoUso >>
          tipoAbono;

      int minLibres;
      double precioPlan, cargoExcedente;
      datosPlan(tipoAbono, precioPlan, minLibres, cargoExcedente);

      int minExcedidos;
      double aAbonar;
      excedente(precioPlan, minLibres, cargoExcedente, toMin(tiempoUso),
                minExcedidos, aAbonar);

      cout << nombreAbonado << "\t";
      cout << direccionAbonado << "\t";
      cout << minLibres << "\t";
      cout << minExcedidos << "\t";
      cout << aAbonar << "\t";

    } while (numCelular != 0);

    return 0;
  }
}

// t del formato HHHMM.
int toMin(int t) {
  int h = t / 100;
  int m = t % 100;
  return h * 60 + m;
}

void excedente(double precio, int minLibres, double valorMinutoExcedente,
               int minutosUtilizados, int &minutosExcedidos,
               double &importeAAbonar) {
  minutosExcedidos = minutosUtilizados - minLibres;
  importeAAbonar = precio + ((double)minutosExcedidos * valorMinutoExcedente);
}

void datosPlan(char tipoAbono, double &precioPlan, int &minLibres,
               double &cargoExcedente) {
  switch (tipoAbono) {
  case 'A':
    precioPlan = 1500;
    minLibres = 1000;
    cargoExcedente = 1;
    break;

  case 'B':
    precioPlan = 1000;
    minLibres = 600;
    cargoExcedente = 3;
    break;

  case 'C':
    precioPlan = 700;
    minLibres = 400;
    cargoExcedente = 5;
    break;

  case 'D':
    precioPlan = 500;
    minLibres = 300;
    cargoExcedente = 7;
    break;

  case 'E':
    precioPlan = 350;
    minLibres = 100;
    cargoExcedente = 10;
    break;
  }
}
