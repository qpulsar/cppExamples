#ifndef ARABA_H
#define ARABA_H

#include "varlik.h"
#include "termcolor.hpp"


class Araba : public Varlik
{
    public:
        Araba(int x, int y);
        virtual ~Araba();
        void ciz();
        void sil();
    protected:
    private:
};

#endif // ARABA_H
