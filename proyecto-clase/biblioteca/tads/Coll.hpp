#ifndef _TCOLL_T_
#define _TCOLL_T_

#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include <iostream>

using namespace std;

template <typename T> struct Coll {
  string token;
  char sep;
  int currIndex;
};

template <typename T> Coll<T> coll(char sep) {
  Coll<T> c;
  c.token = "";
  c.sep = sep;
  c.currIndex = 0;
  return c;
}

template <typename T> Coll<T> coll() { return coll<T>('|'); }

template <typename T> int collSize(Coll<T> c) {
  return tokenCount(c.token, c.sep);
}

template <typename T> void collRemoveAll(Coll<T> &c) { c.token = ""; }

template <typename T> void collRemoveAt(Coll<T> &c, int p) {
  removeTokenAt(c.token, c.sep, p);
}

template <typename T> int collAdd(Coll<T> &c, T t, string tToString(T)) {
  addToken(c.token, c.sep, tToString(t));
  return collSize(c) - 1;
}

template <typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T)) {
  setTokenAt(c.token, c.sep, tToString(t), p);
}

template <typename T> T collGetAt(Coll<T> c, int p, T tFromString(string)) {
  return tFromString(getTokenAt(c.token, c.sep, p));
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string)) {
  for (int i = 0, len = collSize(c); i < len; i++) {
    if (cmpTK(collGetAt(c, i, tFromString), k) == 0) {
      return i;
    }
  }
  return -1;
}

template <typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string),
              string tToString(T)) {
  bool swapped;
  do {
    swapped = false;
    for (int i = 1, len = collSize(c); i < len; i++) {
      T primerElem = collGetAt<T>(c, i - 1, tFromString);
      T segundoElem = collGetAt<T>(c, i, tFromString);
      if (cmpTT(primerElem, segundoElem) < 0) {
        // Cambiar de lugar ambos elementos.
        collSetAt<T>(c, segundoElem, i - 1, tToString);
        collSetAt<T>(c, primerElem, i, tToString);
        swapped = true;
      }
    }
  } while (swapped);
}

template <typename T> bool collHasNext(Coll<T> c) {
  return c.currIndex < collSize(c);
}

template <typename T> T collNext(Coll<T> &c, T tFromString(string)) {
  T t = collGetAt<T>(c, c.currIndex, tFromString);
  c.currIndex++;
  return t;
}

template <typename T>
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string)) {
  endOfColl = !collHasNext(c);
  return collNext(c, tFromString);
}

template <typename T> void collReset(Coll<T> &c) { c.currIndex = 0; }

#endif
