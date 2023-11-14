#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp
#include<iostream>
#include"Liste.hpp"
using namespace std;

class Dugum
{
public:
//~ alt 0126 ile yapılıyor
Dugum(int veri)
~Dugum();
int veri;
Dugum* sonraki;
Dugum* onceki;
     
    /*YoneticiDugum(SatirListe* SatirListesi);
    ~YoneticiDugum();
    SatirListe* SatirListesi;
     YoneticiDugum* previous;
     YoneticiDugum* next;*/
    
};

#endif