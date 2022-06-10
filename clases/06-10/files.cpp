#include <iostream>

using namespace std;

int main() {
  FILE *f = fopen("a.txt", "r+b");

  int d[2] = {23, 45};

  fwrite(&d, sizeof(int), 2, f);

  fclose(f);

  return 0;
}
