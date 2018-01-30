#include <iostream>
#include "util.h"  ///ubuntu
#include "termcolor.hpp"
#include "araba.h"

using namespace std;

enum DURUM {menu, oyun, bekle, son};

void dolgu(int x1, int y1, int x2,int y2)
{
    for(int i=y1;i<=y2;i++)
        for(int j=x1;j<=x2;j++)
        {
            termcolor::gotoxy(j,i);
            cout<<" ";
        }
}

void ekran()
{
    cout<<termcolor::white<<termcolor::on_green;
    dolgu(1,1,80,4);
    dolgu(1,20,80,24);
    cout<<termcolor::white<<termcolor::on_blue;
    dolgu(1,5,80,19);
}
DURUM menuSor()
{
    cout<<termcolor::white<<termcolor::on_red;
    dolgu(1,1,80,24);
    termcolor::gotoxy(30,8);cout<<"1- OYUNA BASLA";
    termcolor::gotoxy(30,9);cout<<"2- OYUNDAN CIK";
    termcolor::gotoxy(30,10);
    int tus;
    tus=getch();
    if(tus=='1') return oyun;
    if(tus=='2') return son;
    return menu;
}
bool sonmu()
{
    cout<<termcolor::white<<termcolor::on_yellow;
    dolgu(1,1,80,24);
    termcolor::gotoxy(30,8);cout<<"Cikmak icin E";
    char tus;
    tus=getch();
    if(tus=='e' || tus=='E')
        return true;
    else return false;
}
void logic(Araba *arb)
{
     bool cont = true;
     char tus;
     nonblock(NB_ENABLE);
     do{
         arb->ciz();
         if(kbhit())
         {
           tus=getch();
           if(tus=='w'|| tus=='W')
           {
               if(arb->getY()>5)
                   arb->hareket(0,-1);
           }else if(tus=='s'|| tus=='S')
           {
               if(arb->getY()<19)
                   arb->hareket(0,1);
           }
        }
    }while(cont);
}


int main()
{
    DURUM durum=menu;
    bool devam=true;
    system("setterm -cursor off");  ///ubuntu
    terminal_ayarla();              ///ubuntu
    nonblock(NB_DISABLE);            ///ubuntu

    Araba *anadol = new Araba(2,10);
    do{
        switch(durum)
        {
            case menu: durum = menuSor();break;
            case oyun:ekran();
                logic(anadol);
                break;
            case bekle:break;
            case son: devam=!sonmu();
            if(devam) durum=oyun;
                break;
        }
    }while(devam);

    return 0;
}
