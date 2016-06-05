#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "graf.hh"
// #include "lista.hh"
//#include "tablica.hh"
#include <sys/time.h>
#define RG 100


int main(){

  test_grafu g(RG,10);
  struct timeval start,st;
  struct timeval end,en;
  long long int ms=0, s=0,us=0;

  
  //system("echo 'Begin of test' | festival --tts"); //komunikat glosowy rozpoczecia testu.
  gettimeofday(&st,NULL);
  g.prepare();
  gettimeofday(&en,NULL);
  s=(en.tv_sec-st.tv_sec);
  ms=(en.tv_usec-st.tv_usec)/1000;
  us=(en.tv_usec-st.tv_usec)%1000;
  cout<<"*   Czas przygotowania: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;

  s=0;ms=0;us=0;
  cout<<endl<<"--B&B--"<<endl;
  gettimeofday(&start,NULL);
  g.run();
  gettimeofday(&end,NULL); 
  g.remove();
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Liczba_wierzcholkow: "<<RG<<endl;
  

  //generowanie dzwieku, zeby slyszec kiedy komputer zakonczyl test
  // system("echo '--Exit--' | festival --tts");
  return 0;
}
