#include "atom.h"

#ifndef VERLET_H
#define VERLET_H

class Verlet {

    private: 

    double   dt_{0.1} ;
    double   gamma_{1}  ;
    double   currentTime {0.000}; 
    double   beginTime {0.000};
    Vector2  box; 


    public:

        //Verlet();
        
        double  getdt() const       { return dt_; };
        double  getTime() const     { return currentTime; };
        double  getBegin() const    { return beginTime; };
        void    setTimer(double t)  { currentTime = t; };
        
        void    printStatus(particles&) const;
        void    stepper(particles&);
        
        //void    computeForces(particles&, );

};

#endif