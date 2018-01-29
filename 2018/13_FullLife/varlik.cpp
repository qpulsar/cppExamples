#include "varlik.h"

Varlik::Varlik()
{
    setX(5);
    setY(5);
    ciz();
}
Varlik::Varlik(int x, int y)
{
    setX(x);
    setY(y);
    ciz();
}

Varlik::~Varlik()
{
    sil();
}
void Varlik::setX(int x)
{
mX = x>0&&x<81? x :mX;
/*
    if(x<1 || x>80)
        return;
    mX = x;
*/
}
int Varlik::getX()
{
    return mX;
}
void Varlik::setY(int y)
{
    mY = y>0&&y<25? y :mY;
}
int Varlik::getY()
{
    return mY;
}
void Varlik::ciz()
{
    //cocuklarim cizsin
}
void Varlik::sil()
{
    //cocuklarim silsin
}
void Varlik::hareket(int dx, int dy)
{
    sil();
    setX(getX()+dx);//mx += dx;
    setY(getY()+dy);//my += dy;
    ciz();
}
