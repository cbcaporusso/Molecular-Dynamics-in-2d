#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "types.h"
#include "atom.h"

#ifndef PARTICLES_H
#define PARTICLES_H

class particles {

    public:
    
        //particles();
    
        void     printOutput(std::ostream&);
        int      add(mdatom);     
        void     randomAdd(int); 
		void	 initGaussianVel(double, double); // from a gaussian distribution 

        int      size()         	{ return atoms_.size(); };	
        mdatom&  atom(int i)  		{ return atoms_[i]; 	};
		mdatom&  operator[](int i) 	{ return atoms_[i]; 	};

		void 	 setBoxSize(Vector2 newbox) 	{ box = newbox; };
		Vector2	 getBoxSize()					{ return box;   };
        
        void     checkBoundaries();

        double   kinE();
        double   potE();

		//const Vector2  boxsize()  		{ Vector2& refbox = box; return refbox; };
		//double	 totKE ();
    
    private:
    
        std::vector<mdatom> atoms_;
		Vector2 box;

        friend class Verlet;

};

void readfile(std::string, particles& );

#endif