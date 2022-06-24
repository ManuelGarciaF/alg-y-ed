#include <iostream>

#include "../../../proyecto-clase/biblioteca/funciones/files.hpp"
#include "../../../proyecto-clase/biblioteca/funciones/strings.hpp"
#include "../../../proyecto-clase/biblioteca/tads/Coll.hpp"

using namespace std;

struct Producto {
  int idProd;
  char descr[20];
  double precio;
  int idRub;
};

struct RProducto {
  Producto p;
  int total;
};

struct Rubro {
  int idRub;
  char descr[20];
  double promo; // Valor por el que multiplicar el valor, p.ej. 10% de descuento
                // = 0.9
};

struct ElemTicket {
  int idProd;
  string descr;
  double precio;
  double precioDto;
  int cant;
  double total;
};

struct Ahorro {
  int idRub;
  string descr;
  double descuento;
};

int main() {
  int idCli, idProd, cant;

  cin >> idCli;

  while (idCli != 0) {

    cin >> idProd >> cant;

    while (idProd != 0) {
      cin >> idProd >> cant;
    }
    cin >> idCli;
  }

  return 0;
}
