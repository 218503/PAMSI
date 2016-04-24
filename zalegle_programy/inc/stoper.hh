#ifndef _STOPER_HH
#define _STOPER_HH
#include <stdio.h>
#include <sys/time.h>

using namespace std;

class stoper{
public:
  
  struct timeval start, end;
  int koniec();
  int poczatek();
  
};

int stoper::poczatek()
{
  gettimeofday(&start,NULL);
    return 0;
}

int stoper::koniec()
{
  gettimeofday(&end,NULL);
  return 0;
}
#endif
