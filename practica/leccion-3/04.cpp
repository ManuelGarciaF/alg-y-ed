#include <iostream>
#include <unistd.h>

#include "TADs/timer.hpp"

using std::cout;
using std::endl;

int main() {
  Timer t1 = timer();

  timerStart(t1);
  sleep(4); // Esperar 4 segundos.
  timerStop(t1);

  cout << "Milis:" << timerElapsedTime(t1) << endl;

  return 0;
}
