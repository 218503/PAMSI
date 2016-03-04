//tablice dynamiczne, 5 elementow podstawa, powyzej alokacja dynamiczna
#include <iostream>
#include <string>


using namespace std;

int wyswietl(int *tab,int n){
  int i;
  cout<<"Zawartosc:"<<endl;
  for(i=0;i<n;i++)
    { 
      cout<<tab[i]<<endl;
    }
  return 0;
}

int dodaj(int el, int *tab, int & licznik){
  int i;
  if (licznik<=5) { 
    tab[licznik]=el;
    ++licznik;}
  else{
    int *tab_pom=new int[licznik];
    for(i=0;i<licznik;i++){
      tab_pom[i]=tab[i];
    }

    int *tablica=new int[licznik+1];
    for(i=0;i<licznik;i++){
      tab[i]=tab_pom[i];}
    
    tab[licznik]=el;
    tab=tablica;
    ++licznik;
    delete tab_pom;
    
  }
    return 0;
}

int kopiuj(int *tab, int licznik){
  
  return 0;
}

int main()
{
  int z;
  int licznik=0; //licznik elementow w tablicy
  int element;
  int * tablica= new int[5];
  int k=0;
  do {
  cout<<"Menu:"<<endl;
  cout<<"1 - Dodaj element"<<endl;
  cout<<"2 - Wyswietl tablice"<<endl;
  cout<<"0 - End"<<endl;
  cin>>z;
  switch(z){
  case 1:{
    cout<<"Ile elementow?"<<endl;
    cin>>k;
    cout<<"wprowadz elementy (LICZBY)"<<endl;
    for(int i=0;i<k;i++){
    
    cin>>element;
    dodaj(element,tablica,licznik);
    }
    cout<<"licznik= "<<licznik<<endl;
    //dodawanie elementu
    break;}
  case 2:{ wyswietl(tablica,licznik); break;}
     
  case 0:{
    cout<<"Zamykanie"<<endl;
    break;}
    
  default: cout<<"Blad! Nie ma takiej opcji :("<<endl;
  }}
  while(z!=0);

  return 0;
}
