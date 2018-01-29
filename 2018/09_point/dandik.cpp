#include "dandik.h"

Dandik::Dandik()
{
    cout<<"Dandik olustu\n";
    ip = new int;
}

Dandik::~Dandik()
{
    delete ip;
    ip = NULL;
    cout<<"Dandik yokoldu\n";
}
void Dandik::sayi(int s)
{
    *ip = s;
}
Dandik::Dandik(const Dandik &obj)
{
    cout<<"Kopyalandim ben\n";
    ip = new int;
    *ip = *obj.ip;
}





