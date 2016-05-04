#ifndef _DRZEWO_HH
#define _DRZEWO_HH
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "tablica.hh"



using namespace std;

class element{
public:
  element *rodzic=NULL,*lewy=NULL,*prawy=NULL;
  int zawartosc;

};

class drzewo : public element{
private:
  element *el;
public:
  itab<int> * tabl;
  int i=0,j;
  
  
  drzewo(){
    el=NULL;
  }

  element *& korzen(){
    return el;

  }
  void generator(int l){
    tabl=new tab<int>[l];
    int i,x;
    srand(time(NULL));
    for(i=0;i<l;i++){
      x=1+(rand()%10000);
      tabl->push_back_x2(x);}
    tabl->QS(0,l-1);
  }
  
  void wstaw(element *&el,int k){

    if(el==NULL){
      el=new element;
      el->zawartosc=k;
      el->lewy=NULL;
      el->prawy=NULL;
    }
    else{
      if(k>el->zawartosc){
	if((el->lewy==NULL)&&(el->prawy!=NULL)){
	  wstaw(el->lewy,el->zawartosc);
	  el->zawartosc=el->prawy->zawartosc;
	 el->prawy->zawartosc=k;}
	else{
	  wstaw(el->prawy,k);}
      }
      if(k<el->zawartosc){
	if((el->prawy==NULL)&&(el->lewy!=NULL)){
	  wstaw(el->prawy,el->zawartosc);
	  el->zawartosc=el->lewy->zawartosc;
	  el->lewy->zawartosc=k; 
	}
	else{
	  wstaw(el->lewy,k);}
      }
      
    }
  }
  
  void preorder(element *el){
    if(el!=NULL){
      cout<<el->zawartosc<<" ";
      preorder(el->lewy);
      preorder(el->prawy);
    }
  }
  
  void inorder(element *el){
  if(el!=NULL){
      inorder(el->lewy);
      cout<<el->zawartosc<<" ";
      inorder(el->prawy);
      
    }
  }

  void postorder(element *el){
    if (el!=NULL){
      postorder(el->lewy);
      postorder(el->prawy);
      cout<<el->zawartosc<<" ";
    }
  }
  
  void wypelnij(element *el){
    if(el!=NULL){
      wypelnij(el->lewy);
      el->zawartosc=tabl->pop_0(i);
      i++;
      wypelnij(el->prawy);

    }
  }

  element *wyszukaj(element *el,int k){
    if(el==NULL||el->zawartosc==k) return el;
    if(k<el->zawartosc) {
      return wyszukaj(el,k);}
    else{
      if(k>el->zawartosc){
	return wyszukaj(el,k);}
    }
    return NULL;
  }

};


#endif
