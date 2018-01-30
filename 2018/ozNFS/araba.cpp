#include "araba.h"

Araba::Araba(int x, int y):Varlik(x,y)
{
    ciz();
}

Araba::~Araba()
{
    sil();
}
void Araba::ciz()
{
cout<<termcolor::red<<termcolor::on_blue;
termcolor::gotoxy(getX(),getY()  );cout<<" _/  \\_ ";
termcolor::gotoxy(getX(),getY()+1);cout<<"|______|";
termcolor::gotoxy(getX(),getY()+2);cout<<" o   o  ";
}
void Araba::sil()
{
cout<<termcolor::cyan<<termcolor::on_blue;
termcolor::gotoxy(getX(),getY()  );cout<<"       ";
termcolor::gotoxy(getX(),getY()+1);cout<<"       ";
termcolor::gotoxy(getX(),getY()+2);cout<<"       ";
}
