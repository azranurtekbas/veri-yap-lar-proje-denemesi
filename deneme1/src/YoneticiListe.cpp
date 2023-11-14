#include "YoneticiDugum.hpp"
#include <YoneticiListe.hpp>
#include<iomanip>


YoneticiListe::YoneticiListe()
{
    elemanSayisi=0;
    cizilecekDugumSayisi=8;
    satirGenislik=12;
    cizimBaslangicSirasi=0;

    for(int i=0;i<satirGenislik; i++)
    strCizgi+='-';
    ilk=0;
}
void YoneticiListe::solaOtele()
{
   if(cizimBaslangicSirasi-cizilecekDugumSayisi>=0)
     cizimBaslangicSirasi-=cizilecekDugumSayisi;
}
void YoneticiListe::sagaOtele()
{
    if(cizimBaslangicSirasi+cizilecekDugumSayisi<elemanSayisi)
     cizimBaslangicSirasi+=cizilecekDugumSayisi;
}

YoneticiListe::~YoneticiListe()
{
    YoneticiDugum* gec =ilk;
    while(gec!=0)
    {
      YoneticiDugum* silinecek = gec;
      gec=gec->next; 

      delete silinecek ;
    }
}

void YoneticiListe::ekle(SatirListe* nextListe)
{
    YoneticiDugum* newDugum = new YoneticiDugum(nextListe);
    if(ilk==0)
    {
        ilk = newDugum;
    }
    else
    {
      YoneticiDugum* gec = ilk;
      YoneticiDugum* son = 0;
      bool eklemeYapildimi =false;

      while(gec!=0)
      {
            float nextOrtalama = gec->SatirListesi->ortalamaGetir();
            float newOrtalama = newDugum->SatirListesi->ortalamaGetir();

            if(newOrtalama<nextOrtalama&&!eklemeYapildimi)
            {
               YoneticiDugum* previousDugum = gec->previous;
               newDugum->next = gec; 
               newDugum->previous = gec->previous;

               if(previousDugum)
               previousDugum->next = newDugum;
               else
                ilk = newDugum;
                gec->previous = newDugum;
                eklemeYapildimi= true;
                
                

            } //end of while(gec!=0)
            son=gec;
            gec=gec->next;

            if(!eklemeYapildimi)
            {
                son->next = newDugum;
                newDugum->previous = son;
            }
            
      }

    }
    elemanSayisi++;
}
void YoneticiListe::cikar()
{
    if(ilk==0)   
     return 0;

    if(ilk->next==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
      YoneticiDugum* gec =ilk;

      while(gec->next->next!=0)
         gec=gec->next;

      delete gec->next;
      gec->next =0;
    }
    elemanSayisi--;
    
}

void YoneticiListe::onuneEkle(int sira,SatirListe* veri)
{
    YoneticiDugum* aktifDugum= dugumGetir(sira);

    if(aktifDugum)
    {
        YoneticiDugum* aktifOnceki = aktifDugum->previous;
        YoneticiDugum*newDugum = new YoneticiDugum(veri);

        aktifDugum->previous = newDugum;

        newDugum->next = aktifDugum;
        newDugum->previous = aktifOnceki;

        if(aktifOnceki)
           aktifOnceki->next = newDugum;
        else
          ilk=newDugum;
    }
    elemanSayisi++;

}

void YoneticiListe::cikar(int sira)
{
    YoneticiDugum* silinecek= dugumGetir(sira);

 if(silinecek)
 {
     
     
  YoneticiDugum* silinecekPrevious= silinecek->previous;
  YoneticiDugum* silinecekNext=silinecek->next;

  if(silinecekNext) silinecekNext->previous= silinecekPrevious;
  if(silinecekPrevious) silinecekPrevious->next= silinecekNext;
  else
  ilk= silinecekNext;
  delete silinecek;
  elemanSayisi--;      
 }
}

YoneticiListe* YoneticiListe::dugumGetir(int sira)
{
    YoneticiListe* gec =ilk;

    while(sira>0&&gec!=0)
    {
        if(sira==0) return gec;
        gec=gec->next;

        sira--; 
    }  
    return 0; 
}

void YoneticiListe::cizgiCiz()
{
    int sinir = cizilecekDugumSayisiHesapla();
    for(int i=0;i<sinir;i++)
    {
       cout << strCizgi<<"   "; 
    }
    cout<< endl;

}
void YoneticiListe::adresYazdir()
{
    YoneticiDugum* nextDugum = dugumGetir(cizimBaslangicSirasi);
    int sinir = cizilecekDugumSayisiHesapla();
    for(int i=0;i<sinir;i++)
    {
       cout <<" "<<setw(satirGenislik-2)<<nextDugum<<"    "; 
       nextDugum=nextDugum->next;
    }
    cout<< endl;
}
void YoneticiListe::previousAdresYazdir()
{
    YoneticiDugum* nextDugum = dugumGetir(cizimBaslangicSirasi);
    int sinir = cizilecekDugumSayisiHesapla();
    for(int i=0;i<sinir;i++)
    {
       cout <<"|"<<setw(satirGenislik-2)<<nextDugum->previous<<"|    "; 
       nextDugum=nextDugum->next;
    }
    cout<< endl;
}
void YoneticiListe::nextAdresYazdir()
{
    YoneticiDugum* nextDugum = dugumGetir(cizimBaslangicSirasi);
    int sinir = cizilecekDugumSayisiHesapla();
    for(int i=0;i<sinir;i++)
    {
       cout <<"|"<<setw(satirGenislik-2)<<nextDugum->next<<"|    "; 
       nextDugum=nextDugum->next;
    }
    cout<< endl;
}
void YoneticiListe::ortYazdir()
{
   YoneticiDugum* nextDugum = dugumGetir(cizimBaslangicSirasi);
   int sinir = cizilecekDugumSayisiHesapla();
    for(int i=0;i<sinir;i++)
    {
       cout <<"|"<<setw(satirGenislik-2)<<nextDugum->SatirListesi->ortalamaGetir()<<"|    "; 
       nextDugum=nextDugum->next;
    }
    cout<< endl;
}
int yoneticiListe::cizilecekDugumSayisiHesapla()
{
  int sinir = cizilecekDugumSayisi;  

  if(cizimBaslangicSirasi+cizilecekDugumSayisi>elemanSayisi)
  {
    sinir = elemanSayisi-cizimBaslangicSirasi;
  }

  return sinir;
}
   
ostream& operator<<(ostream& os,YoneticiListe& liste)
{
    using namespace std;
    liste.adresYazdir();
    liste.cizgiCiz();
    liste.previousAdresYazdir();
    liste.cizgiCiz();
    liste.ortYazdir();
    liste.cizgiCiz();
    liste.nextAdresYazdir();
    liste.cizgiCiz();

    return os;
}

