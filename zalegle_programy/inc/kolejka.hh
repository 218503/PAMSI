#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

#include "tablica.hh"
template <class typ>
class ikolejka{
public:
  virtual bool empty()=0;
  virtual void pop(typ)=0;
  virtual void push(typ)=0;
  virtual int size()=0;
  
  
};

template <class typ>
class kolejka : public ikolejka<typ>{
private:
  itab<typ> * tabl=new tab<typ>;
public:
  virtual bool empty();
  virtual typ pop();
  virtual void push(typ);
  virtual int size();
  
};
 
template <class typ>
typ kolejka<typ>::pop(){
  return tabl->pop_front();
}
 
template <class typ>
void kolejka<typ>::push(typ element){
  tabl->push_back(element);
}
 
template <class typ>
int kolejka<typ>::size(){
  return tabl->size();
}
 
template <class typ>
bool kolejka<typ>::empty(){
  return tabl->is_empty;
}



#endif
