#include <iostream>
#include "anne.h"
#include "cocuk.h"

using namespace std;

int main()
{
    Anne *gulsah = new Anne;
//    gulsah->kucak=5;
//    gulsah->keder = 99;
    gulsah->sefkat();
    delete gulsah;
cout<<"==============\n";
    Cocuk *sezercik = new Cocuk;
    sezercik->sefkat();
 //   sezercik->otorite();
//    sezercik->kucak = 89;
    delete sezercik;
    return 0;
}
