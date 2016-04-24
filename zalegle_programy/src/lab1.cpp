#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include "stoper.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"
#include "irunn.hh"
#include "tablica.hh"

using namespace std;

int main(){
  int xyz=20,i,max=1000000;
  struct timeval start;
  struct timeval end;
  double ms=0, s=0,us=0;
  itab<int> * t=new tab<int>; 
 
  cout<<"ALGORYTM POWIEKSZANIA O 1:"<<endl;
  gettimeofday(&start, NULL);
  for(i=0;i<max;i++) {t->push_back(xyz+i);}
  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<t->size()<<" elementow"<<endl;
  t->remove();
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout<<"ALGORYTM POWIEKSZANIA *2:"<<endl;
  gettimeofday(&start, NULL);
  for(i=0;i<max;i++) {t->push_back_x2(xyz+i);}
  gettimeofday(&end,NULL);
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;  
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<t->size()<<" elementow"<<endl;
  t->remove();

  
  cout<<"ALGORYTM POWIEKSZANIA 'O 100':"<<endl;
  gettimeofday(&start, NULL);
  for(i=0;i<max;i++){t->push_back_fast(xyz+i);}
  gettimeofday(&end,NULL);
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<t->size()<<" elementow"<<endl;
  
  t->remove();
  
  
  cout<<"Insert"<<endl;
  gettimeofday(&start, NULL);
  for(i=0;i<max;i++){t->push_back_x2(xyz+i);}
  t->insert(321,max-3);
  gettimeofday(&end,NULL);
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<t->size()<<" elementow"<<endl;
  t->remove();
  cout<<"__________________________________________________"<<endl;
  return 0;
}



