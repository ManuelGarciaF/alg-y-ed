#include "timer.hpp"

Long timeInMillis() {
  struct timeval i;
  gettimeofday(&i, NULL);
  return (i.tv_sec * 1000000 + i.tv_usec) / 1000;
}

Timer timer() { return {}; }

void timerStart(Timer &t) { t.start = timeInMillis(); }

void timerStop(Timer &t) { t.end = timeInMillis(); }

Long timerElapsedTime(Timer t) { return t.end - t.start; }
