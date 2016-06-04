#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <fstream>
#include <string>
#include "lista.hh"
#include "irunn.hh"
#include "tablica.hh"
#include "tabl_asoc.hh"

#define RD 10000000
#define MAX 10

using namespace std;

int main(){

  // TABLICA ASOCJACYJNA 
  struct timeval start;
  struct timeval end;
  long long int ms=0, s=0,us=0;

  int i=0,key=0;
  int max=MAX;
  ifstream plik;
  int *liczby=new int[max];
  string *nazwiska=new string[max];
  string z;
  srand(time(NULL));
  for(int a=0;a<max;a++) liczby[a]=0;
  plik.open("nn.txt");
  if(plik.good()){
    cout<<"OPEN"<<endl;
    for(i=0;i<max;i++){
      plik>>nazwiska[i];
      plik>>liczby[i];
    }
  }
  plik.close();
  test_asoc<int,string> tabl(max);
  gettimeofday(&start, NULL);
  
  tabl.prepare(max,liczby,nazwiska);

  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"| CZAS TWORZENIA TABLICY"<<endl;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<max<<" elementow"<<endl;
 
  cout<<"______________________________________"<<endl;
  key=liczby[rand()%max];
  gettimeofday(&start, NULL);

  tabl.run(key);

  gettimeofday(&end,NULL); 
  s=(end.tv_sec-start.tv_sec);
  ms=(end.tv_usec-start.tv_usec)/1000;
  us=(end.tv_usec-start.tv_usec)%1000;
  cout<<"| CZAS WYSZUKIWANIA ELEMENTU"<<endl;
  cout<<"|   Czas: "<<s<<"s "<<ms<<"ms "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy: "<<max<<" elementow"<<endl;

  return 0;
}


