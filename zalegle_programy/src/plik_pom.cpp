#include <iostream>



using namespace std;

class klasa{
public:
  int *w,l;
  int *tab=new int[l];
  
  klasa(int liczba){l=liczba;}
  
};



int main(){
  
  int *wsk;
  int a=10;
  int *tab=new int[3];
  wsk=&a;
  tab[0]=11;
  tab[1]=a;
  tab[2]=*wsk+20;
 
  cout<<"wsk="<<wsk<<"   *wsk="<<*wsk<<endl;
  cout<<"a="<<a<<endl;

  cout<<"tab[0]= "<<tab[0]<<endl;
  cout<<"tab[1]= "<<tab[1]<<endl;
  cout<<"tab[2]= "<<tab[2]<<endl;


  cout<<endl<<"----------------------------------------"<<endl<<endl;
  
  wsk=tab;
  cout<<"wsk="<<wsk<<"    *wsk="<<wsk[2]<<endl;
  
  cout<<endl<<"----------------------------------------"<<endl<<endl;

  int e=10;
  klasa k(e);

  k.w=tab;
    
  cout<<"Klasa.w"<<endl;
  cout<<k.w[0]<<endl;
  cout<<k.w[1]<<endl;
  cout<<k.w[2]<<endl;
  cout<<"liczba="<<k.l<<endl;
  
  delete [] tab;
  cout<<"Klasa.w"<<endl;
  cout<<k.w[0]<<endl;
  cout<<k.w[1]<<endl;
  cout<<k.w[2]<<endl;
  cout<<"liczba="<<k.l<<endl;
  return 0;
}
