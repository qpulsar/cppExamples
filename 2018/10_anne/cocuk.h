#ifndef COCUK_H
#define COCUK_H

#include "anne.h"
#include "baba.h"

class Cocuk : public Anne, protected Baba
{
    public:
        Cocuk();
        virtual ~Cocuk();

    protected:

    private:
};

#endif // COCUK_H
