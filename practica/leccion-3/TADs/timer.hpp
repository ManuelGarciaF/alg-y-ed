#include <cstddef>
#include <sys/time.h>

typedef unsigned long long Long;

struct Timer {
  Long start;
  Long end;
};

Timer timer();

void timerStart(Timer &t);
void timerStop(Timer &t);
Long timerElapsedTime(Timer t);

Long timeInMillis();
