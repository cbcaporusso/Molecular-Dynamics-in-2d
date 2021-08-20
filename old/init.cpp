/*
Simple program that perform molecular dynamics simulations in 2D

Claudio B. Caporusso
PhD student, University of Bary
cbcaporusso@gmail.com

*/

#include <iostream>
#include <vector>
#include <string>
#include "atom.h"
#include "verlet.h"


int main() {

	std::string filename;

	std::cout << "Please insert a file name (Ctrl-D to stop):"<<std::endl;
	std::cin >> filename;
    
    //Verlet MDSimulation; 
    
    std::vector<atom> particles; 

    if ( ! readDataFromFile(filename, &particles) ) {
        exit(0);
    }
    
    for (int i=0;i<particles.size();i++) {
        particles.at(i).print();
    }
    
    return 0;

}