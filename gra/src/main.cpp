#include <iostream>
#include <stdio.h>
#include "gra.hh"
#include <gtk/gtk.h>

using namespace std;

int poziom=3;
bool flaga=0;
GtkWidget *okno;
GtkWidget *tablica;
GtkWidget *przycisk[12];
gra g;

void zmien_0(GtkWidget *widzet){
  if((g.t[0]==' ')&&(!flaga)){ 
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[0]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){      
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");

    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);

  }
}

void zmien_1(GtkWidget *widzet){
  if((g.t[1]==' ')&&(!flaga)) {
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[1]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");	
    
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);

  }
}

void zmien_2(GtkWidget *widzet){
  if((g.t[2]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[2]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' '))  g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");

    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);

  }
}
void zmien_3(GtkWidget *widzet){
  if((g.t[3]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[3]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);
  }
}

void zmien_4(GtkWidget *widzet){
  if((g.t[4]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[4]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' '))  g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);
  }
}

void zmien_5(GtkWidget *widzet){
  if((g.t[5]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[5]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){ 
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);
  }
}

void zmien_6(GtkWidget *widzet){
  if((g.t[6]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[6]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X')||g.wygrana(g.t,'O')||g.remis(g.t);
  }
}

void zmien_7(GtkWidget *widzet){
  if((g.t[7]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[7]='O';
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' '))  g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);
  }
}

void zmien_8(GtkWidget *widzet){
  if((g.t[8]==' ')&&(!flaga)){
    gtk_button_set_label( GTK_BUTTON(widzet), "O" );
    g.t[8]='O'; 
    if(!(g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t))){
      int r=g.komputer(g.t,poziom);
      if((r >= 0) && (r <= 8) && (g.t[r] == ' ')) g.t[r]='X';
      gtk_button_set_label(GTK_BUTTON(przycisk[r]),"X");
    }
    flaga=g.wygrana(g.t,'X') || g.wygrana(g.t,'O') || g.remis(g.t);

  }
}


void ustaw_poziom_3(GtkWidget *widzet){
  poziom=3;
}

void ustaw_poziom_0(GtkWidget *widzet){
  poziom=0;
}

void resetuj(GtkWidget *widzet){
  flaga=0;
  for(int i=0;i<9;i++) gtk_button_set_label(GTK_BUTTON(przycisk[i])," ");
  g.od_nowa();  
}



int main(int argc, char *argv[]){
  int i=0;
  gtk_init (&argc,&argv);
  //wyczyszczenie pola gry
  g.od_nowa();
  
  //ustawienie parametrow okna
  okno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(okno), 300, 300);
  gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
  g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_window_set_title (GTK_WINDOW(okno), "Kolko i krzyzyk");
  
  gtk_container_set_border_width(GTK_CONTAINER(okno), 5);

  tablica = gtk_table_new(4, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(tablica), 2);
  gtk_table_set_col_spacings(GTK_TABLE(tablica), 2);
  //dodanie przyciskow z polem tekstowym
  for(i=0;i<9;i++) przycisk[i] = gtk_button_new_with_label(" ");
  przycisk[9]=gtk_button_new_with_label("Łatwy");
  przycisk[10]=gtk_button_new_with_label("Trudny");
  przycisk[11]=gtk_button_new_with_label("Resetuj");
  
  //deklaracja jaka funkcja ma zostac wywolana po nacisnieciu przycisku
  g_signal_connect(przycisk[0], "clicked", G_CALLBACK(zmien_0), NULL);
  g_signal_connect(przycisk[1], "clicked", G_CALLBACK(zmien_1), NULL);
  g_signal_connect(przycisk[2], "clicked", G_CALLBACK(zmien_2), NULL);
  g_signal_connect(przycisk[3], "clicked", G_CALLBACK(zmien_3), NULL);
  g_signal_connect(przycisk[4], "clicked", G_CALLBACK(zmien_4), NULL);
  g_signal_connect(przycisk[5], "clicked", G_CALLBACK(zmien_5), NULL);
  g_signal_connect(przycisk[6], "clicked", G_CALLBACK(zmien_6), NULL);
  g_signal_connect(przycisk[7], "clicked", G_CALLBACK(zmien_7), NULL);
  g_signal_connect(przycisk[8], "clicked", G_CALLBACK(zmien_8), NULL);
  g_signal_connect(przycisk[9], "clicked", G_CALLBACK(ustaw_poziom_3), NULL);
  g_signal_connect(przycisk[10], "clicked", G_CALLBACK(ustaw_poziom_0),NULL);
  g_signal_connect(przycisk[11], "clicked", G_CALLBACK(resetuj),NULL);

  //dodanie przyciskow do kontenera tablica
  for (int x = 0; x < 3; x++)
    for (int y = 0; y < 4; y++)
      gtk_table_attach_defaults (GTK_TABLE(tablica), przycisk[(y*3)+x], x, x+1, y, y+1);
  gtk_container_add(GTK_CONTAINER(okno), tablica); 
  gtk_widget_show_all(okno);
  gtk_main();

  return 0;
}
