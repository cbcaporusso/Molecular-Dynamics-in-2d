#include <iostream>
#include <vector>

#include "types.h"

#ifndef ATOM_H
#define ATOM_H

struct mdatom {
    
        mdatom();
        mdatom(Vector2);
        mdatom(Vector2, Vector2);
             
        int     id {0};
        double  m {1.0};
        double  radius {1.0};

        Vector2 r;
        Vector2 v;
        Vector2 f;

        /*void rInc(const Vector2& prova) {
            r.x_[0] += prova.x_[0];
            r.x_[1] += prova.x_[1];
        }; 
        */

};

class particles {

    public:
    
        //particles();
    
        void     printOutput( std::ostream& );
        void     add( mdatom );

        int      size()         { return atoms_.size(); };
        mdatom&  atom( int i )  { return atoms_[i];  };
    
    private:
    
        std::vector<mdatom> atoms_;

};

void    readfile( std::string, particles& );
void    printToFile( std::string, particles& );



#endif