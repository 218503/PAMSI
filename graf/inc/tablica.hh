#ifndef _TABLICA_HH
#define _TABLICA_HH

#include <stdio.h>
#include <iostream>
using namespace std;

/*!
 * \brief Interfejs klasy tab
 *
 */
template  <class typ>
class itab{
public:
  /*!
   * \brief Dodawanie elementu na koniec tablicy, rozszerzanie +1.
   */
  virtual void push_back(typ )=0;
  /*!
   * \brief Dodawanie elementu na koniec tablicy, rozszerzanie x2.
   */
  virtual void push_back_x2(typ )=0;
  /*!
   * \brief Dodawanie elementu na koniec tablicy, rozszerzanie +100.
   */
  virtual void push_back_fast(typ )=0;
  /*!
   * \brief Wstawianie elementu na wskazana pozycje w tablicy.
   */
  virtual void insert(typ, int)=0;
  /*!
   * \brief Usuwa elementu z poczatku tablicy i zwraca jego wartosc.
   */
  virtual typ pop_front()=0;
 
 /*!
   * \brief Usuwa element z konca tablicy i zwraca jego wartosc.
   *
   * Nie zmniejsza rozmiaru tablicy.
   */
  virtual typ pop_back()=0;
  /*!
   * \brief Usuwa element z wybranego miejsca tablicy.
   *
   * Nie zmniejsza rozmiaru tablicy.
   */
  virtual typ pop_position(int)=0;
  /*!
   * \brief Usuwa wybrany element z tablicy i wstawienia w jego miejsce 0
   *
   * Nie zmniejsza rozmiaru tablicy.
   */
  virtual typ pop_0(int)=0;
  /*!
   * \brief Zwraca rozmiar tablicy.
   */
  virtual int size()=0;
  /*!
   * \brief Usuwa tablice.
   */
  virtual void remove()=0;
  /*!
   * \brief Wyswielta tablice w konsoli.
   */
  virtual void display()=0;
  /*!
   * \brief Sprawdza czy tablica jest pusta.
   */
  virtual bool is_empty()=0;
  /*!
   * \brief Zamienia dwa elementy miejscami.
   */

  virtual bool search(int)=0;
  virtual void swap(int , int)=0;
  /*!
   * \brief Szybkie sortowanie tablicy.
   */
  virtual void QS(int left, int right)=0;
  /*!
   * \brief Sortowanie babelkowe tablicy.
   */
  virtual void BS()=0;

};


template <class typ>
class tab : public itab<typ>{
private:
  typ *wsk=NULL; /*!< Tablica do ktorej beda zapisywane elementy. */
  unsigned int l_elementow=0; /*!< Liczba elementow w tablicy. */
  unsigned int rozmiar_tablicy=5; /*!< Rozmiar zaalokowanej pamieci.*/
public:
  /*!
   * \brief Konstruktor bezparametryczny.
   */
  tab(){  
    l_elementow=0;
    wsk=new typ[5];}

  /*!
   * \brief Konstruktor parametryczny.
   */
  tab(int x){
    wsk=new typ[x];
  }

  /*!
   * \brief Wstawia element na koniec tablicy.
   */
  virtual void push_back(typ element);
  /*!
   * \brief Dodawanie elementu na koniec tablicy, rozszerzanie x2.
   */
  virtual void push_back_x2(typ element);

  /*!
   * \brief Dodawanie elementu na koniec tablicy, rozszerzanie +100.
   */
  virtual void push_back_fast(typ element);

  /*!
   * \brief Dodawanie elementu na wskazana pozycje.
   */
  virtual void insert(typ element, int pozycja );

  /*!
   * \brief Usuwa element z poczatku listy i zwraca jego wartosc.
   */
  virtual typ pop_front();
  /*!
   * \brief Usuwa element z konca listy i zwraca jego wartosc.
   *Nie zmienia zaalokowanej pamieci.
   */
  virtual typ pop_back();

  /*!
   * \brief Usuwa element z wybranej pozycji i zwraca jego wartosc.
   * Nie zmnienia zaalokowanej pamieci.
   */
  virtual typ pop_position(int pozycja);

  /*!
   * \brief Usuwa element ze wskazanej pozycji, zwraca jego wartosc, wstawia na jego miejsce 0. 
   * Nie zmnienia zaalokowanej pamieci.
   */
  virtual typ pop_0(int pozycja);


  /*!
   * \brief Zwraca rozmiar tablicy.
   */
  virtual int size();
  /*!
   * \brief Usuwa tablice.
   */
  virtual void remove();

  /*!
   * \brief Wyswietla tablice
   */
  virtual void display();

  /*!
   * \brief Sprawdza czy tablica jest pusta.
   */
  virtual bool is_empty();


  virtual bool search(int s);

  /*!
   * \brief Zamienia wskazane elementy miejscami.
   */
  virtual void swap(int x1, int x2);

  /*!
   * \brief Sortowanie szybkie tablicy.
   */
  virtual void QS(int left, int right);

  /*!
   * \brief Sortowanie babelkowe tablicy.
   */
  virtual void BS();

};


template <class typ>
void tab<typ>::push_back(typ element){
    
    if(l_elementow<5){
      wsk[l_elementow]=element;
      l_elementow++;
    }
      else { 
	typ *tablica=NULL; //tablica pomocnicza 
	int j;
	tablica=new typ[l_elementow];
	for(j=0;j<l_elementow;j++){ tablica[j]=wsk[j];}
	delete [] wsk;
       	wsk=new typ[l_elementow+1];
	for(j=0;j<l_elementow;j++){ wsk[j]=tablica[j]; }
	delete [] tablica;
	wsk[l_elementow]=element;
   	l_elementow++;
      }
}


