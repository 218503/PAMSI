#include <stdio.h>
#include "tablica.hh"


class komorka{
public:
  string slowo_klucz;
  int wartosc;
};

class it_a{
public: 
  virtual komorka odczyt(string)=0;
  virtual void zapis(komorka)=0;
  virtual int f_hasz(string)=0;
 
};


class t_a : public it_a{
private:
  tab<tab<komorka>> *tab_indeksow;
public: 
  virtual komorka odczyt(string);
  virtual void zapis(komorka);
  virtual int f_hasz(string slowo){
    switch(slowo[0]){
      if((slowo<=90)&&(slowo>=65)){
	return slowo[0]-65;}
    }

  }
};

t_a::f_hasz(){

  return 
}

int main(){
  int n=10; //liczba slotow
  
  
  return 0;
}


komorka operator[](tab<tab<komorka>> t_i,string kl){

  
}  



