#include <iostream>
#include"termcolor.hpp"
#include"util.h"
#include"engel.h"
#include"hero.h"
#include"mermi.h"
#include"dusman.h"
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
void oldum(bool *dev)
{
    *dev = false;
    termcolor::gotoxy(5,10);
    cout<<termcolor::on_grey;
    cout<<termcolor::red;
    cout<<" GAME BITTI !!!";
    getch();
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
    vector<Dusman*>kostoklar;
    int dusmanZaman = rand()%30+50;
    int ziplaUstSinir;
    bool devam = true;
    do{
        if(dusmanZaman==frm)
        {
            Dusman *dsm = new Dusman;
            kostoklar.push_back(dsm);
            dusmanZaman = rand()%20+10+frm;
        }
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
                    if(Bahattin->getOtur())
                        ziplaUstSinir = 7;
                    else
                        ziplaUstSinir = 4;
                }
            }else if(tus==' ')
            {
                int namlu = Bahattin->getOtur()?2:1;
                Mermi *dan = new Mermi(Bahattin->getX()+3,
                                        Bahattin->getY()+namlu);
                mermiler.push_back(dan);
            }
        }
        if(Bahattin->getZipla())
        {
            if(Bahattin->getYuksel())
            {
                Bahattin->hareket(0,-1);
                if(Bahattin->getY()<ziplaUstSinir)
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
        for(vector<Dusman*>::iterator kos=kostoklar.begin();
            kos!=kostoklar.end();kos++)
        {
            (*kos)->hareket(-1,0);
        }

        Sleep(50);
        mer=mermiler.begin();
        while(mer!=mermiler.end())
        {

            if(
                (*mer)->getX()>79 ||
                (
                    safran!=NULL &&
                    (*mer)->getX()>=safran->getX() &&
                    (*mer)->getX()<=safran->getX()+3&&
                    (*mer)->getY()>=safran->getY()
                )
               )
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
        vector<Dusman*>::iterator pyd;
        pyd = kostoklar.begin();
        while(pyd!=kostoklar.end())
        {
            vector<Mermi*>::iterator domdom;
            domdom=mermiler.begin();
            bool carptimi = false;
            if((*pyd)->getX()<2)
            {
                delete *pyd;
                kostoklar.erase(pyd);
                continue;
            }
            while (domdom!=mermiler.end())
            {
                if((*domdom)->getX() >= (*pyd)->getX()&&
                   (*domdom)->getY() >= (*pyd)->getY()&&
                   (*domdom)->getY() <= (*pyd)->getY()+1
                  )
                {
                    delete *pyd;
                    delete *domdom;
                    mermiler.erase(domdom);
                    kostoklar.erase(pyd);
                    carptimi=true;
                    break;
                }
                else
                    domdom++;
            }
            if(!carptimi)
                pyd++;
        }
        //Ölüm kontrolü
        if(safran!=NULL&&
            Bahattin->getX()+2>=safran->getX()&&
            Bahattin->getX()<=safran->getX()+2&&
            Bahattin->getY()+3>=safran->getY()
          )
        {
            oldum(&devam);
        }
        for(vector<Dusman*>::iterator kos=kostoklar.begin();
            kos!=kostoklar.end();kos++)
        {
            int egil = Bahattin->getOtur()?2:0;

            if(Bahattin->getX()+2>=(*kos)->getX()&&  //sağı
               Bahattin->getX()<=(*kos)->getX()+1&&  //solu
               Bahattin->getY()+egil<=(*kos)->getY()+1&&  //kafası
               Bahattin->getY()+3>=(*kos)->getY()    //ayakları
               )
               oldum(&devam);
        }
        //bilgi
        termcolor::gotoxy(1,1);
        cout<<termcolor::on_blue;
        cout<<termcolor::white;
        cout<<"frm="<<frm;
        termcolor::gotoxy(15,1);
        cout<<"ez="<<engelZaman;
    }while(devam);
    getch();
    return 0;
}
