#ifndef _LISTA_HH
#define _LISTA_HH

#include "tablica.hh"

template <class typ>
class ilista{
  public:
  virtual void push_front(typ)=0;
  virtual void push_back(typ)=0;
  virtual void insert(typ,int)=0;
  virtual void pop_front(typ)=0;
  virtual void pop_back(typ)=0;
  virtual bool empty()=0;
  virtual int size()=0;
};


template <class typ>
class lista : public ilista<typ> {
private:
  itab<typ> * tabl=new tab<typ>;
public:
  virtual void push_front(typ);
  virtual void push_back(typ);
  virtual void insert(typ,int);
  virtual typ pop_front();
  virtual typ pop_back();
  virtual bool empty(); 
  virtual int size();
};

template <class typ>
void lista<typ>::push_front(typ element){
  tabl->push_front(element);
}

template <class typ>
void lista<typ>::push_back(typ element){
  tabl->push_back(element);
}

template <class typ>
void lista<typ>::insert(typ element,int pozycja){
  tabl->insert(element,pozycja);
}

template <class typ>
typ lista<typ>::pop_front(){
  return tabl->pop_front();
}

template <class typ>
typ lista<typ>::pop_back(){
  return tabl->pop_back();
}

template <class typ>
bool lista<typ>::empty(){
  return tabl->is_empty;
}

template <class typ>
int lista<typ>::size(){
  return tabl->size();
}

#endif
