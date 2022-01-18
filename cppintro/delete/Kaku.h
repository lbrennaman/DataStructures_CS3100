#ifndef KAKU_H
#define KAKU_H

#include "Futatsu.h"

class Kaku
{

    private:
        int size;
        Futatsu** array;

    public:
        Kaku();
        ~Kaku();
        void miseru();
        int returnNum(Kaku*);

};

#endif