#include <iostream>
#include "verlet.h"


void Verlet::stepper(particles& parts) {

    const double dt = getdt();
    
    for (int i=0; i < parts.size(); i++) {

        //std::cout << parts.atom(i).r << std::endl;
        
        mdatom& atm = parts.atom(i);

        atm.r  +=  dt * atm.v;
        atm.v  +=  0.5 * dt * atm.f / atm.m;

 
    }

    setTimer(currentTime+dt);
    
}

/* void Verlet::computeForces(particles& parts) {
    // Only LJ implemented at this moment
    for (int i=0; i < parts.size(); i++) {
    }
} */

void Verlet::printStatus(particles& parts) const {
    //std::cout << "Step \t Energy " << std::endl;
    if ( getTime() == getBegin() ) {
        std::cout << "Number of atoms: " << parts.size() << std::endl;
        std::cout << "Id x y vx vy" << std::endl;

    }

    std::cout << "ts: " << getTime() << std::endl;
    
    for (int i=0; i < parts.size(); i++) {
        std::cout << parts.atom(i).id << " " << parts.atom(i).r << " " << parts.atom(i).v << std::endl; 
    }
}

