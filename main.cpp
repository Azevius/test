// na_zaliczenie.cpp : Defines the entry point for the console application.
//

/*
Zadania na zaliczenie

 

Warunki zaliczenia:

1.      Nale¿y wybraæ tylko jedno zadanie z zakresu 3- 5

2.      Do ka¿dego programu musi byæ za³¹czony algorytm (w postaci schematu blokowego)
zapisany w pliku: *.pdf lub formacie graficznym *.jpg (czytelnym na laboratorium). 
Inne formy nie s¹ akceptowane.

3.      Wymagana jest podstawowa znajomoœæ Debugger’a (analiza zmiennych, tablic, pu³apki, edycja krok po kroku)

4.      Programy musz¹ byæ napisane z u¿yciem niezale¿nych funkcji i wskaŸników (jeœli konieczne),
nie u¿ywaæ referencji i zmiennych globalnych.

5.      Napisany program musi dzia³aæ (wa¿ny jest kod Ÿród³owy *.c lub *.cpp) w Builder6 lub Visual

6.      Program ma byæ napisany samodzielnie.

7.      Podstaw¹ zaliczenia bêdzie:

a.       oddanie dzia³aj¹cego programu,

b.      oddanie algorytmu w postaci schematu blokowego (diagramu) do napisanego programu,

c.       odpowiedŸ na postawione pytania zwi¹zane z napisanym programem i zakresem programu zajêæ z Informatyki 1,

d.      znajomoœæ Debugger’a.

8.      Nieodwo³alny termin oddania – do ostatniego dnia zajêæ w semestrze dla danej grupy zajêciowej. Oddanie programu po czasie lub programu napisanego niesamodzielnie jest równoznaczne z ocen¹ niedostateczn¹ na koniec semestru.
*/

#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*5.2. Napisz program, który wczytuj¹c dowolny plik tekstowy sporz¹dzi dla tego zbioru alfabetyczny s³ownik
wyrazów, bêdzie mo¿liwoœæ sortowania tych wyrazów (A-Z i Z-A) dwoma ró¿nymi algorytmami sortowania 
(wybór nale¿y zostawiæ u¿ytkownikowi), znajdowania najd³u¿szego i najkrótszego wyrazu, dopisywania,
kasowania oraz zapisu odczytu danych do i z pliku w postaci tabelki.*/

//void wczytaj();

