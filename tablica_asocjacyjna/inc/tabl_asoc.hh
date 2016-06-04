#ifndef _TABL_ASOC_HH
#define _TABL_ASOC_HH

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include "irunn.hh"
#include "tablica.hh"
#include "lista.hh"
using namespace std;

// Klasa przechowujaca klucz i wartosc
template <class typ1,class typ2>
class rekord{
public:
  typ1 klucz;
  typ2 wartosc;
  rekord(){    
  }
  rekord(typ1 k,typ2 w){
    klucz=k;
    wartosc=w;
  }
  rekord<typ1,typ2> & operator = (const int & x);
  rekord<typ1,typ2> & operator = (const string & x);
  rekord<typ1,typ2> &operator = (const rekord<typ1,typ2>& ww);
};


//Interfejs klasy tab_asoc
template <class typ1,class typ2>
class itab_asoc{
public:
  virtual void dodaj(typ1,typ2)=0;
  virtual void usun()=0;
  virtual void wyswietl()=0;
  virtual typ2 znajdz(typ1)=0;
  virtual int haszuj(typ1)=0;
};


template <class typ1,class typ2>
class tab_asoc : public itab_asoc<typ1,typ2>{
private:
  int rozmiar;
  lista<rekord<typ1,typ2>> *tablica;
public:
  virtual void dodaj(typ1 k,typ2 w);
  virtual void usun(){}
  virtual void wyswietl();
  virtual typ2 znajdz(typ1 k);
  virtual int haszuj(typ1 k);

  tab_asoc(int liczba){
    rozmiar=liczba;
    tablica=new lista<rekord<typ1,typ2>>[rozmiar];//tablica list rekordów
  }

  typ2 & operator [](typ1 klucz){
    return tablica[haszuj(klucz)];
  }
};



template <class typ1,class typ2>
void tab_asoc<typ1,typ2>::dodaj(typ1 k, typ2 w){
  rekord<typ1,typ2> r(k,w);
  tablica[haszuj(k)].push_back(r);
}


template <class typ1, class typ2>
void tab_asoc<typ1,typ2>::wyswietl(){
  for(int i=0;i<rozmiar;i++){
    cout<<"---BUCKET--- "<<i<<endl;
    tablica[i].display();
  }
}

template <class typ1,class typ2>
typ2 tab_asoc<typ1,typ2>::znajdz(typ1 k){
  int i=0;
  while(tablica[haszuj(k)].check_value(i).klucz!=k) i++;

  return tablica[haszuj(k)].check_value(i).wartosc;
}


template <class typ1,class typ2>
int tab_asoc<typ1,typ2>::haszuj(typ1 klucz){
  int poz=0;
  poz+=(klucz/(123));
  poz=(int)poz%(rozmiar);
  return poz;
}



template <class typ1,class typ2>
class test_asoc{
  itab_asoc<typ1,typ2> *ta;
  
public:
  test_asoc(int m){
    ta=new tab_asoc<typ1,typ2>(m);
  }
  bool prepare(int rozmiar,typ1 kl[],typ2 wart[]){
    int i;
    srand(time(NULL));
    for(i=0;i<rozmiar;i++){
      ta->dodaj(kl[i],wart[i]);
    }
    return true;
  }
  
  int run(int klucz){
    cout<<"ZNALEZIONO:"<<endl;
    cout<<ta->znajdz(klucz)<<endl;
    return 0;
  }

};




template <class typ1, class typ2>
rekord<typ1,typ2> & rekord<typ1,typ2>::operator = (const int & x){
  klucz=x;
  return *this;
}

template <class typ1,class typ2>
rekord<typ1,typ2> & rekord<typ1,typ2>::operator = (const string & y){
  for(int i=0;i<y.length();i++)
    wartosc[i]=y[i];
  return *this;
}

template <class typ1,class typ2>
rekord<typ1,typ2> & rekord<typ1,typ2>::operator = (const rekord<typ1,typ2>& ww){
  wartosc=ww.wartosc;
  klucz=ww.klucz;
  return *this;
}

template <class typ1,class typ2>
bool operator ==( const rekord<typ1,typ2> & r1, const string & s){
  if(r1.wartosc==s) return true;
  return false;
}


template <class typ1,class typ2>
bool operator ==( const rekord<typ1,typ2> & r1, const rekord<typ1,typ2> & r2){
  if(r1.wartosc==r2.wartosc) return true;
  return false;
}

 template <class typ1,class typ2>
 bool operator ==( const rekord<typ1,typ2> & r1, const int & a){
   if(r1.klucz==a) return true;
   return false;
 }

template <class typ1,class typ2>
ostream & operator<<(ostream & ekran, rekord<typ1,typ2> & r){
  ekran<<"Wartosc = "<<r.wartosc<<endl;
  ekran<<"Klucz: "<<r.klucz<<endl;
  return ekran;
}


template <class typ1,class typ2>
bool operator>(const rekord<typ1,typ2> & r,const rekord<typ1,typ2> & r2){

  if(r.wartosc>r2.wartosc){return true;}
  return false;
}

template <class typ1,class typ2>
bool operator>(const rekord<typ1,typ2> &r,const int & x){

  if(r.wartosc>x){return true;}
  return false;
}

template <class typ1,class typ2>
bool operator<(const rekord<typ1,typ2> &r,const rekord<typ1,typ2> & r2){

  if(r.wartosc<r2.wartosc){return true;}
  return false;
}

template <class typ1,class typ2>
bool operator<(const rekord<typ1,typ2> &r,const int & x){

  if(r.wartosc<x){return true;}
  return false;
}




#endif
