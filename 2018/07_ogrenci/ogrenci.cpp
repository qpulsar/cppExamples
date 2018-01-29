#include "ogrenci.h"

Ogrenci::Ogrenci(string numara)
{
    mNumara = numara;
    setIsim("Okkes");
    setVize(0);
    setFinal(0);
}

Ogrenci::~Ogrenci()
{
    cout<<mNumara<<":ogrenci nesnesi yok oldu\n";
}
void Ogrenci::setIsim(string isim)
{
    mIsim = isim;
}
string Ogrenci::getIsim()
{
    return mIsim;
}
void Ogrenci::setVize(int v)
{
    if(v<0 || v>100)
        return;
    else
        mVize = v;
}
int Ogrenci::getVize()
{
    return mVize;
}
void Ogrenci::setFinal(int f)
{
    if(f<0 || f>100)
        return;
    else
        mFinal = f;
}
int Ogrenci::getFinal()
{
    return mFinal;
}
float Ogrenci::ortalamaHesapla()
{
    return mVize*0.4 + mFinal*0.6;
}
void Ogrenci::bilgiYaz()
{
    cout<<"numara:"<<mNumara<<endl;
    cout<<"Isim:"<<mIsim<<endl;
    cout<<"Vize:"<<mVize<<endl;
    cout<<"Final:"<<mFinal<<endl;
    cout<<"Ortalama:"<<ortalamaHesapla()<<endl;
}
