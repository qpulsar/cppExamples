#ifndef VARLİK_H
#define VARLİK_H

#include <iostream>

using namespace std;
class Varlik
{
    public:
        Varlik();
        Varlik(int x, int y);
        Varlik(int x, int y, int v);
        virtual ~Varlik();
        virtual void ciz();
        virtual void sil();
        void hareket(int dx, int dy);
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void setV(int v);
        int getV();
    protected:
    private:
        int mX;
        int mY;
        int mV;
};

#endif // VARLİK_H
