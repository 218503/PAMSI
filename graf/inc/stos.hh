#ifndef _STOS_HH
#define _STOS_HH

#include "tablica.hh"


template <class typ>
class istos{
public:
  /*!
   * \brief Zdejmuje element ze stosu i zwraca jego wartosc.
   */
  virtual typ pop()=0; 

  /*!
   * \brief Wstawia element na poczatek stosu.
   */
  virtual void push(typ)=0;

  /*!
   * \brief Zwraca rozmiar stosu.
   */
  virtual int size()=0;

  /*!
   * \brief Sprawdza czy stos jest pusty.
   */
  virtual bool empty()=0; 

  /*!
   * \brief Wyswietla stos.
   *
   */
  virtual void display()=0;

  /*!
   * \brief Usuwa stos. 
   *
   */
  virtual void remove()=0;
};


template <class typ>
class stos : public istos<typ>{

private:
  itab<typ> * tabl=new tab<typ>;
public:
  /*!
   * \brief Zdejmuje element ze stosu i zwraca jego zawartosc.
   */
  virtual typ pop();

  /*!
   * \brief Wstawia element na stos.
   *
   * \param[in] element element do wstawienia na stos.
   */
  virtual void push(typ element);

  /*!
   * \brief Zwraca rozmiar stosu.
   */
  virtual int size();

  /*!
   * \brief Zwraca informacje czy stos jest pusty.
   *
   * \return true jesli stos jest pusty, false jesli nie jest.
   */
  virtual bool empty();
  /*!
   * \brief Wyswietla stos.
   *
   */
  virtual void display();
  /*!
   * \brief Usuwa stos
   *
   */
  virtual void remove();

  stos(){
    tabl=new tab<typ>;
  }
  
  stos(int a){
    tabl=new tab<typ>(a);
  }
};

template <class typ>
typ stos<typ>::pop(){
  return tabl->pop_back();
}

template <class typ>
void stos<typ>::push(typ element){
  tabl->push_back_x2(element);
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


