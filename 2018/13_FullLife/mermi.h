#ifndef MERMI_H
#define MERMI_H

#include "varlik.h"


class Mermi : public Varlik
{
    public:
        Mermi(int x, int y);
        virtual ~Mermi();
        void ciz();
        void sil();
    protected:

    private:
};

#endif // MERMI_H
