#include "dusman.h"

Dusman::Dusman()
{
    setX(79);
    setY(rand()%13+3);
    ciz();
}

Dusman::~Dusman()
{
    sil();
}
void Dusman::ciz()
{
    cout<<termcolor::on_white;
    cout<<termcolor::green;
    termcolor::gotoxy(getX(),getY()  );cout<<"DD";
    termcolor::gotoxy(getX(),getY()+1);cout<<"DD";
}
void Dusman::sil()
{
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY()  );cout<<"  ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"  ";
}
