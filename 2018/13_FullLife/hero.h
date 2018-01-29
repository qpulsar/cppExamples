#ifndef HERO_H
#define HERO_H

#include "varlik.h"


class Hero : public Varlik
{
    public:
        Hero();
        virtual ~Hero();
        void ciz();
        void sil();
        void setOtur(bool o);
        bool getOtur();
        void setZipla(bool z);
        bool getZipla();
        void setYuksel(bool y);
        bool getYuksel();
    protected:

    private:
        bool mOtur;
        bool mZipla;
        bool mYuksel;
};

#endif // HERO_H
