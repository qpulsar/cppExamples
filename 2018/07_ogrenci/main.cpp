#include <iostream>
#include "ogrenci.h"

using namespace std;

int main()
{
    Ogrenci ogr("201510202315");
    ogr.setIsim("Mecnun Coksever");
    ogr.setVize(23);
    ogr.setFinal(35);
    ogr.bilgiYaz();

    Ogrenci stu("92834729");
    stu.setIsim("Ned Stark");
    stu.bilgiYaz();

    ogr.setVize(19);
    ogr.bilgiYaz();

    Ogrenci *op = new Ogrenci("09328409328");
    Ogrenci *iop;
    iop = new Ogrenci("8787887");
    op->setVize(78);
    op->bilgiYaz();

    delete op;
    delete iop;




    return 0;
}
