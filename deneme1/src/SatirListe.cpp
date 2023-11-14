#include "SatirDugum.hpp"
#include "SatirListe.hpp"
#include<iomanip>

SatirListe::SatirListe()
{
    ilk=0;
    elemanSayisi=0;
    ortalama=0;
}

SatirListe::~SatirListe()
{
    SatirDugum* gec =ilk;
    while(gec!=0)
    {
      SatirDugum* silinecek = gec;
      gec=gec->next; 

      delete silinecek;
    }
}

void SatirListe::ekle(int veri)
{
    SatirDugum* newDugum = new SatirDugum(veri);
    if(ilk==0)
    {
        ilk = newDugum;
    }
    else
    {
      SatirDugum* gec = ilk;

      while(gec->next!=0)
      {
            gec=gec->next;
      }

       gec->next = newDugum;
       newDugum->previous = gec;
    }
    elemanSayisi++;
}
int SatirListe::ilkGetir(int veri)
{
    if(ilk!=0)
     return ilk->veri;
    throw std::out_of_range("SatirListe::ilkGetir(): Lİste bos hatasi");
}
void SatirListe::cikar()
{
    if(ilk==0)   return 0;

    if(ilk->next==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
      SatirDugum* gec =ilk;

      while(gec->next->next!=0)
         gec=gec->next;

      delete gec->next;
      gec->next =0;
    }
    elemanSayisi--;
}

void SatirListe::onuneEkle(int sira, int veri)
{
    SatirDugum* aktifDugum = dugumGetir(sira);

    if (aktifDugum)
    {
        SatirDugum* aktifOnceki = aktifDugum->previous;
        SatirDugum* newDugum = new SatirDugum(veri);

        aktifDugum->previous = newDugum;

        newDugum->next = aktifDugum;
        newDugum->previous = aktifOnceki;

        if (aktifOnceki)
            aktifOnceki->next = newDugum;
        else
            ilk = newDugum;
    }
    elemanSayisi++;

}

void SatirListe::cikar(int sira)
{
    SatirDugum* silinecek= dugumGetir(sira);

if(silinecek)
{
     
     
  SatirDugum* silinecekPrevious= silinecek->previous;
  SatirDugum* silinecekNext=silinecek->next;

  if(silinecekNext) silinecekNext->previous= silinecekPrevious;
  if(silinecekPrevious) silinecekPrevious->next= silinecekNext;
  else
  ilk= silinecekNext;
  delete silinecek;
  elemanSayisi--;
        
}

}

SatirDugum* SatirListe::dugumGetir(int sira)
{
    SatirDugum* gec =ilk;

    while(sira>0&&gec!=0)
    {
        if(sira==0) return gec;
        gec=gec->next;

        sira--;
    }  
    return 0; 
}

ostream& operator<<(ostream& os,SatirListe& liste)
{
    using namespace std;

    os<<setw(15)<<"Satirdugum adres"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15);

     SatirDugum* gec=liste.ilk;

    while(gec!=0)
    { 
        os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->previous<<setw(15);
    }

    os<<"-----------------------------------------"<<endl;
}

void SatirListe::birSatirYazdir()
{
    SatirDugum* gec=ilk;

    while(gec!=0)
    {
        cout<<setw(4)<<gec->veri;
        gec=gec->next;
    }
    cout<<endl;
}

