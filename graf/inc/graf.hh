#ifndef GRAF_HH
#define GRAF_HH

#include "lista.hh"
#include "tablica.hh"
#include "irunn.hh"
#include <cstdlib>
#include <ctime>

#define RD 10 //Rozmiar Grafu

using namespace std;
// typedef ilista<int> illista;
// typedef lista<int> llista;


// class wierzcholek{
// public:
//   ilista<int> *lista_sasiadow=new lista<int>;
//   int zawartosc;
//   wierzcholek &operator=(const wierzcholek &w);
//   wierzcholek &operator=(const int &x);

// };

class krawedz{
public:
  int waga=1;
  int kierunek;
  krawedz & operator = (const int & x);
  krawedz(){
    waga=0;
    kierunek=0;
  }
  krawedz(int x,int y){
    waga=y;
    kierunek=x;
  }
};


class igraf{
public:
  virtual void dodaj_wierzcholek()=0;
  virtual void dodaj_krawedz(int,int,int )=0;
  //virtual void usun_wierzcholek()=0;
  virtual void sasiadujace_wierzcholki(int )=0;
  virtual void sasiadujace_krawedzie(int )=0;
  virtual int size()=0;
};

class graf : public igraf{
  int k;
  lista<krawedz> *w; 
  int max=0;
  int lw;
public:
  virtual void dodaj_wierzcholek();
  virtual void dodaj_krawedz(int w1, int w2, int waga);
  //virtual void usun_wierzcholek();
  virtual void sasiadujace_wierzcholki(int nr);
  virtual void sasiadujace_krawedzie(int nr);
  virtual int size();
  graf(int m){
    srand(time(NULL));
    lw=0;
    max=m;
    w=new lista<krawedz>[RD];
     }
};


void graf::dodaj_wierzcholek(){
  lista<krawedz> *p=new lista<krawedz>[lw+1]; 
  if(lw<RD){
    for(int j=0;j<lw;j++){
      for(int i=0;i<w[j].size();i++){
	p[j]=w[j];
      }
    }  
    delete [] w;
    lw++;
    w=new lista<krawedz>[lw+1];
    for(int j=0;j<lw;j++){
      for(int i=0;i<p[j].size();i++){
	w[j]=p[j];	
      }
    }
    delete [] p;
  }
}


void graf::dodaj_krawedz(int w1, int w2,int waga){
  // int x;
  // for(int i=0;i<w[w1].size();i++){
  //   x=w[w1]
  //   if(x!=w1)
  if(!w[w1].search(w2)){
  krawedz k(w2,waga);
  w[w1].push_back(k);
  }
  if(!w[w2].search(w1)){
  krawedz k2(w1,waga);
  w[w2].push_back(k2);
  }
}


void graf::sasiadujace_wierzcholki(int nr){
  

}


void graf::sasiadujace_krawedzie(int nr){
  cout<<"Sasiedzi wierzcholka nr "<<nr<<" :"<<endl;
  w[nr].display();
  cout<<"______________________________"<<endl;
}

int graf::size(){
  return lw;
}

ostream & operator<<(ostream & ekran, krawedz & k){
  ekran<<k.kierunek;
  return ekran;

}

bool operator>(const krawedz &k,const int & x){

  if(k.kierunek>x){return true;}
  return false;
}

bool operator<(const int & x,const krawedz &k){

  if(k.kierunek<x){return true;}
  return false;
}

bool operator>(const krawedz &k1,const krawedz & k2){
  if(k1.kierunek>k2.kierunek){return true;}
  return false;
}

bool operator<(const krawedz &k1,const krawedz & k2){
  if(k1.kierunek<k2.kierunek){return true;}
  return false;
}

krawedz & krawedz::operator = (const int & x){
  kierunek=x;
  return *this;
}

bool operator==(const krawedz &k, const int &x){
  if(k.kierunek==x) {return true;}
  return false;
}

// wierzcholek & wierzcholek::operator = (const int & x){
//   zawartosc=x;
//   return *this;
// }

// wierzcholek &wierzcholek::operator = (const wierzcholek & ww){
//   zawartosc=ww.zawartosc;
//   lista_sasiadow->push_back(ww.lista_sasiadow->pop_front());
//   return *this;
// }


// ostream & operator<<(ostream & ekran, wierzcholek & w){
//   ekran<<"Zawartosc = "<<w.zawartosc<<endl;
//   ekran<<"Sasiedzi: "<<endl;
//   w.lista_sasiadow->display();
//   return ekran;
// }


// bool operator>(const wierzcholek & w,const wierzcholek & w2){

//   if(w.zawartosc>w2.zawartosc){return true;}
//   return false;
// }

// bool operator>(const wierzcholek &w,const int & x){

//   if(w.zawartosc>x){return true;}
//   return false;
// }

// bool operator<(const wierzcholek &w,const wierzcholek & w2){

//   if(w.zawartosc<w2.zawartosc){return true;}
//   return false;
// }

// bool operator<(const wierzcholek &w,const int & x){

//   if(w.zawartosc<x){return true;}
//   return false;
// }




class test_grafu : public irunable{
private:
  igraf *g=new graf(RD);
  int liczba_wierzcholkow=0;
  
public:
  void dodaj_wierzcholki(int l);
  void polacz();
  virtual bool prepare(int);
  virtual bool run();

};

void test_grafu::dodaj_wierzcholki(int l){
  for(int w=0;w<l;w++){
    g->dodaj_wierzcholek();}
}

void test_grafu::polacz(){
  for(int i=0;i<liczba_wierzcholkow;i++){
    for(int j=0;j<3;j++){
      g->dodaj_krawedz(i,rand()%10,1);
    }
  }
}


bool test_grafu::prepare(int l){
  srand(time(NULL));
  liczba_wierzcholkow=l;
  dodaj_wierzcholki(l);
  polacz();
  return true;
}



bool test_grafu::run(){

  cout<<"--OGOLEM--"<<endl;
  for(int i=0;i<g->size();i++){
    g->sasiadujace_krawedzie(i);  
  }
  g->dodaj_krawedz(1,4,1);
  cout<<"Dodano krawedz"<<endl;
  cout<<"--OGOLEM--"<<endl;
  for(int i=0;i<g->size();i++){
    g->sasiadujace_krawedzie(i);  
  }
   return true;
}
#endif
