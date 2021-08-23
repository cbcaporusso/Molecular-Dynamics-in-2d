#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "atom.h"
#include "verlet.h"

/*
Simple program that perform molecular dynamics simulations in 2D

Claudio B. Caporusso
PhD student, University of Bary
cbcaporusso@gmail.com

*/

int main() {

	//std::string filename;   
	//std::cout << "Please insert a file name (Ctrl-D to stop):" <<std::endl;
	//std::cin  >> filename;
    //std::cout << "Please insert simulation duration (tmax):" <<std::endl;
	//std::cin  >> tmax;
    
    // initialize particles in the box
    
    particles parts; 
    parts.setBoxSize( {10.0, 10.0} );
    parts.randomAdd(50);
    parts.initGaussianVel(0,1.0);

    // set simulation up 
    
    Verlet sim(parts);
    sim.setdt(0.005);
    sim.setTmax(15.0);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << "Running a simulation of " << parts.size() << " particles for "\
    << sim.getTmax() <<  " ts in a box of size " << parts.getBoxSize().u_[0] << "x" \
    << parts.getBoxSize().u_[1] << " with periodic boundary conditions." << std::endl;

    // start simulation

    while ( sim.getTime() < sim.getTmax() ) {
        
        sim.status();  
        sim.printToFile(1000);
        sim.stepper();

    };

    return 0;

}