#include "first.h"
#include <iostream>
First::First()
{
    sayi = 5;
    std::cout<<"Nesne olustu\n";
}
First::~First()
{
    std::cout<<"Nesne yok oldu:"<<sayi<<"\n";
}
void First::ataSayi(int s)
{
    sayi = s;
}
