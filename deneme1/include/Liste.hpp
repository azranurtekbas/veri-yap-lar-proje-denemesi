#include<exception>
#include<iostream>
#include"Dugum.hpp"
class Liste
{
public:
   Liste();
  ~Liste();
   void ekle(int veri);
   void cikar();
   void cikar(int sira);
   void onuneEkle(int sira,int veri);
   int ilkGetir();
   friend ostream& operator<<(ostream& os,SatirListe& liste);
   SatirDugum* dugumGetir(int sira);

private:
 
    int     ortalama;
    int     elemanSayisi;  


   Dugum* ilk;
};