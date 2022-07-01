#ifndef _MAINHPP
#define _MAINHPP
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

struct Libro {
  int idLibro;
  int idRelator;
  int idAutor;
  char titulo[50];
  int duracion;
};

struct RLibro {
  Libro libro;
  int c100;
  int c75;
  int c50;
  int c25;
  int c1;
};

struct Reproduccion {
  int idUsuario;
  int idLibro;
  int fecha;
  int minutos;
};

struct Relator {
  int idRelator;
  char nombre[50];
};

struct RRelator {
  Relator relator;
  int cont;
};

string libroToString(Libro x) {
  char sep = 1;
  string sIdLibro = to_string(x.idLibro);
  string sIdRelator = to_string(x.idRelator);
  string sIdAutor = to_string(x.idAutor);
  string sTitulo = x.titulo;
  string sDuracion = to_string(x.duracion);
  return sIdLibro + sep + sIdRelator + sep + sIdAutor + sep + sTitulo + sep +
         sDuracion;
}

Libro libroFromString(string s) {
  char sep = 1;
  Libro x;
  string t0 = getTokenAt(s, sep, 0);
  x.idLibro = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.idRelator = stoi(t1);
  string t2 = getTokenAt(s, sep, 2);
  x.idAutor = stoi(t2);
  string t3 = getTokenAt(s, sep, 3);
  strcpy(x.titulo, t3.c_str());
  string t4 = getTokenAt(s, sep, 4);
  x.duracion = stoi(t4);
  return x;
}

string libroToDebug(Libro x) {
  stringstream sout;
  sout << "[";
  sout << x.idLibro;
  sout << ",";
  sout << x.idRelator;
  sout << ",";
  sout << x.idAutor;
  sout << ",";
  sout << x.titulo;
  sout << ",";
  sout << x.duracion;
  sout << "]";
  return sout.str();
}

string libroToDebug(string mssg, Libro x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idLibro;
  sout << ",";
  sout << x.idRelator;
  sout << ",";
  sout << x.idAutor;
  sout << ",";
  sout << x.titulo;
  sout << ",";
  sout << x.duracion;
  sout << "]";
  return sout.str();
}

Libro libro(int idLibro, int idRelator, int idAutor, string titulo,
            int duracion) {
  Libro a;
  a.idLibro = idLibro;
  a.idRelator = idRelator;
  a.idAutor = idAutor;
  strcpy(a.titulo, titulo.c_str());
  a.duracion = duracion;
  return a;
}

bool libroEquals(Libro a, Libro b) {
  if (a.idLibro != b.idLibro)
    return false;
  if (a.idRelator != b.idRelator)
    return false;
  if (a.idAutor != b.idAutor)
    return false;
  if (a.duracion != b.duracion)
    return false;
  return true;
}

string rLibroToString(RLibro x) {
  char sep = 2;
  string sLibro = libroToString(x.libro);
  string sC100 = to_string(x.c100);
  string sC75 = to_string(x.c75);
  string sC50 = to_string(x.c50);
  string sC25 = to_string(x.c25);
  string sC1 = to_string(x.c1);
  return sLibro + sep + sC100 + sep + sC75 + sep + sC50 + sep + sC25 + sep +
         sC1;
}

