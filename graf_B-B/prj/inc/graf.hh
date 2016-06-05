#ifndef GRAF_HH
#define GRAF_HH

#include "lista.hh"
#include "tablica.hh"
#include "kolejka.hh"
#include "irunn.hh"
#include "stos.hh"
#include <cstdlib>
#include <ctime>

using namespace std;


/*!
 * \brief Klasa definiująca krawedz
 *
 */
class krawedz{
public:
  int waga=1; /*!< Waga krawedzi. */
  int kierunek; /*!< Wierzcholek do ktorego prowadzi krawedz. */
  krawedz & operator = (const int & x);

  krawedz(){
    waga=1;
    kierunek=0;
  }
  krawedz(int x,int y){
    waga=y;
    kierunek=x;
  }
};

/*!
 * \brief Interfejs klasy graf.
 *
 */
class igraf{
public:
  /*!
   * \brief Dodawanie wierzcholka do grafu.
   *
   */
  virtual void dodaj_wierzcholek()=0;
  /*!
   * \brief Dodawaine krawedzi do wierzcholka.
   *
   */
  virtual void dodaj_krawedz(int,int,int )=0;
  //  virtual void usun_wierzcholek()=0;
  //  virtual void sasiadujace_wierzcholki(int )=0;
  /*!
   * \brief Wypisanie sasiadujacych z wierzcholkiem krawedzi.
   *
   */
  virtual void sasiadujace_krawedzie(int )=0;
  /*!
   * \brief Zwraca liczbe wierzcholkow z jaka sasiaduje wierzcholek.
   *
   */
  virtual int liczba_sasiadow(int )=0;
  /*!
   * \brief Zwraca wybranego sasiada z listy sasiadow danego wierzcholka.
   *
   */
  virtual int sasiad(int, int)=0;
  /*!
   * \brief Zwraca rozmiar drzewa.
   *
   */
  virtual int size()=0;

  /*!
   * \brief 
   */
  virtual void remove()=0;
};



/*!
 * \brief Klasa graf.
 *
 */
class graf : public igraf{
  int k; 
  lista<krawedz> *w; /*!< Tablica list krawedzi, indeks tablicy jest rownoczesnie numerem wierzcholka */
  int max=0; /*!< Maksymalna zdefiniowana liczba wierzcholkow, dla ktorych zostala zaalokowana pamiec  */
  int lw=0; /*!< Aktualna liczba wierzcholkow w grafie */
public:
  /*!
   * \brief Dodaje wierzcholek.
   *
   */
  virtual void dodaj_wierzcholek();
  /*!
   * \brief Dodaje krawedz miedzy wskazanymi  wiercholkami.
   *
   * \param[in] w1 numer pierwszego wierzcholka.
   * \param[in] w2 numer drugiego wierzcholka.
   * \param[in] waga waga krawedzi.
   */
  virtual void dodaj_krawedz(int w1, int w2, int waga);
  //virtual void usun_wierzcholek();
  // virtual void sasiadujace_wierzcholki(int nr);
  /*!
   * \brief Wypisuje sasiadujace krawedzie wiercholka nr.
   *
   */
  virtual void sasiadujace_krawedzie(int nr);
  /*!
   * \brief Zwraca ile sasiadow ma dany wierzcholek.
   *
   * \param[in] i numer wierzcholka dla ktorego sprawdzamy liczbe sasiadow.
   */
  virtual int liczba_sasiadow(int i);
  /*!
   * \brief Zwraca numer sasiedniego wierzcholka znajdujacego sie na liscie na pozycji i wierzcholka nr.
   *
   * \param[in] nr numer wierzcholka, ktorego sasiada wybieramy.
   * \param[in] i numer na liscie.
   */
  virtual int sasiad(int nr,int i);
  /*!
   * \brief Zwraca rozmiar grafu
   *
   */
  virtual int size();

  /*!
   * \brief 
   */
  virtual void remove(){
    delete [] w;
  }

  graf(int a){
    srand(time(NULL));
    lw=0;
    max=a;
    delete []w;
    w=new lista<krawedz>[a];
  }

  
};


void graf::dodaj_wierzcholek(){
  // lista<krawedz> *p=new lista<krawedz>[lw+1]; 
  if(lw<max){
    // for(int j=0;j<lw;j++){
    //     for(int i=0;i<w[j].size();i++){
    // 	p[j]=w[j];
    // 		}
    // }  
    // delete [] w;
    // lw++;
    // w=new lista<krawedz>[lw+1];
    // for(int j=0;j<lw;j++){
    //    for(int i=0;i<p[j].size();i++){
    // 	w[j]=p[j];	
    // 	}
    // }

    lw++;
  }
}


void graf::dodaj_krawedz(int w1, int w2,int waga){
  if(!w[w1].search(w2)&&w1!=w2){
  krawedz k(w2,waga);
  w[w1].push_back(k);
  w[w1].BS();
  }
  if(!w[w2].search(w1)&&w1!=w2){
  krawedz k2(w1,waga);
  w[w2].push_back(k2);
  w[w2].BS();
  }
}


void graf::sasiadujace_krawedzie(int nr){
    cout<<"Sasiedzi wierzcholka nr "<<nr<<" :"<<endl;
    w[nr].display();
    cout<<"______________________________"<<endl;
}


int graf::liczba_sasiadow(int i){
  return w[i].size();
}


