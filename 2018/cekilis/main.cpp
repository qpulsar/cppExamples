#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int kazanan = rand()%30;
    cout << "Kazanan:" <<kazanan<< endl;
    return 0;
}
