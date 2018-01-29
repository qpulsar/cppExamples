#ifndef DANDIK_H
#define DANDIK_H
#include<iostream>
using namespace std;

class Dandik
{
    public:
        Dandik();
        virtual ~Dandik();
        void sayi(int s);
        Dandik(const Dandik &obj);

    protected:

    private:
        int *ip;
};

#endif // DANDIK_H
