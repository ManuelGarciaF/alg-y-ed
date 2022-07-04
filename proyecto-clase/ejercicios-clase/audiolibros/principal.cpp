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

#define ARCHIVO_REPROD "./reproducciones.dat"
#define ARCHIVO_LIBROS "./libros.dat"
#define ARCHIVO_RELAT "./relatores.dat"

using namespace std;

Coll<RLibro> subirLibros() {
  FILE *f = fopen(ARCHIVO_LIBROS, "rb");

  Coll<RLibro> cLi = coll<RLibro>();

  while (!feof(f)) {
    RLibro l = read<RLibro>(f);
    collAdd(cLi, l, rLibroToString);
  }

  fclose(f);
  return cLi;
}

Coll<RRelator> subirRelatores() {
  FILE *f = fopen(ARCHIVO_RELAT, "rb");

  Coll<RRelator> cRe = coll<RRelator>();

  while (!feof(f)) {
    RRelator l = read<RRelator>(f);
    collAdd(cRe, l, rRelatorToString);
  }

  fclose(f);
  return cRe;
}

void proceso(Coll<RLibro> &cLi, int idLibro, int contMin, Coll<RRelator> &cRe) {
  int indexLibroLeido =
      collFind<RLibro>(cLi, idLibro, cmpRLibroId, rLibroFromString);
  RLibro libroLeido = collGetAt<RLibro>(cLi, indexLibroLeido, rLibroFromString);

  // Actualizar el contador correcto segun el porcenaje escuchado.
  double porcentajeEscuchado =
      ((double)contMin / (double)libroLeido.libro.duracion) * 100;
  if (porcentajeEscuchado >= 100) {
    libroLeido.c100++;
  } else if (porcentajeEscuchado > 75) {
    libroLeido.c75++;
  } else if (porcentajeEscuchado > 50) {
    libroLeido.c50++;
  } else if (porcentajeEscuchado > 25) {
    libroLeido.c25++;
  } else {
    libroLeido.c1++;
  }
  // Volver a ingresar a la colección el objeto actualizado.
  collSetAt<RLibro>(cLi, libroLeido, indexLibroLeido, rLibroToString);

  // Aumentar el contador de autores en reproducciones de mas del 75% de libro.
  if (porcentajeEscuchado > 75) {
    int indexRelatorLibroLeido = collFind<RRelator>(
        cRe, libroLeido.libro.idRelator, cmpRRelatorId, rRelatorFromString);
    RRelator relatorLibroLeido =
        collGetAt<RRelator>(cRe, indexRelatorLibroLeido, rRelatorFromString);

    relatorLibroLeido.cont++;

    collSetAt<RRelator>(cRe, relatorLibroLeido, indexRelatorLibroLeido,
                        rRelatorToString);
  }
}

void muestroPto1(Coll<RLibro> cLi) {
  while (collHasNext<RLibro>(cLi)) {
    RLibro l = collNext<RLibro>(cLi, rLibroFromString);
    cout << l.libro.titulo << ":" << endl;
    cout << "\t100%:" << l.c100 << endl;
    cout << "\t75%+:" << l.c75 << endl;
    cout << "\t50%+:" << l.c50 << endl;
    cout << "\t25%+:" << l.c25 << endl;
    cout << "\t<25%:" << l.c1 << endl;
  }
}

void muestroPto2(Coll<RRelator> cRe) {
  collSort<RRelator>(cRe, cmpRRelatorReproducciones, rRelatorFromString,
                     rRelatorToString);

  int i = 1;
  while (collHasNext<RRelator>(cRe)) {
    RRelator r = collNext<RRelator>(cRe, rRelatorFromString);
    cout << i << ")" << r.relator.nombre << endl;
  }
}

int main() {
  // subo archivos a memoria
  Coll<RLibro> cLi = subirLibros();
  Coll<RRelator> cRe = subirRelatores();

  // recorro con doble corte de control
  FILE *f = fopen(ARCHIVO_REPROD, "rb");

  Reproduccion r = read<Reproduccion>(f);
  while (!feof(f)) {
    int idUsuarioAnt = r.idUsuario;
    while (!feof(f) && r.idUsuario == idUsuarioAnt) {
      // inicializo el contador de minutos libro/usuario
      int contMin = 0;

      int idLibroAnt = r.idLibro;
      while (r.idUsuario == idUsuarioAnt && r.idLibro == idLibroAnt) {
        // acumulo minutos
        contMin += r.minutos;

        r = read<Reproduccion>(f);
      }

      // proceso ptos 1 y 2
      proceso(cLi, idLibroAnt, contMin, cRe);
    }
  }

  // resultados
  muestroPto1(cLi);
  muestroPto2(cRe);

  fclose(f);
  return 0;
}
