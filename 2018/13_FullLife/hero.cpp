#include "hero.h"

Hero::Hero()
{
    setX(5);
    setY(16);
    setOtur(false);
    setZipla(false);
    setYuksel(false);
    ciz();
}

Hero::~Hero()
{
    sil();
}
void Hero::setOtur(bool o)
{
    mOtur = o;
    ciz();
}
bool Hero::getOtur()
{
    return mOtur;
}
void Hero::setZipla(bool z)
{
    mZipla = z;
}
bool Hero::getZipla()
{
    return mZipla;
}
void Hero::setYuksel(bool y)
{
    mYuksel = y;
}
bool Hero::getYuksel()
{
    return mYuksel;
}

void Hero::ciz()
{
    cout<<termcolor::on_blue;
    cout<<termcolor::yellow;
    if(getOtur()==false)
    {
        if(getX()%2==0)
        {
            termcolor::gotoxy(getX(),getY()  );cout<<" 0 ";
            termcolor::gotoxy(getX(),getY()+1);cout<<"\\|-";
            termcolor::gotoxy(getX(),getY()+2);cout<<" | ";
            termcolor::gotoxy(getX(),getY()+3);cout<<"/ \\";
        }else
        {
            termcolor::gotoxy(getX(),getY()  );cout<<" 0 ";
            termcolor::gotoxy(getX(),getY()+1);cout<<"/|-";
            termcolor::gotoxy(getX(),getY()+2);cout<<" | ";
            termcolor::gotoxy(getX(),getY()+3);cout<<"| |";
        }
    }else
    {
        termcolor::gotoxy(getX(),getY()  );cout<<"   ";
        termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
        termcolor::gotoxy(getX(),getY()+2);cout<<"/0-";
        termcolor::gotoxy(getX(),getY()+3);cout<<"< >";
    }
}
void Hero::sil()
{
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+3);cout<<"   ";
}