int graf::sasiad(int nr, int i){
  krawedz k;
  k=w[nr].check_value(i); 
  return k.kierunek;
}


int graf::size(){
  return lw;
}



/*!
 * \brief Test grafu
 *
 */
class test_grafu : public irunable{
private:
  igraf *g;
  int liczba_wierzcholkow=0,liczba_krawedzi=0;
  istos<int> *s=new stos<int>;//(liczba_wierzcholkow);
  ikolejka<int> *k;
  bool *odwiedzony;
  // int counter=0;
public:
  /*!
   * \brief Dodanie wierzcholkow do grafu.
   *
   * \param[in] l liczba wierzcholkow do dodania.
   */
  void dodaj_wierzcholki(int l); 
  /*!
   * \Laczenie wierzcholkow z wybranymi losowo innymi wierzcholkami.
   *
   */
  void polacz();
    /*!
   * \brief Przygotowanie grafu do testu.
   *
   * Tworzy graf o zadanej w konstruktorze liczbie wierzcholkow, a nastepnie losuje, ktore wierzcholki maja byc polaczone.
   */
  virtual bool prepare();
  /*!
   * \brief Test grafu.
   *
   */
  virtual bool run();

  /*!
   * \brief Zwalnia pamiec.
   *
   * 
   */
  virtual void remove();

  /*!
   * \brief Przejscie DFS.
   *
   * \param[in] o wierzcholek poczatkowy.
   */


  int DFS(int o);
  /*!
   * \brief Przejscie BFS.
   *
   * param[in] o wierzcholek poczatkowy.
   */
  int BFS(int o);
 
  // a liczba wierzcholkow, b liczba krawedzi dla wierzcholka
  /*!
   * \brief 
   */
  test_grafu(int a, int b){
    liczba_wierzcholkow=a;
    liczba_krawedzi=b;
    g=new graf(liczba_wierzcholkow);
    odwiedzony=new bool[liczba_wierzcholkow];
    for(int i=0;i<liczba_wierzcholkow;i++) odwiedzony[i]=false;
    k=new kolejka<int>[liczba_wierzcholkow];
  }
};

void test_grafu::dodaj_wierzcholki(int l){
  for(int w=0;w<l;w++){
    g->dodaj_wierzcholek();
    // if(w%10==0) cout<<w<<endl; 
  }
}

void test_grafu::polacz(){
  int kk,j,waga;
  for(int i=0;i<liczba_wierzcholkow;i++){
    j=0;
    while(j<liczba_krawedzi){

      kk=rand()%liczba_wierzcholkow;
      if((kk<liczba_wierzcholkow)&&(kk!=i)&&(g->liczba_sasiadow(kk)<liczba_krawedzi)&&(g->liczba_sasiadow(i)<liczba_krawedzi))
	{
	  waga=(rand()%9)+1;
	  g->dodaj_krawedz(i,kk,waga);
	}
      j++;
    }
  }
}

int test_grafu::DFS(int o){
  int i=0;
  odwiedzony[o]=true;
  //counter++;
  // cout<<"Odwiedzony "<<o<<endl;
  for(i=0;i<g->liczba_sasiadow(o);i++){
    s->push(g->sasiad(o,i));
  }
  while(!s->empty()){
    i=s->pop();
    if(!odwiedzony[i]) DFS(i);
  }
  return 0;
}

int test_grafu::BFS(int o){
  int i;
  //cout<<"ODWIEDZONY "<<o<<endl;
  //counter++;
  odwiedzony[o]=true;
  k->push(o);
  for(i=0;i<g->liczba_sasiadow(o);i++){
    if(!odwiedzony[g->sasiad(o,i)]) k->push(g->sasiad(o,i));
  }
  while(!k->empty()){
    k->pop();
    if(!odwiedzony[k->check_value(0)]){BFS(k->check_value(0));}
  }
  return 0;
}

bool test_grafu::prepare(){
  srand(time(NULL));
  dodaj_wierzcholki(liczba_wierzcholkow);
  cout<<"Dodano wierzcholki"<<endl;
  polacz();
  return true;
}


bool test_grafu::run(){

  // for(int i=0;i<g->size();i++){
  //   g->sasiadujace_krawedzie(i);  
  // }
  // g->dodaj_krawedz(1,4,1);
  // cout<<"Dodano krawedz"<<endl;
  // cout<<"--OGOLEM--"<<endl;
  // for(int i=0;i<g->size();i++){
  //   g->sasiadujace_krawedzie(i);  
  // }

  
  DFS(0);

  // cout<<"counter= "<<counter<<endl;
  // cout<<"g.size()= "<<g->size()<<endl;
  // if(counter==g->size())
  //   {cout<<"Graf spojny counter==g.size()"<<endl;}
  // else
  //   {cout<<"Graf niespojny counter!=g.size()"<<endl;}
  // cout<<"ODWIEDZONE:"<<endl;
  // for(int i=1;i<g->size()+1;i++) {
  //   if(odwiedzony[i-1]) cout<<i-1<<"  ";
  //   if(i%10==0) cout<<endl;}
   return true;
}

void test_grafu::remove(){

  g->remove();
  delete [] s;
  delete [] k;
  delete [] g;
  delete [] odwiedzony;
}






ostream & operator<<(ostream & ekran, krawedz & k){
  ekran<<"kierunek: "<<k.kierunek<<"  waga: "<<k.waga;
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


#endif

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
