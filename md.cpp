#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "atom.h"
#include "verlet.h"
#include "particles.h"

/*

Simple program to perform molecular dynamics simulations in 2D

Claudio B. Caporusso
PhD student, University of Bari

cbcaporusso@gmail.com

*/

int main() {

    // initialize particles in the box
    
    particles parts; 

    Vector2     box {100.0, 100.0};    // simulation box size; use Vector2 type
    int         num_particles {100};     

    double      v_avg {0.0};         // parameter for the gaussian distribution 
    double      v_sigma {0.01};       // for the particles' velocities 

    parts.setBoxSize(box);
    parts.randomAdd(num_particles);
    parts.initGaussianVel(v_avg,v_sigma);

    // set simulation up 
    
    Verlet sim(parts);     // creation of the obj sim, takes as input a 
                           // reference to the particles' container

    double dt {0.005};
    double tmax {50.0};

    sim.setdt(dt);
    sim.setTmax(tmax);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(1);

    std::cout << "Running a simulation of " << parts.size() << " particles for "\
    << sim.getTmax() <<  " ts in a box of size " << parts.getBoxSize().u_[0] << "x" \
    << parts.getBoxSize().u_[1] << " with periodic boundary conditions." << std::endl;
    std::cout << std::endl;

    // start simulation

    int infos_step = 1000;  // n timesteps to print simulation infos
    
    while ( sim.getTime() < sim.getTmax() ) {
        
        sim.status(infos_step);         // print status on stdout and positions  
        sim.printToFile(infos_step);    // on file every info_step times 

        sim.stepper();                  // velocity verlet integration step 

    };

    return 0;

}