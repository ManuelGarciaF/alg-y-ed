#include "principal.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/Array.hpp"
#include "../../biblioteca/tads/Coll.hpp"
#include "../../biblioteca/tads/List.hpp"
#include "../../biblioteca/tads/Map.hpp"
#include "../../biblioteca/tads/Queue.hpp"
#include "../../biblioteca/tads/Stack.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

#define ARCHIVO_GASTOS "./GASTOS.dat"
#define ARCHIVO_CONSORCIOS "./CONSORCIOS.dat"

int main() {
  Coll<Gasto> listaGastos = cargarGastos();
  Coll<Consorcio> listaConsorcios = cargarConsorcios();

  // Iterar sobre cada consorcio.
  collReset(listaGastos);
  while (collHasNext(listaConsorcios)) {
    Consorcio c = collNext<Consorcio>(listaConsorcios, consorcioFromString);
    int nroDeptos = c.cantPisos * c.dtosPorPiso;

    double gastosTotales = 0;

    Coll<Depto> listaDeptos = coll<Depto>();
    // Generar la lista de deptos del consorcio.
    for (int i = 1; i <= nroDeptos; i++) {
      double metros = mtsPorcencuales(c.idCons, i);
      collAdd<Depto>(listaDeptos, depto(c.idCons, i, metros, 0), deptoToString);
    }

    // Iterar sobre cada gasto y agregar aquellos que correspondan al consorcio
    // actual.
    collReset(listaGastos);
    while (collHasNext(listaGastos)) {
      Gasto g = collNext<Gasto>(listaGastos, gastoFromString);
      // Si el gasto no corresponde al consorcio actual, ignorarlo.
      if (g.idCons != c.idCons) {
        continue;
      }

      gastosTotales += g.importe;

      // Actualizar el total a pagar de cada depto.
      for (int i = 0; i < collSize<Depto>(listaDeptos); i++) {
        Depto d = collGetAt<Depto>(listaDeptos, i, deptoFromString);

        // Calcular el gasto que le corresponde al departamento.
        d.gastoAcumulado += (g.importe / c.cantPisos) * d.mtsPorcentaje;

        collSetAt<Depto>(listaDeptos, d, i, deptoToString);
      }

      imprimirDatos(listaDeptos, c, gastosTotales);
    }
  }

  return 0;
}

void imprimirDatos(Coll<Depto> listaDeptos, Consorcio consorcio,
                   int gastosTotales) {
  // Organizar la lista por metros porcentuales.
  collSort<Depto>(listaDeptos, cmpDeptoMts, deptoFromString, deptoToString);

  cout << "Consorcio Calle: " << consorcio.direccion << "  ";
  cout << "Gastos totales: $" << gastosTotales << endl;

  cout << "Depto.\t\tMts.2.\t\tTotal a pagar ($)" << endl;

  while (collHasNext(listaDeptos)) {
    Depto d = collNext<Depto>(listaDeptos, deptoFromString);
    cout << d.idDepto << "\t\t" << (d.mtsPorcentaje * 100) << "%\t\t"
         << d.gastoAcumulado << endl;
  }
};

Coll<Gasto> cargarGastos() {
  Coll<Gasto> c = coll<Gasto>();
  FILE *f = fopen(ARCHIVO_GASTOS, "rb");

  while (!feof(f)) {
    Gasto g = read<Gasto>(f);
    collAdd<Gasto>(c, g, gastoToString);
  }

  fclose(f);
  return c;
};

Coll<Consorcio> cargarConsorcios() {
  Coll<Consorcio> c = coll<Consorcio>();
  FILE *f = fopen(ARCHIVO_CONSORCIOS, "rb");

  while (!feof(f)) {
    Consorcio g = read<Consorcio>(f);
    collAdd<Consorcio>(c, g, consorcioToString);
  }

  fclose(f);
  return c;
}
