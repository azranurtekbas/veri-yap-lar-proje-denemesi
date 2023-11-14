/*#ifndef liste_hpp
#define liste_hpp
#include<exception> 
#include<iostream>
#include "YoneticiDugum.hpp"
using namespace std;
class YoneticiListe
{
public:

  YoneticiListe();
 ~YoneticiListe();
  void ekle(SatirListe* veri);
   void cikar();
   void cikar(int sira);
   void onuneEkle(int sira,SatirListe* veri);
   SatirListe* ilkGetir()
   {
       if (ilk != 0)
           return ilk->SatirListesi;
       throw std::out_of_range("YoneticiDugum::ilkGetir(): YoneticiDugum bos hatasi");
   }
   friend ostream& operator<<(ostream& os,YoneticiListe& liste);
   YoneticiDugum* dugumGetir(int sira);


   void cizgiCiz();
   void adresYazdir();
   void previousAdresYazdir();
   void ortYazdir();

   void solaOtele();
   void sagaOtele();
   int cizilecekDugumSayisiHesapla();

private:
  int satirGenislik;
  string strCizgi;
  int       elemanSayisi;
  int cizilecekDugumSayisi;
  int cizimBaslangicSirasi;
  YoneticiDugum* ilk;
};

#endif*/