template <class typ>
void tab<typ>::push_back_x2(typ element){
  typ *tablica=NULL; //tablica pomocnicza 
  int j;
    if(l_elementow<5){
      wsk[l_elementow]=element;
      l_elementow++;
    }
    else { 
      if(l_elementow<rozmiar_tablicy){
	wsk[l_elementow]=element;
	l_elementow++;
      }
      else{
	tablica=new typ[l_elementow];
	for(j=0;j<l_elementow;j++){ tablica[j]=wsk[j];}
	delete [] wsk;
	rozmiar_tablicy*=2;
	wsk=new typ[rozmiar_tablicy];
	for(j=0;j<l_elementow;j++){
	  wsk[j]=tablica[j]; 
	}
	wsk[l_elementow]=element;
	l_elementow++;
      }
    }
}



  
template <class typ>
void tab<typ>::push_back_fast(typ element){
  typ *tablica; //tablica pomocnicza 
  int j;
  
  if(l_elementow<5){
    wsk[l_elementow]=element;
    l_elementow++;
  }
  else{
   if(l_elementow<rozmiar_tablicy){
	wsk[l_elementow]=element;
	l_elementow++;
   }
   else{
     tablica=new typ[l_elementow];
     for(j=0;j<l_elementow;j++){ tablica[j]=wsk[j];}
     rozmiar_tablicy+=100;
     delete [] wsk;
     wsk=new typ[rozmiar_tablicy];
     for(j=0;j<l_elementow;j++){
       wsk[j]=tablica[j]; 
     }	       
     wsk[l_elementow]=element;
     delete [] tablica;
     l_elementow++;
   }   
  }
}

template <class typ>
void tab<typ>::insert(typ element, int pozycja){
  typ *tablica=new typ[rozmiar_tablicy+1];
  int i;
  if(pozycja<=rozmiar_tablicy){
    for(i=0;i<rozmiar_tablicy;i++){
      tablica[i]=wsk[i];
    }
    delete [] wsk;
    wsk=new typ[rozmiar_tablicy+1];
    rozmiar_tablicy++;
    for(i=0;i<pozycja;i++){
      wsk[i]=tablica[i];}
    wsk[pozycja]=element;
    for(i=pozycja+1;i<rozmiar_tablicy;i++){
      wsk[i]=tablica[i-1];}
    l_elementow++;
    delete [] tablica;
  }
}


//usuwanie elementu z poczatku tablicy bez zmieniania zaalokowanej pamieci
template <class typ>
typ tab<typ>::pop_front(){
  int i;
  typ front=wsk[0];
  for(i=0;i<l_elementow;i++){
    wsk[i]=wsk[i+1];
  }
  l_elementow-=1;
  return front;
}

//usuwanie elementu z konca tablicy bez zmieniania zaalokowanej pamieci
template <class typ>
typ tab<typ>::pop_back(){
  typ pom=wsk[l_elementow-1];
  wsk[l_elementow-1]=0;
  l_elementow-=1;

  return pom;}

template <class typ>
typ tab<typ>::pop_position(int pozycja){
  typ element;
  int i;
  element=wsk[pozycja];
  for(i=pozycja;i<rozmiar_tablicy-1;i++){
    wsk[i]=wsk[i+1];}
  return element;
}

template <class typ>
typ tab<typ>::pop_0(int pozycja){
  typ element=wsk[pozycja];
  wsk[pozycja]=0;
  return element;
}

template <class typ>
int tab<typ>::size(){
  return l_elementow;
}

//usuwaine tablicy, zwalnianie pamięci
template <class typ>
void tab<typ>::remove(){
  l_elementow=0;
  rozmiar_tablicy=5;
  delete [] wsk;
  wsk=new typ[5];
  }


//wypisanie tablicy na ekranie w rzędach po 20 liczb
template <class typ>
void tab<typ>::display(){
  int j;
  for(j=0;j<l_elementow;j++){
    if(j<l_elementow) cout<<wsk[j]<<"  "; 
    if(j%15==0)   cout<<endl;
  }
  cout<<endl;
}

template <class typ>
bool tab<typ>::is_empty(){
  
  if(l_elementow==0) { return true;}
  return false;
}

template <class typ>
bool tab<typ>::search(int s){
  
  for(int i=0;i<l_elementow;i++){
    if(wsk[i]==s) {return true;
    }
  }
  return false;
}


template <class typ>
void tab<typ>::swap(int x1, int x2){
  typ zm=wsk[x1];
  wsk[x1]=wsk[x2];
  wsk[x2]=zm;

}

template <class typ>
void tab<typ>::QS(int left, int right){
  int i=left;
  int j=right;
  typ x=wsk[(left+right)/2];

  do
    {
      while(wsk[i]<x)
	{i++;};
      while(wsk[j]>x)
	{j--;};
      if(i<=j){
	swap(i,j);
	i++;
	j--;
      }
    } while(i<=j);  
  if(left<j){
    QS(left,j);}
  
  if(right>i) {
    QS(i,right);}
}


template <class typ>
void tab<typ>::BS(){
  int i,j;
  for(i=0;i<l_elementow;i++)
    {
      for(j=0;j<(l_elementow-1);j++){
	if(wsk[j]>wsk[j+1]){
	  swap(j,j+1);
	}
      }
    }
}

#endif
