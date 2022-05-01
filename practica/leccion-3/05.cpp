#include <iostream>

#include "TADs/timer.hpp"

using std::cout;
using std::endl;

void f(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ;
}

int main() {
  Timer t1 = timer();
  timerStart(t1);
  f(100);
  timerStop(t1);

  Timer t2 = timer();
  timerStart(t2);
  f(1000);
  timerStop(t2);

  Timer t3 = timer();
  timerStart(t3);
  f(10000);
  timerStop(t3);

  Timer t4 = timer();
  timerStart(t4);
  f(100000);
  timerStop(t4);

  cout << "f(100)   : " << timerElapsedTime(t1) << "ms" << endl;
  cout << "f(1000)  : " << timerElapsedTime(t2) << "ms" << endl;
  cout << "f(10000) : " << timerElapsedTime(t3) << "ms" << endl;
  cout << "f(100000): " << timerElapsedTime(t4) << "ms" << endl;
}
