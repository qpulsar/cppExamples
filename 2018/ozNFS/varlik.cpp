#include "varlik.h"

Varlik::Varlik()
{
    setX(75);
    setY(5);
    setV(0);
    ciz();
}

Varlik::~Varlik()
{
    sil();
}
Varlik::Varlik(int x, int y)
{
    setX(x);
    setY(y);
    setV(0);
}
Varlik::Varlik(int x, int y, int v)
{
    setX(x);
    setY(y);
    setV(v);
}
void Varlik::ciz()
{
    ///miras alan yapacak
}
void Varlik::sil()
{
    ///miras alan yapacak
}
void Varlik::hareket(int dx, int dy)
{
    sil();
    setX(getX()+dx);
    setY(getY()+dy);
    ciz();
}
void Varlik::setX(int x)
{
    mX = x>0 && x<81 ? x : mX;
}
int Varlik::getX()
{
    return mX;
}
void Varlik::setY(int y)
{
    mY = y>0 && y<25 ? y : mY;
}
int Varlik::getY()
{
    return mY;
}
void Varlik::setV(int v)
{
    mV= v;
}
int Varlik::getV()
{
    return mV;
}
