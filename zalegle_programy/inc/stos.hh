#ifndef _STOS_HH
#define _STOS_HH

#include "tablica.hh"


template <class typ>
class istos{
public:
  virtual typ pop()=0; 
  virtual void push(typ)=0;
  virtual int size()=0;
  virtual bool empty()=0; 
};


template <class typ>
class stos : public istos<typ>{

private:
  itab<typ> * tabl=new tab<typ>;
public:
  virtual typ pop();
  virtual void push(typ element);
  virtual int size();
  virtual bool empty();
};

template <class typ>
typ stos<typ>::pop(){
  return tabl->pop_front();
}

template <class typ>
void stos<typ>::push(typ element){
  tabl->push(element);
}

template <class typ>
int stos<typ>::size(){
  return tabl->size();
}

template <class typ>
bool stos<typ>::empty(){
  return tabl->is_empty();
}

#endif


