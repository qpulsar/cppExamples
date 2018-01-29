#ifndef BABA_H
#define BABA_H
#include <iostream>

using namespace std;

class Baba
{
    public:
        Baba();
        virtual ~Baba();
        void otorite();
    protected:
        float harclik;
    private:
        float maas;
};

#endif // BABA_H
