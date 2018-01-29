#include <iostream>
#include"timer.h"
using namespace std;

int main()
{
    Timer *start = new Timer();
    start->yaz();
    start->zamanAta(5,0,50);
    start->yaz();
    start->ilerle(120);
    start->yaz();

    Timer *sure = new Timer(3,2,5);
    start->topla(sure);
    start->yaz();
    start->esitle(sure);
    start->yaz();

//    start=sure;
//    start = start + sure;

    delete start;
    return 0;
}
