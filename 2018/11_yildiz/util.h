#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "termcolor.hpp"
//#include <termios.h> // getch() fonksiyonunu kullanabilmek için...

using namespace std;

#define NB_ENABLE 0
#define NB_DISABLE 1

void Sleep(unsigned int mseconds)
{
    mseconds *= 1000;
    clock_t goal = mseconds + clock();
    int i;
    while (goal > clock())
    {
        cout<<termcolor::dark<<termcolor::bold;
        //cout<<"bekle: "<<goal - clock();
        i= clock() * clock() * clock();
    }
}

void terminal_ayarla()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state)
{
    struct termios ttystate;

    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);

    if (state==NB_ENABLE)
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state==NB_DISABLE)
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

}

/* reads from keypress, doesn't echo */
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