RLibro rLibroFromString(string s) {
  char sep = 2;
  RLibro x;
  string t0 = getTokenAt(s, sep, 0);
  x.libro = libroFromString(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.c100 = stoi(t1);
  string t2 = getTokenAt(s, sep, 2);
  x.c75 = stoi(t2);
  string t3 = getTokenAt(s, sep, 3);
  x.c50 = stoi(t3);
  string t4 = getTokenAt(s, sep, 4);
  x.c25 = stoi(t4);
  string t5 = getTokenAt(s, sep, 5);
  x.c1 = stoi(t5);
  return x;
}

string rLibroToDebug(RLibro x) {
  stringstream sout;
  sout << "[";
  sout << libroToDebug(x.libro);
  sout << ",";
  sout << x.c100;
  sout << ",";
  sout << x.c75;
  sout << ",";
  sout << x.c50;
  sout << ",";
  sout << x.c25;
  sout << ",";
  sout << x.c1;
  sout << "]";
  return sout.str();
}

string rLibroToDebug(string mssg, RLibro x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << libroToDebug(x.libro);
  sout << ",";
  sout << x.c100;
  sout << ",";
  sout << x.c75;
  sout << ",";
  sout << x.c50;
  sout << ",";
  sout << x.c25;
  sout << ",";
  sout << x.c1;
  sout << "]";
  return sout.str();
}

RLibro rLibro(Libro libro, int c100, int c75, int c50, int c25, int c1) {
  RLibro a;
  a.libro = libro;
  a.c100 = c100;
  a.c75 = c75;
  a.c50 = c50;
  a.c25 = c25;
  a.c1 = c1;
  return a;
}

bool rLibroEquals(RLibro a, RLibro b) {
  if (!libroEquals(a.libro, b.libro))
    return false;
  if (a.c100 != b.c100)
    return false;
  if (a.c75 != b.c75)
    return false;
  if (a.c50 != b.c50)
    return false;
  if (a.c25 != b.c25)
    return false;
  if (a.c1 != b.c1)
    return false;
  return true;
}

string reproduccionToString(Reproduccion x) {
  char sep = 3;
  string sIdUsuario = to_string(x.idUsuario);
  string sIdLibro = to_string(x.idLibro);
  string sFecha = to_string(x.fecha);
  string sMinutos = to_string(x.minutos);
  return sIdUsuario + sep + sIdLibro + sep + sFecha + sep + sMinutos;
}

Reproduccion reproduccionFromString(string s) {
  char sep = 3;
  Reproduccion x;
  string t0 = getTokenAt(s, sep, 0);
  x.idUsuario = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.idLibro = stoi(t1);
  string t2 = getTokenAt(s, sep, 2);
  x.fecha = stoi(t2);
  string t3 = getTokenAt(s, sep, 3);
  x.minutos = stoi(t3);
  return x;
}

string reproduccionToDebug(Reproduccion x) {
  stringstream sout;
  sout << "[";
  sout << x.idUsuario;
  sout << ",";
  sout << x.idLibro;
  sout << ",";
  sout << x.fecha;
  sout << ",";
  sout << x.minutos;
  sout << "]";
  return sout.str();
}

string reproduccionToDebug(string mssg, Reproduccion x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idUsuario;
  sout << ",";
  sout << x.idLibro;
  sout << ",";
  sout << x.fecha;
  sout << ",";
  sout << x.minutos;
  sout << "]";
  return sout.str();
}

Reproduccion reproduccion(int idUsuario, int idLibro, int fecha, int minutos) {
  Reproduccion a;
  a.idUsuario = idUsuario;
  a.idLibro = idLibro;
  a.fecha = fecha;
  a.minutos = minutos;
  return a;
}

bool reproduccionEquals(Reproduccion a, Reproduccion b) {
  if (a.idUsuario != b.idUsuario)
    return false;
  if (a.idLibro != b.idLibro)
    return false;
  if (a.fecha != b.fecha)
    return false;
  if (a.minutos != b.minutos)
    return false;
  return true;
}

string relatorToString(Relator x) {
  char sep = 4;
  string sIdRelator = to_string(x.idRelator);
  string sNombre = x.nombre;
  return sIdRelator + sep + sNombre;
}

Relator relatorFromString(string s) {
  char sep = 4;
  Relator x;
  string t0 = getTokenAt(s, sep, 0);
  x.idRelator = stoi(t0);
  string t1 = getTokenAt(s, sep, 1);
  strcpy(x.nombre, t1.c_str());
  return x;
}

string relatorToDebug(Relator x) {
  stringstream sout;
  sout << "[";
  sout << x.idRelator;
  sout << ",";
  sout << x.nombre;
  sout << "]";
  return sout.str();
}

string relatorToDebug(string mssg, Relator x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << x.idRelator;
  sout << ",";
  sout << x.nombre;
  sout << "]";
  return sout.str();
}

Relator relator(int idRelator, string nombre) {
  Relator a;
  a.idRelator = idRelator;
  strcpy(a.nombre, nombre.c_str());
  return a;
}

bool relatorEquals(Relator a, Relator b) {
  if (a.idRelator != b.idRelator)
    return false;
  return true;
}

string rRelatorToString(RRelator x) {
  char sep = 5;
  string sRelator = relatorToString(x.relator);
  string sCont = to_string(x.cont);
  return sRelator + sep + sCont;
}

RRelator rRelatorFromString(string s) {
  char sep = 5;
  RRelator x;
  string t0 = getTokenAt(s, sep, 0);
  x.relator = relatorFromString(t0);
  string t1 = getTokenAt(s, sep, 1);
  x.cont = stoi(t1);
  return x;
}

string rRelatorToDebug(RRelator x) {
  stringstream sout;
  sout << "[";
  sout << relatorToDebug(x.relator);
  sout << ",";
  sout << x.cont;
  sout << "]";
  return sout.str();
}

string rRelatorToDebug(string mssg, RRelator x) {
  stringstream sout;
  sout << mssg << ":[";
  sout << relatorToDebug(x.relator);
  sout << ",";
  sout << x.cont;
  sout << "]";
  return sout.str();
}

RRelator rRelator(Relator relator, int cont) {
  RRelator a;
  a.relator = relator;
  a.cont = cont;
  return a;
}

bool rRelatorEquals(RRelator a, RRelator b) {
  if (!relatorEquals(a.relator, b.relator))
    return false;
  if (a.cont != b.cont)
    return false;
  return true;
}

int cmpRLibroId(RLibro l, int id) { return l.libro.idLibro - id; }

int cmpRRelatorId(RRelator r, int id) { return r.relator.idRelator - id; }

int cmpRRelatorReproducciones(RRelator a, RRelator b) {
  return a.cont - b.cont;
}

#endif
