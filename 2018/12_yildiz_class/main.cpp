#include <iostream>
#include"util.h"
#include"termcolor.hpp"
#include"star.h"
#include<time.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main()
{
    long unsigned int sayac = 0;
    terminal_ayarla();
    srand(time(NULL));
    Star *halley;
    vector<Star *> starvec;
    vector<Star *>::iterator starit;

   // nonblock(NB_ENABLE);
    system("setterm -cursor off");
    do
    {
        if(sayac%100==0)
        {
            halley = new Star(rand()%75+1,rand()%20+2);
            starvec.push_back(halley);
        }
        for(starit = starvec.begin();
            starit!=starvec.end(); starit++)
        {
            (*starit)->ilerle();
        }
        Sleep(50);
        sayac++;
        termcolor::gotoxy(1,1);
        cout<<kbhit();
    } while (!kbhit());
    return 0;
}
