#include <stdio.h>

#define FILENAME "reproducciones.dat"

/* Structs */

struct Str {
  int idUsuario;
  int idLibro;
  int fecha;
  int minutos;
};

/* Arrays */

struct Str data[] = {
    {3, 1, 48388, 25},
    {9, 1, 48388, 25},
    {0xAAAA, 1, 48388, 25},
    {1, 1, 48388, 25},
    {1, 1, 48388, 25},
    {1, 1, 48388, 25},
    {1, 1, 48388, 25},
};

int main() {
  FILE *f = fopen(FILENAME, "wb");

  unsigned int arrayLength = sizeof(data) / sizeof(struct Str);
  fwrite(data, sizeof(struct Str), arrayLength, f);

  return 0;
}
