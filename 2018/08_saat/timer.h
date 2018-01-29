#ifndef TIMER_H
#define TIMER_H
#include<iostream>
using namespace std;

class Timer
{
    public:
        Timer();
        Timer(int saat, char dak, char saniye);
        virtual ~Timer();
        void zamanAta(int saat, char dak, char saniye);
        void setSaat(int s);
        void setDakika(int s);
        void setSaniye(int s);
        void yaz();
        void ilerle(int s);
        void topla(const Timer *nesne);
        void esitle(Timer *gelen);
    protected:

    private:
        int mSaat;
        int mDakika;
        int mSaniye;
};

#endif // TIMER_H