int main(int argc, char* argv[])
{
  string tab[512];
  ifstream wej;
  ofstream wyj;
 
//----------------------------//odczyt z pliku//--------------------------------
  wej.open("slownik.txt");       
  if (!wej)cout<<"slownik.txt nie zostal otworzony"<<endl;
//else cout<<"slownik.txt zostal otworzony"<<endl;
  for (int i=0;i<512;i++)
  {
      wej>>tab[i];
  }
  wej.close();
  cout<<"Dane zostaly pobrane z pliku: slownik.txt"<<endl;

//------------------------------//menu//----------------------------------------
  while(1)
  {
  cout<<"Aby wyswietlic tablice wcisnij (1)"<<endl;
  cout<<"Aby posortowac tablice algorytmem babelkowym wcisnij (2)"<<endl;
  cout<<"Aby posortowac tablice przez wybieranie wcisnij (3)"<<endl;
  cout<<"Aby dodac wiersz wcisnij (4)"<<endl;
  cout<<"Aby usunac wiersz wcisnij (5)"<<endl;
  cout<<"Aby zapisac i wyjsc wcisnij (z)"<<endl;
  char z;
  cin>>z;
//-------------------------//wyswietlenie tabeli//------------------------------                                 
if (z=='1')
{
  for (int i=0,j=0,y=1;i<512;i++,j++)
  {
          if(tab[i].length()==0)break;
          if (i%2==0) cout<<y++<<" ";
          cout<<tab[i]<<" ";
          if (j%2==1) cout<<endl;
  }
}    
//-----------------------//sortowanie babelkowe//-------------------------------
else if (z=='2')
{
           cout<<"A-Z(1) czy Z-A(2)?"<<endl;
  cin>>z;
  if (z=='1') //sortowanie babelkowe A-Z
  {
      for(int i=0;i<512;i++)
        for(int j=510;j>i;j-=2)
          if (tab[j].compare(tab[j-2])==-1){
          swap(tab[j],tab[j-2]);
          swap(tab[j+1],tab[j-1]);
             }
      cout<<"sortowanie babelkowe A-Z zostalo ukonczone"<<endl;          
  }
  else if (z=='2') //sortowanie babelkowe Z-A
    {
      for(int i=0;i<512;i++)
        for(int j=510;j>i;j-=2)
          if (tab[j].compare(tab[j-2])==1){
          swap(tab[j],tab[j-2]);
          swap(tab[j+1],tab[j-1]);
             }
       cout<<"sortowanie babelkowe Z-A zostalo ukonczone"<<endl;             
  }
  else cout<<"blad"<<endl;
}
//----------------------//sortowanie przez wybieranie//-------------------------
else if (z=='3') 
{
      cout<<"A-Z(1) czy Z-A(2)?"<<endl;
  cin>>z;
  if (z=='1') //sortowanie przez wybieranie A-Z
  {
     for (int i=0;i<509;i+=2)
     {
         int m=i,j;
         for(j=i+2;j<511;j+=2) if(tab[j].compare(tab[m])==-1) m=j;
         swap(tab[i],tab[m]);
         swap(tab[i+1],tab[m+1]);
     }
       cout<<"sortowanie przez wybieranie A-Z zostalo ukonczone"<<endl;
  }
  else if(z=='2') //sortowanie przez wybieranie Z-A
  {
       for (int i=0;i<509;i+=2)
       {
         int m=i,j;
         for(j=i+2;j<511;j+=2) if(tab[j].compare(tab[m])==1) m=j;
         swap(tab[i],tab[m]);
         swap(tab[i+1],tab[m+1]);
       }
       cout<<"sortowanie przez wybieranie Z-A zostalo ukonczone"<<endl;
  }
  else cout<<"blad"<<endl;         
}

//----------------------------//dodawanie wiersza//-----------------------------
else if (z=='4')
{  
  string napis1,napis2;
  int x=0;
  cout<<"Podaj wyraz po polsku: ";
  cin>>napis1;
  cout<<"Podaj wyraz po angielsku: ";
  cin>>napis2;
  while(tab[x].length()>0)
  {
   x++;
  }
tab[x]=napis1;
tab[x+1]=napis2;
}  
//----------------------------//usuwanie wiersza//------------------------------
else if (z=='5')
{  
int wiersz;
 cout<<"Podaj nr wiersza(1,2,3 itd), ktory chcesz usunac: ";
 cin>>wiersz;
 wiersz=(wiersz-1)*2;
 tab[wiersz]="";
 tab[wiersz+1]="";
 
 if (tab[wiersz+2].length()>0){
  for (int p=wiersz;p<509;p+=2)
  {  
      tab[p]=tab[p+2];
      tab[p+1]=tab[p+3];
  }
 }
}
else if (z=='z')break;
else cout<<"blad"<<endl; 
}  
//----------------------------//zapis do pliku//--------------------------------
  wyj.open("wynik.txt");                                  
  if(!wyj)cout<<"wynik.txt nie zostal otworzony"<<endl;
//else cout<<"wynik.txt zostal otworzony"<<endl;
  for (int i=0,j=0;i<512;i++,j++)
  {
          wyj<<tab[i]<<" ";
          if (j%2==1) wyj<<endl;
  }
  wyj.close();
  cout<<"Wynik zostal zapisany w pliku: wynik.txt"<<endl;
  
//-----------------------------//najdluzszy wyraz//-----------------------------
  int m=0,ex=tab[0].length();
  for (int i=1;i<512;i++)
{
  if (tab[i].length()>ex)
  {
   m=i,ex=tab[i].length();
  }
}
  cout<<"Najdluzszy wyraz to "<<tab[m]<<". Jego dlugosc wynosi "<<tab[m].length()<<" znakow."<<endl;
  
//---------------------------//najkrotszy wyraz//-------------------------------
  m=100,ex=tab[0].length();
  for (int i=1;i<512;i++)
{
  if (tab[i].length()<ex&&tab[i].length()>0)
  {
   m=i,ex=tab[i].length();
  }
}
  cout<<"Najkrotszy wyraz to "<<tab[m]<<". Jego dlugosc wynosi "<<tab[m].length()<<" znakow."<<endl;

//-----------------------//wstrzymanie konsoli//--------------------------------
	cin.ignore(INT_MAX, '\n');
	cin.get();
	return 0;
}
