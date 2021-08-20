/*
Simple program that perform molecular dynamics simulations in 2D

Claudio B. Caporusso
PhD student, University of Bary
cbcaporusso@gmail.com

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "atom.h"
#include "verlet.h"


int main() {

	//std::string filename;
    
	//std::cout << "Please insert a file name (Ctrl-D to stop):" <<std::endl;
	//std::cin  >> filename;
    //std::cout << "Please insert simulation duration (tmax):" <<std::endl;
	//std::cin  >> tmax;
    
    particles sim; 
    //readfile(filename, sim);
    
    mdatom temp {Vector2{0.0, 0.0}, Vector2{0.1, 0.2}};
    sim.add(temp);

    Verlet verlet;

    int step {0};
    double tmax{1.0};

    std::cout << "Running simulation for " << tmax << " timesteps." << std::endl;

    while (verlet.getTime() < tmax ) {

        verlet.printStatus(sim);
        
        /*if ( step%1000 == 0 ) {

            std::string outname ("xy.dump.");
            outname+=std::to_string(verlet.getTime());

            printToFile(outname,sim);

        }*/

        verlet.stepper(sim); 
        step++;
 
    };
    
    return 0;

}