#ifndef _MAINHPP
#define _MAINHPP
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/Coll.hpp"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

struct Gasto {
  int idCons;
  int fecha;
  double importe;
  char categoria[20];
};

struct Consorcio {
  int idCons;
  char direccion[50];
  int cantPisos;
  int dtosPorPiso;
};

struct Depto {
  int idCons;
  int idDepto;
  double mtsPorcentaje;
  double gastoAcumulado;
};

// Función magica.
double mtsPorcencuales(int idCons, int depto);

string gastoToString(Gasto x) {
  char sep = 1;
  string sIdCons = to_string(x.idCons);
  string sFecha = to_string(x.fecha);
  string sImporte = to_string(x.importe);
  string sCategoria = x.categoria;
  return sIdCons + sep + sFecha + sep + sImporte + sep + sCategoria;
}

Gasto gastoFromString(string s) {
  char sep = 1;
  Gasto x;
  string t0 = getTokenAt(s, sep, 0);
  x.idCons = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.fecha = stoi(t1);
  string t2 = getTokenAt(s, sep, 2);
  x.importe = stod(t2);
  string t3 = getTokenAt(s, sep, 3);
  strcpy(x.categoria, t3.c_str());
  return x;
}

string gastoToDebug(Gasto x) {
  stringstream sout;
  sout << "[";
  sout << x.idCons;
  sout << ",";
  sout << x.fecha;
  sout << ",";
  sout << x.importe;
  sout << ",";
  sout << x.categoria;
  sout << "]";
  return sout.str();
}

string gastoToDebug(string mssg, Gasto x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idCons;
  sout << ",";
  sout << x.fecha;
  sout << ",";
  sout << x.importe;
  sout << ",";
  sout << x.categoria;
  sout << "]";
  return sout.str();
}

Gasto gasto(int idCons, int fecha, double importe, string categoria) {
  Gasto a;
  a.idCons = idCons;
  a.fecha = fecha;
  a.importe = importe;
  strcpy(a.categoria, categoria.c_str());
  return a;
}

bool gastoEquals(Gasto a, Gasto b) {
  if (a.idCons != b.idCons)
    return false;
  if (a.fecha != b.fecha)
    return false;
  if (a.importe != b.importe)
    return false;
  return true;
}

string consorcioToString(Consorcio x) {
  char sep = 2;
  string sIdCons = to_string(x.idCons);
  string sDireccion = x.direccion;
  string sCantPisos = to_string(x.cantPisos);
  string sDtosPorPiso = to_string(x.dtosPorPiso);
  return sIdCons + sep + sDireccion + sep + sCantPisos + sep + sDtosPorPiso;
}

Consorcio consorcioFromString(string s) {
  char sep = 2;
  Consorcio x;
  string t0 = getTokenAt(s, sep, 0);
  x.idCons = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  strcpy(x.direccion, t1.c_str());
  string t2 = getTokenAt(s, sep, 2);
  x.cantPisos = stoi(t2);
  string t3 = getTokenAt(s, sep, 3);
  x.dtosPorPiso = stoi(t3);
  return x;
}

string consorcioToDebug(Consorcio x) {
  stringstream sout;
  sout << "[";
  sout << x.idCons;
  sout << ",";
  sout << x.direccion;
  sout << ",";
  sout << x.cantPisos;
  sout << ",";
  sout << x.dtosPorPiso;
  sout << "]";
  return sout.str();
}

string consorcioToDebug(string mssg, Consorcio x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idCons;
  sout << ",";
  sout << x.direccion;
  sout << ",";
  sout << x.cantPisos;
  sout << ",";
  sout << x.dtosPorPiso;
  sout << "]";
  return sout.str();
}

Consorcio consorcio(int idCons, string direccion, int cantPisos,
                    int dtosPorPiso) {
  Consorcio a;
  a.idCons = idCons;
  strcpy(a.direccion, direccion.c_str());
  a.cantPisos = cantPisos;
  a.dtosPorPiso = dtosPorPiso;
  return a;
}

bool consorcioEquals(Consorcio a, Consorcio b) {
  if (a.idCons != b.idCons)
    return false;
  if (a.cantPisos != b.cantPisos)
    return false;
  if (a.dtosPorPiso != b.dtosPorPiso)
    return false;
  return true;
}

string deptoToString(Depto x) {
  char sep = 3;
  string sIdCons = to_string(x.idCons);
  string sIdDepto = to_string(x.idDepto);
  string sMtsPorcentaje = to_string(x.mtsPorcentaje);
  string sGastoAcumulado = to_string(x.gastoAcumulado);
  return sIdCons + sep + sIdDepto + sep + sMtsPorcentaje + sep +
         sGastoAcumulado;
}

Depto deptoFromString(string s) {
  char sep = 3;
  Depto x;
  string t0 = getTokenAt(s, sep, 0);
  x.idCons = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.idDepto = stoi(t1);
  string t2 = getTokenAt(s, sep, 2);
  x.mtsPorcentaje = stod(t2);
  string t3 = getTokenAt(s, sep, 3);
  x.gastoAcumulado = stod(t3);
  return x;
}

string deptoToDebug(Depto x) {
  stringstream sout;
  sout << "[";
  sout << x.idCons;
  sout << ",";
  sout << x.idDepto;
  sout << ",";
  sout << x.mtsPorcentaje;
  sout << ",";
  sout << x.gastoAcumulado;
  sout << "]";
  return sout.str();
}

string deptoToDebug(string mssg, Depto x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idCons;
  sout << ",";
  sout << x.idDepto;
  sout << ",";
  sout << x.mtsPorcentaje;
  sout << ",";
  sout << x.gastoAcumulado;
  sout << "]";
  return sout.str();
}

Depto depto(int idCons, int idDepto, double mtsPorcentaje,
            double gastoAcumulado) {
  Depto a;
  a.idCons = idCons;
  a.idDepto = idDepto;
  a.mtsPorcentaje = mtsPorcentaje;
  a.gastoAcumulado = gastoAcumulado;
  return a;
}

bool deptoEquals(Depto a, Depto b) {
  if (a.idCons != b.idCons)
    return false;
  if (a.idDepto != b.idDepto)
    return false;
  if (a.mtsPorcentaje != b.mtsPorcentaje)
    return false;
  if (a.gastoAcumulado != b.gastoAcumulado)
    return false;
  return true;
}

Coll<Gasto> cargarGastos();

Coll<Consorcio> cargarConsorcios();

int cmpDeptoMts(Depto a, Depto b) { return a.mtsPorcentaje - b.mtsPorcentaje; }

void imprimirDatos(Coll<Depto> listaDeptos, Consorcio consorcio,
                   int gastosTotales);

#endif
