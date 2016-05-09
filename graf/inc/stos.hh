#ifndef _STOS_HH
#define _STOS_HH

#include "tablica.hh"


template <class typ>
class istos{
public:
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
  virtual int size()=0;

  /*!
   * \brief 
   */
  virtual bool empty()=0; 
  
  virtual void display()=0;

  virtual void remove()=0;
};


template <class typ>
class stos : public istos<typ>{

private:
  itab<typ> * tabl=new tab<typ>;
public:
  /*!
   * \brief 
   */
  virtual typ pop();

  /*!
   * \brief 
   */
  virtual void push(typ element);

  /*!
   * \brief 
   */
  virtual int size();

  /*!
   * \brief 
   */
  virtual bool empty();
  
  virtual void display();

  virtual void remove();
};

template <class typ>
typ stos<typ>::pop(){
  return tabl->pop_front();
}

template <class typ>
void stos<typ>::push(typ element){
  tabl->insert(element,0); //taki "push_front"
}

template <class typ>
int stos<typ>::size(){
  return tabl->size();
}

template <class typ>
bool stos<typ>::empty(){
  return tabl->is_empty();
}


template <class typ>
void stos<typ>::display(){
  tabl->display();

}

template <class typ>
void stos<typ>::remove(){
  tabl->remove();
}
#endif


