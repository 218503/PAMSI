#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sys/time.h>

#include "drzewo.hh"
#include "tablica.hh"
#define LL 1000
using namespace std;


int main(int argc, char *argv[]){
  drzewo d;
  element *k1=new element;
  element *p=new element;
  int i;
  struct timeval start;
  struct timeval end;
  double ms=0, s=0,us=0;

  gettimeofday(&start, NULL);
  d.generator(LL);
  k1->zawartosc=LL/2+1;
  for(i=LL/2;i>0;i--){d.wstaw(k1,i);}
  for(i=LL/2+1;i<=LL;i++){d.wstaw(k1,i);}
  d.wypelnij(k1);
  d.inorder(k1);
  cout<<endl<<endl<<"korzen= "<<k1->zawartosc<<endl<<endl;
    gettimeofday(&end,NULL); 
    s=(end.tv_sec-start.tv_sec);
    ms=(end.tv_usec-start.tv_usec)/1000;
    us=(end.tv_usec-start.tv_usec)%1000;
    cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
    cout<<"|   Rozmiar problemu: "<<LL<<" elementow"<<endl;
    

    gettimeofday(&start, NULL);
 
  p=d.wyszukaj(k1,30407621);
  if(p!=NULL){
    cout<<"wyszukiwanie zakonczone powodzeniem, "<<p->zawartosc<<endl;
  }
  else{cout<<"wyszukiwanie nie powiodlo sie"<<endl;}
      gettimeofday(&end,NULL); 
    s=(end.tv_sec-start.tv_sec);
    ms=(end.tv_usec-start.tv_usec)/1000;
    us=(end.tv_usec-start.tv_usec)%1000;
    cout<<"|   Czas wyszukiwania: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
    cout<<"|   Rozmiar problemu: "<<LL<<" elementow"<<endl;
  return 0;
}
