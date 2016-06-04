#ifndef GRA_HH
#define GRA_HH
#include <iostream>
#include <gtk/gtk.h>
using namespace std;


class gra{

public:
  char t[9],gracz,wybor;
  int counter=0;
  
  // Funkcja zwraca true, jeśli nastąpiła
  // wygrana danego zawodnika
  //-------------------------------------
  bool wygrana(char t[],char g)
  {
    bool test;
    int i;
    
    test=false; // Zmienna przyjmuje true, jeśli zawodnik ma trzy figury
    // w wierszu, kolumnie lub na przekątnych
    
    // Sprawdzamy wiersze
    for(i=0;i<=6;i+=3) 
      test=test||((t[i]==g)&&(t[i+1]==g)&&(t[i+2]==g));
    
    // Sprawdzamy kolumny  
    for(i=0;i<=2;i++)
      test=test||((t[i]==g)&&(t[i+3]==g)&&(t[i+6]==g));
    
    // Sprawdzamy przekątną 1-5-9
    test=test||((t[0]==g)&&(t[4]==g)&&(t[8]==g));
    
    // Sprawdzamy przekątną 3-5-7
    test=test||((t[2]==g)&&(t[4]==g)&&(t[6]==g));
    
    if(test)
      {
   	    //plansza(t);
	    //if(g=='O') system("echo 'Player wins' | festival --tts");
	    //if(g=='X') system("echo 'Computer wins' | festival --tts");
	    //cout << "\nGRACZ " << g << " WYGRYWA!!!\n\n";	  
	return true;
      }
    return false;
  }
  
  // Funkcja zwraca true, jeśli na planszy nie ma już
  // żadnego wolnego pola na ruch.
  //-------------------------------------------------
  bool remis(char t[])
  {
    // Jeśli napotkamy spację, to plansza posiada wolne pola - zwracamy false  
    
    for(int i=0;i<=8;i++)
      if(t[i]==' ')
	return false;
    
    // Jeśli pętla for zakończyła się normalnie, to na żadnym polu planszy nie było
    // spacji. Mamy do czynienia z remisem - zwracamy true
   
	//system("echo 'Tie' | festival --tts");
	//plansza(t);
	//cout << "\nREMIS !!!\n\n";

    return true;     
  }
  
  // Algorytm rekurencyjny MINIMAX
  // Do algorytmu wchodzimy z planszą, na której ustawione jest pole
  // bieżącego gracza. Parametr gracz przekazuje literkę gracza, a
  // parametr mx przekazuje jego wynik w przypadku wygranej
  //----------------------------------------------------------------
  int minimax(char t[],char gracz,int poziom,int licznik)
  {
    int m, mmx;

    // Najpierw sprawdzamy, czy bieżący gracz wygrywa na planszy. Jeśli tak, to
    // zwracamy jego maksymalny wynik
    
    if(wygrana(t,gracz)) 
      return (gracz=='X')?1:-1;
    
    // Następnie sprawdzamy, czy nie ma remisu. Jeśli jest, zwracamy wynik 0
    
    if(remis(t)) 
      return 0;
    
    // Będziemy analizować możliwe posunięcia przeciwnika. Zmieniamy zatem
    // bieżącego gracza na jego przeciwnika

    gracz=(gracz=='X')?'O':'X';
    
    // Algorytm MINIMAX w kolejnych wywołaniach rekurencyjnych naprzemiennie analizuje
    // grę gracza oraz jego przeciwnika. Dla gracza oblicza maksimum wyniku gry, a dla
    // przeciwnika oblicza minimum. Wartość mmx ustawiamy w zależności od tego, czyje
    // ruchy analizujemy:
    // X - liczymy max, zatem mmx <- -10
    // O - liczymy min, zatem mmx <-  10
    
    mmx=(gracz=='O')?10:-10;
    
    // Przeglądamy planszę szukając wolnych pół na ruch gracza. Na wolnym polu ustawiamy
    // literkę gracza i wyznaczamy wartość tego ruchu rekurencyjnym wywołaniem
    // algorytmu MINIMAX. Planszę przywracamy i w zależności kto gra:
    // X - wyznaczamy maximum
    // O - wyznaczamy minimum
    if(counter!=0){
      licznik=licznik+1;
    }
    else{
      licznik=1; 
      counter++;
    }

    if((poziom==0)||((poziom!=0)&&(licznik<3))){
      for(int i=0;i<=8;i++){	
	if((t[i] == ' '))
	  {
	    t[i]=gracz;
	    m=minimax(t,gracz,poziom,licznik);
	    t[i]=' ';
	    if(((gracz=='O')&&(m<mmx))||((gracz=='X')&&(m>mmx)))mmx=m;
	  }
      }
    }
    return mmx;
  }
  
  // Funkcja wyznacza ruch dla komputera.
  //------------------------------------
  int komputer(char t[],int poziom)
  {
    int ruch,i,m,mmx;
    
    mmx=-10;
    for(i=0;i<=8;i++)
      if(t[i]==' ')
	{
	  t[i]='X';
	  m=minimax(t,'X',poziom,0);
	  t[i]=' ';
	  if(m>mmx)
	    {
	      mmx=m; 
	      ruch=i;     
	    }        
	}    
    return ruch;
  }
  
  int od_nowa(){
    for(int i=0;i<9;i++){
      t[i]=' ';
    }
    return 0;
  }
 };

#endif
