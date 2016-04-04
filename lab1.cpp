#include <stdio.h>
#include <iostream>
#include <sys/time.h>


using namespace std;
class tab {
public:
  int *wsk;
  tab(int l);
  int liczba;
};


tab::tab(int l){  
   liczba=l;
   wsk=new int[liczba];
}

int main(){

  struct timeval start, end;
  unsigned long long us;
  tab t(5); 
  int i,j,max=1000;  //max - rozmiar do jakiego chcemy rozszerzyc tablice
  int *tablica=new int[5]; //tablica pomocnicza


  gettimeofday(&start, NULL);

  for(i=0;i<max;i++){
    if(i<5){
      t.wsk[i]=i;
    }
    else { 
      tablica=new int[i];
      for(j=0;j<(i);j++){ tablica[j]=t.wsk[j];}
      delete [] t.wsk;
      t.wsk=new int[i+1];
      for(j=0;j<(i);j++){t.wsk[j]=tablica[j];}
      t.wsk[i]=i;
      delete [] tablica;
      t.liczba=i+1;
    }
  }

  gettimeofday(&end,NULL);
  us=end.tv_usec-start.tv_usec;
 
  // for(i=0;i<t.liczba;i++){ cout<<t.wsk[i]<<endl; } //wypisanie tablicy na ekranie

  cout<<"|   Czas "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy "<<t.liczba<<" elementow"<<endl;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  max=10000;
  gettimeofday(&start, NULL);

  for(i=0;i<max;i++){
    if(i<5){
      t.wsk[i]=i;
    }
    else { 
      tablica=new int[i];
      for(j=0;j<(i);j++){ tablica[j]=t.wsk[j];}
      delete [] t.wsk;
      t.wsk=new int[i+1];
      for(j=0;j<(i);j++){t.wsk[j]=tablica[j];}
      t.wsk[i]=i;
      delete [] tablica;
      t.liczba=i+1;
    }
  }

  gettimeofday(&end,NULL);
  us=end.tv_usec-start.tv_usec;
 
  // for(i=0;i<t.liczba;i++){ cout<<t.wsk[i]<<endl; } //wypisanie tablicy na ekranie

  cout<<"|   Czas "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy "<<t.liczba<<" elementow"<<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  max=100000;
  gettimeofday(&start, NULL);

  for(i=0;i<max;i++){
    if(i<5){
      t.wsk[i]=i;
    }
    else { 
      tablica=new int[i];
      for(j=0;j<(i);j++){ tablica[j]=t.wsk[j];}
      delete [] t.wsk;
      t.wsk=new int[i+1];
      for(j=0;j<(i);j++){t.wsk[j]=tablica[j];}
      t.wsk[i]=i;
      delete [] tablica;
      t.liczba=i+1;
    }
  }

  gettimeofday(&end,NULL);
  us=end.tv_usec-start.tv_usec;
 
  // for(i=0;i<t.liczba;i++){ cout<<t.wsk[i]<<endl; } //wypisanie tablicy na ekranie

  cout<<"|   Czas "<<us<<"us"<<endl;
  cout<<"|   Rozmiar tablicy "<<t.liczba<<" elementow"<<endl;
  return 0;
}



