#include <iostream>

using namespace std;

int main()
{
    int sayi;
    do
    {
        cout << "Bir sayi girin:";
        cin>>sayi;
        if(sayi==0) break;
        cout<< sayi<<"*2 = "<<sayi*2<<endl;
    } while (sayi!=0);

    return 0;
}
