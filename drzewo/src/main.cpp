#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sys/time.h>

#include "drzewo.hh"
#include "tablica.hh"
#define LL 11
using namespace std;


int main(){
  drzewo d;
  int i;
  struct timeval start;
  struct timeval end;
  double ms=0, s=0,us=0;

  gettimeofday(&start, NULL);
  d.generator(LL);
  cout<<"Zawartosc tablicy"<<endl;
  d.tabl->display();
  cout<<"Drzewo"<<endl;
  d.wstaw(d.korzen(),d.tabl->pop_0(LL/2));
  for(i=LL/2+1;i<LL;i++){
    d.wstaw(d.korzen(),d.tabl->pop_0(i));}
  
  for(i=0;i<LL/2;i++){
    d.wstaw(d.korzen(),d.tabl->pop_0(i));}
  cout<<endl<<"Preorder"<<endl;
  d.preorder(d.korzen());
  cout<<endl<<"Inorder"<<endl;
  d.inorder(d.korzen());
  cout<<endl<<"Postorder"<<endl;
  d.postorder(d.korzen());

  cout<<endl<<"korzen= "<<d.korzen()->zawartosc<<endl<<endl;
  
  cout<<endl;
  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar problemu: "<<LL<<" elementow"<<endl;
  d.tabl->display();
  // gettimeofday(&start, NULL);
 
  // p=d.wyszukaj(k1,300);
  // if(p!=NULL){
  //   cout<<"wyszukiwanie zakonczone powodzeniem, "<<p->zawartosc<<endl;
  // }
  // else{cout<<"wyszukiwanie nie powiodlo sie"<<endl;}
  //     gettimeofday(&end,NULL); 
  //   s=(end.tv_sec-start.tv_sec);
  //   ms=(end.tv_usec-start.tv_usec)/1000;
  //   us=(end.tv_usec-start.tv_usec)%1000;
  //   cout<<"|   Czas wyszukiwania: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  //   cout<<"|   Rozmiar problemu: "<<LL<<" elementow"<<endl;
  return 0;
}
