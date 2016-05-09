#ifndef _LISTA_HH
#define _LISTA_HH

#include "tablica.hh"

  /*!
   * \brief 
   */
template <class typ>
class ilista{
  public:
  /*!
   * \brief 
   */
  virtual void push_front(typ)=0;
   /*!
   * \brief 
   */
  virtual void push_back(typ)=0;
    /*!
   * \brief 
   */
  virtual void insert(typ,int)=0;
  /*!
   * \brief 
   */
  virtual typ pop_front()=0;
  /*!
   * \brief 
   */
  virtual typ pop_back()=0;
  /*!
   * \brief 
   */
  virtual bool empty()=0;
  /*!
   * \brief 
   */
  virtual int size()=0;
  virtual void display()=0;
  virtual void remove()=0;
};

  /*!
   * \brief 
   */
template <class typ>
class lista : public ilista<typ> {
private:
  itab<typ> * tabl=new tab<typ>;
public:
  /*!
   * \brief 
   */
  virtual void push_front(typ element);
  /*!
   * \brief 
   */
  virtual void push_back(typ element);
  /*!
   * \brief 
   */
  virtual void insert(typ element,int pozycja);
  /*!
   * \brief 
   */
  virtual typ pop_front();
  /*!
   * \brief 
   */
  virtual typ pop_back();
  /*!
   * \brief 
   */
  virtual bool empty(); 
  /*!
   * \brief 
   */
  virtual int size();
  virtual void display();
  virtual void remove();

};

template <class typ>
void lista<typ>::push_front(typ element){
  
}

template <class typ>
void lista<typ>::push_back(typ element){
  tabl->push_back_x2(element);
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
  return tabl->is_empty();
}

template <class typ>
int lista<typ>::size(){
  return tabl->size();
}


template <class typ>
void lista<typ>::display(){
  tabl->display();
}

template <class typ>
void lista<typ>::remove(){
  tabl->remove();
}
#endif

