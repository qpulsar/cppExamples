#include <iostream>
#include"dandik.h"
using namespace std;
void gulum(Dandik dndk)
{
    cout<<"aldim gulum \n";
    dndk.sayi(88);

}
void abisinin(Dandik *kdkd)
{
    cout<<"aldim abisinin\n";
    kdkd->sayi(99);

}

int main()
{
    Dandik mandik;
    mandik.sayi(50);
    gulum(mandik);
    abisinin(&mandik);
    cin.get();
    mandik.sayi(111);
    return 0;
}
