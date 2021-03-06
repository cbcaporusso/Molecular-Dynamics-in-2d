#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "verlet.h"
#include "atom.h"
#include "types.h"

Verlet::Verlet(particles &simparts) : parts_(simparts) {}  // constructor

void Verlet::stepper()  {  
    // Full Verlet integration step
    // it connsist of two half steps 

    const double dt = getdt();
    
    for (int i=0; i < parts_.size(); i++) {    // first half integration step    

        mdatom& atm = parts_[i];

        atm.r  +=  dt * atm.v + 0.5 * dt * dt * atm.f / atm.m;
        atm.v  +=  0.5 * dt * atm.f / atm.m;
        atm.PBCadjust( parts_.box );  

    }
    
    //parts_.checkBoundaries();    // check if atoms are inside the box
    this->computeForces();    // compute forces with new positions
    
    for (int i=0; i < parts_.size(); i++) {     // second half integration step 

        mdatom& atm = parts_[i];
    
        atm.v  +=  0.5 * dt * atm.f / atm.m;

    }

    setTimer(currentTime+dt);    // increment simulation timer

}

void Verlet::computeForces() {
    // Only LJ implemented at this moment

    // const double ecut {5.0}; // ?
    // const double dcut {5.0}; 
    
    double eps {1.0};
    double dd{0.0}, r6i{0.0}, e{0.0}, f{0.0};
    Vector2 dr{0.0,0.0};
    
    for (int i=0; i < parts_.size(); i++) {
        mdatom& ai = parts_[i];
        
        for(int j=0; j < parts_.size(); j++) {
            mdatom& aj = parts_[j];

            dd      =   ai.PBCdistance( aj, parts_.box ); 
            //  lennard-jones pot and force computation 
            dr      =   ai.r - aj.r;    
            r6i     =   ai.radius / (dd*dd*dd);
            f       =   48 * eps * ( r6i*r6i - 0.5 * r6i );

            ai.f  =     dr * ( f / dd );
            aj.f  =     dr * ( - f / dd );

            //e     +=    4  * ( r6i*r6i - r6i) - ecut;
            
        }
    }
}


void Verlet::status( int print_steps ) const {

    if ( this->beginTime == this->currentTime ) {
        std::cout << "ts kine" << std::endl;
    }
    
    int computed_steps = static_cast<int>( ( currentTime - beginTime ) / dt_ );

    if ( computed_steps % print_steps == 0 ) {
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << this->getTime() << " " << parts_.kinE() << std::endl;
    }

}

void Verlet::printToFile( int print_steps ) {
    
    int computed_steps = static_cast<int>( ( currentTime - beginTime ) / dt_ ); 

    if ( computed_steps % print_steps == 0 ) {
        
        std::string outname ("xy.dump_");
        outname+=std::to_string( currentTime );
        outname+=".dat";
        
        std::ofstream file;
    	file.open(outname);
	    
        parts_.printOutput(file);

    }

}

