#include "mermi.h"

Mermi::Mermi(int x, int y):Varlik(x,y)
{
     ciz();
}

Mermi::~Mermi()
{
    sil();
}
void Mermi::ciz()
{
    cout<<termcolor::white;
    cout<<termcolor::on_red;
    termcolor::gotoxy(getX(),getY())  ;cout<<"*";
}
void Mermi::sil()
{
    cout<<termcolor::white;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY())  ;cout<<" ";
}
