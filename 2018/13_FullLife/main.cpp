#include <iostream>
#include"termcolor.hpp"
#include"util.h"
#include"engel.h"
#include"hero.h"
#include"mermi.h"
#include<vector>
using namespace std;
void dolgu(int bx, int by,int sx, int sy, int r)
{
    int x,y;
    for(x=bx;x<sx;x++)
        for(y=by;y<sy;y++)
        {
            if(r==1)
                cout<<termcolor::on_blue;
            else
                cout<<termcolor::on_green;
            termcolor::gotoxy(x,y);
            cout<<" "; //boşluk
        }
}
void ekran()
{
    dolgu(1,1,81,20,1);
    dolgu(1,20,81,25,2);

}
int main()
{
    system("setterm -cursor off");
    ekran();
    terminal_ayarla(); ///ubuntu
    Engel *safran = NULL;
    int engelZaman = rand()%30;
    long unsigned int frm=0;
    Hero *Bahattin = new Hero;
    unsigned char tus;
    nonblock(NB_ENABLE); ///ubuntu
    vector<Mermi*>mermiler;
    vector<Mermi*>::iterator mer;

    do{
        if(safran==NULL&&engelZaman==frm)
        {
            safran=new Engel();
        }
        if(safran!=NULL)
            safran->hareket(-1,0);

        if(kbhit()!=0)
        {
            tus= getch();
            if(tus=='A' || tus=='a')
            {
                Bahattin->hareket(-1,0);
            }else if(tus=='D' || tus=='d')
            {
                Bahattin->hareket(1,0);
            }else if(tus=='S' || tus=='s')
            {
                Bahattin->setOtur(!Bahattin->getOtur());
            }else if(tus=='W' || tus=='w')
            {
                if(Bahattin->getZipla()==false)
                {
                    Bahattin->setZipla(true);
                    Bahattin->setYuksel(true);
                }
            }else if(tus==' ')
            {
                Mermi *dan = new Mermi(Bahattin->getX()+3,
                                        Bahattin->getY()+1);
                mermiler.push_back(dan);
            }
        }
        if(Bahattin->getZipla())
        {
            if(Bahattin->getYuksel())
            {
                Bahattin->hareket(0,-1);
                if(Bahattin->getY()<4)
                    Bahattin->setYuksel(false);
            }else
            {
                Bahattin->hareket(0,1);
                if(Bahattin->getY()>15)
                    Bahattin->setZipla(false);
            }
        }
        for(mer=mermiler.begin();mer!=mermiler.end();mer++)
        {
            (*mer)->hareket(1,0);
        }
        Sleep(50);
        mer=mermiler.begin();
        while(mer!=mermiler.end())
        {
            if((*mer)->getX()>79)
            {
                delete *mer;
                mermiler.erase(mer);
            }else
                mer++;
        }
        frm++;
        ///Kontroller
        if(safran!=NULL && safran->getX()<2)
        {
            delete safran;
            safran = NULL;
            engelZaman = frm+rand()%30;
        }
        //bilgi
        termcolor::gotoxy(1,1);
        cout<<termcolor::on_blue;
        cout<<termcolor::white;
        cout<<"frm="<<frm;
        termcolor::gotoxy(15,1);
        cout<<"ez="<<engelZaman;
    }while(1);
    getch();
    return 0;
}
