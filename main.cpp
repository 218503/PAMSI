#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class element{
public:
  int wartosc;
  int *lewy, *prawy;
};

class drzewo{
public:
  int korzen;
  int **drz;
  int i,j,ile;

  void wypelnij(int ilosc){
    int w,k,zm=1;
    ile=ilosc;
    w=sqrt(ilosc)+1;
    cout<<"w"<<w<<"  ilosc "<<ilosc<<endl;
    drz=new int *[w];
    drz[0]=new int[1];
    drz[0][0]=ilosc/2;
    drz[1]=new int[2];
    drz[1][0]=drz[0][0]-2;
    drz[1][1]=drz[0][0]+2;
    for(i=2;i<w;i++){
      k=pow(2,i);
      drz[i]=new int[k];
      for(j=0;j<k;j++){
	drz[i][j+j]=drz[i-1][j]-2;
	drz[i][j+j+1]=drz[i-1][j]+2;
      }      
    }
  }
  

  void wypisz()
  {int i,j,w,p;
    w=sqrt(ile)+1;
    for(i=0;i<w;i++){
      p=pow(2,i);
      for(j=0;j<p;j++){
	cout<<drz[i][j]<<" ";
      }
      cout<<endl;
    }
     
  }

};

int main(){
  
  drzewo d;
  d.wypelnij(10);
  d.wypisz();
  return 0;
}
