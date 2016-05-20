#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "graf.hh"
#include "lista.hh"
#include "tablica.hh"
#include <sys/time.h>
#define RG 1000

int main(){

  test_grafu g(RG,10);
  struct timeval start;
  struct timeval end;
  long long int ms=0, s=0,us=0;

  
  system("echo 'Begin of test' | festival --tts"); //komunikat glosowy rozpoczecia testu.
  g.prepare();
  cout<<"--BFS--"<<endl;
  system("echo 'Start of BFS' | festival --tts");
  gettimeofday(&start,NULL);
  g.run();
  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Liczba_wierzcholkow: "<<RG<<endl;
  

  //generowanie dzwieku, zeby slyszec kiedy komputer zakonczyl test
  system("echo 'New announcement: End of BFS' | festival --tts");
  //system("echo ' ' | festival --tts");
  system("echo '--Exit--' | festival --tts");
  return 0;
}
