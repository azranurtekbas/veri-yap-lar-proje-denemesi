#include "SatirDugum.hpp"
using namespace std;

Dugum::Dugum(int veri)
{
    this->veri = veri;

    onceki = sonraki = 0;
}

Dugum::~Dugum()
{
    cout<<this<<"adresindeki dugum silindi"<<endl;
}
