#include "engel.h"

Engel::Engel():Varlik(78,17)
{
//    setX(78);
//    setY(17);
    ciz();
}

Engel::~Engel()
{
    sil();
}
void Engel::ciz()
{
    cout<<termcolor::on_grey;
    cout<<termcolor::white;
    termcolor::gotoxy(getX(),getY()  );cout<<"HHH";
    termcolor::gotoxy(getX(),getY()+1);cout<<"HHH";
    termcolor::gotoxy(getX(),getY()+2);cout<<"HHH";
}
void Engel::sil()
{
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";
}
