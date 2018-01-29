#include "star.h"

Star::Star(int x, int y)
{
    mX=x;
    mY=y;
    mDx=1;
    mDy=1;
    termcolor::gotoxy(mX,mY);
    cout<<"*";
}
Star::~Star()
{
    termcolor::gotoxy(mX,mY);
    cout<<" ";
}
void Star::ilerle()
{
    termcolor::gotoxy(mX,mY);
    cout<<" ";
    mX += mDx;
    mY += mDy;
    if(mX>79 || mX<2) mDx = -mDx;
    if(mY>23 || mY<2) mDy = -mDy;
    termcolor::gotoxy(mX,mY);
    cout<<"*";
}
