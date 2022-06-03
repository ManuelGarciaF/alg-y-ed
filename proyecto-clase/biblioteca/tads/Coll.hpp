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
  return c;
}

template <typename T> Coll<T> coll() {
  Coll<T> c;
  c.sep = "|";
  return c;
}

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
              string tToString(T)) {}

template <typename T> bool collHasNext(Coll<T> c) { return true; }

template <typename T> T collNext(Coll<T> &c, T tFromString(string)) {
  T t;
  return t;
}

template <typename T>
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string)) {
  T t;
  return t;
}

template <typename T> void collReset(Coll<T> &c) {}

#endif
