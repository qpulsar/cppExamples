#include "timer.h"

Timer::Timer()
{
    setSaat(0);
    setDakika(0);
    setSaniye(0);
}
Timer::Timer(int saat, char dak, char saniye)
{
    setSaat(saat);
    setDakika(dak);
    setSaniye(saniye);
}

Timer::~Timer()
{
    //dtor
}
void Timer::zamanAta(int saat, char dak, char saniye)
{
    setSaat(saat);
    setDakika(dak);
    setSaniye(saniye);
}
void Timer::setSaat(int s)
{
    if(s>=0)
        mSaat = s;
}
void Timer::setDakika(int s)
{
    if(s>=0 && s<60)
        mDakika = s;
}
void Timer::setSaniye(int s)
{
    if(s>=0 && s<60)
        mSaniye = s;
}
void Timer::yaz()
{
    cout<<mSaat<<":"<<int(mDakika)<<":"<<int(mSaniye)<<endl;
}

void Timer::ilerle(int s)
{
    mSaniye += s;
    int artan = mSaniye / 60;
    mSaniye = mSaniye % 60;
    mDakika += artan;
    artan = mDakika / 60;
    mDakika %= 60;
    mSaat += artan;
}
void Timer::topla(const Timer *nesne)
{
    this->mSaniye += nesne->mSaniye;
    int artan = this->mSaniye / 60;
    this->mSaniye = this->mSaniye % 60;
    this->mDakika = artan +nesne->mDakika + this->mDakika;
    artan = this->mDakika / 60;
    this->mDakika %= 60;
    mSaat = this->mSaat+nesne->mSaat+artan;
}

void Timer::esitle(Timer *gelen)
{
    mSaniye = gelen->mSaniye;
    mDakika = gelen->mDakika;
    mSaat = gelen->mSaat;
}







