#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T> void write(FILE *f, T t) {
  // Se debe anteponer esta linea al inicio de la funcion.
  // De otro modo, apareceran errores al momento de actualizar
  // archivos. Esto se debe a un error en la implementacion de Windows.
  
  fseek(f, 0, SEEK_CUR);
  fwrite(&t, sizeof(T), 1, f);
}

template <typename T> T read(FILE *f) {
  // Se debe anteponer esta linea al inicio de la funcion.
  // De otro modo, apareceran errores al momento de actualizar
  // archivos. Esto se debe a un error en la implementacion de Windows.
  
  fseek(f,0,SEEK_CUR);
  T t;

  fread(&t, sizeof(T), 1, f);

  return t;
}

template <typename T> void seek(FILE *f, int n) {
  fseek(f, n*sizeof(T), SEEK_SET);
}

template <typename T> int fileSize(FILE *f) {
  // Reiniciar la posición de f.
  fseek(f, 0, SEEK_SET);

  long long i = 0;
  while (fgetc(f) != EOF) {
    i++;
  }

  // Reiniciar la posición de f.
  fseek(f, 0, SEEK_SET);

  // Dividir la cantidad de bytes por el tamanio del tipo.
  return i / sizeof(T);
}

template <typename T> int filePos(FILE *f) { 
  return ftell(f) / sizeof(T);
}

#endif
