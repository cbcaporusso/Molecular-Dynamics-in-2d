#include <iostream>
#include <vector>

#include "types.h"

#ifndef ATOM_H
#define ATOM_H

struct mdatom {
    
        // data members 
        Vector2 r;
        Vector2 v;
        Vector2 f;

        int           id;
        const double  m {1.0};
        const double  radius {0.5};

        // constructor 
        mdatom();
        mdatom(Vector2);
        mdatom(Vector2, Vector2);
        mdatom(Vector2, Vector2, Vector2);

        double  PBCdistance(const mdatom&, Vector2);
        void    PBCadjust(Vector2);
        
        //double  kinE() { return 0.5 * m * v * v; };
        //double potE(pot);

};

#endif