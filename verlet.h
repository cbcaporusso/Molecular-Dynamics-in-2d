#include "atom.h"

#ifndef VERLET_H
#define VERLET_H

class Verlet
{
    public:
        Verlet();
        void getdt();
        void getBoxSize(); 
        void stepper();
};

#endif