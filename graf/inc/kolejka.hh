#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

#include "tablica.hh"


  /*!
   * \brief 
   */
template <class typ>
class ikolejka{
public:
  /*!
   * \brief 
   */
  virtual bool empty()=0;

  /*!
   * \brief 
   */
  virtual typ pop()=0;

  /*!
   * \brief 
   */
  virtual void push(typ)=0;

  /*!
   * \brief 
   */
  virtual int check_value(int)=0;
  virtual int size()=0;

  virtual void display()=0;

  virtual void remove()=0;
  
  
};

template <class typ>
class kolejka : public ikolejka<typ>{
private:
  itab<typ> * tabl;
public:
  /*!
   * \brief 
   */
  virtual bool empty();

  /*!
   * \brief 
   */
  virtual typ pop();

  /*!
   * \brief 
   */
  virtual void push(typ);

  /*!
   * \brief 
   */
  virtual int check_value(int x);
  virtual int size();

  virtual void display();
  
  virtual void remove();  
  kolejka(){
    tabl=new tab<typ>;
  }
  kolejka(int a){
    tabl=new tab<typ>(a);
  }
};
 
template <class typ>
typ kolejka<typ>::pop(){
  return tabl->pop_front();
}
 
template <class typ>
void kolejka<typ>::push(typ element){
  tabl->push_back_x2(element);
}
 


template <class typ>
int kolejka<typ>::check_value(int x){
  return tabl->return_value(x);
}
template <class typ>
int kolejka<typ>::size(){
  return tabl->size();
}
 
template <class typ>
bool kolejka<typ>::empty(){
  return tabl->is_empty();
}


template <class typ>
void kolejka<typ>::display(){
  tabl->display();

}

template <class typ>
void kolejka<typ>::remove(){
  tabl->remove();}

#endif
