#include <cmath>

#include "atom.h"
#include "particles.h"


#ifndef VERLET_H
#define VERLET_H

class Verlet {

    private: 
        // members
        double   dt_{0.0} ;
        double   tmax{0.0};
        double   currentTime {0.000}; 
        double   beginTime {0.000};
        
        particles& parts_;

    private:
        // methods
        void     computeForces();

    public:

        // constructor
        Verlet( particles& );
        
        // getters and setters

        double  getdt()     const   { return dt_;           };
        double  getTime()   const   { return currentTime;   };
        double  getBegin()  const   { return beginTime;     };
        double  getTmax()   const   { return tmax;          };

        void    setdt    ( double t )   { dt_ = t; };
        void    setTimer ( double t )   { currentTime = t; };
        void    setTmax  ( double t )   { tmax = t; }
        
        void    stepper();

        void    status(int) const;
        void    printToFile(int);

};




#endif