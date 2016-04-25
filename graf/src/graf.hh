#ifndef GRAF_HH
#define GRAF_HH

#include "lista.hh"

#define LW 10
class graf{
  int w,k;
  ilista<int> **tablica=NULL;
  
public:
  void dodaj_wierzcholek();
  void dodaj_krawedz();
  void usun_wierzcholek();
  void sasiadujace_wierzcholki();
  void sasiadujace_krawedzie();
  
  graf(){
    tablica=new ilista<int> *[LW];
  }
};



#endif
