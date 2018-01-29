#ifndef OGRENCI_H
#define OGRENCI_H
#include<iostream>

using namespace std;

class Ogrenci
{
    public:
        Ogrenci(string numara);
        ~Ogrenci();
        void setIsim(string isim);
        string getIsim();
        void setVize(int v);
        int getVize();
        void setFinal(int f);
        int getFinal();
        float ortalamaHesapla();
        void bilgiYaz();
    protected:

    private:
        string mNumara;
        string mIsim;
        int mVize;
        int mFinal;
};

#endif // OGRENCI_H
