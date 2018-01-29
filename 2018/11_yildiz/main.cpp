#include <iostream>
#include "util.h"
#include "termcolor.hpp"
// #include <conio.h> sadece windows

using namespace std;

int main()
{
    terminal_ayarla(); ///yalnızca linux
/*    termcolor::gotoxy(80,1);
    cout<<termcolor::blue;
    cout<<"*";
    termcolor::gotoxy(1,25);
    cout<<termcolor::red;
    cout<<"B";
    getch();
*/
    int x=40;
    int y=10;
    int dx=1;
    int dy=1;
    do
    {
        termcolor::gotoxy(x,y);
        cout<<"*";
        Sleep(50);
        termcolor::gotoxy(x,y);
        cout<<" ";
        x += dx;
        y += dy;
        if(y>23 || y<2) dy = -dy;
        if(x>79 || x<2) dx = -dx;
    } while (kbhit()==0);
    return 0;
}
