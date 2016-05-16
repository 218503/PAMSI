#include <iostream>

#include "graf.hh"
#include "lista.hh"
#include "tablica.hh"
#include <sys/time.h>
#define RG 1000


int main(){

  test_grafu g(RG);
  struct timeval start;
  struct timeval end;
  long long int ms=0, s=0,us=0;
  
  gettimeofday(&start,NULL);
  g.prepare();
  g.run();
  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Liczba_wierzcholkow: "<<RG<<endl;

  

  return 0;
}
