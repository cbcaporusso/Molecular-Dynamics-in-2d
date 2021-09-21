#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <random>

#include "atom.h"
#include "types.h"
#include "particles.h"

// add an atom to the container
int particles::add( mdatom new_atom ) {
    
    // check for overlaps
	double dd;
    for (int i=0; i<size(); i++) {
        dd = atoms_[i].PBCdistance( new_atom, box );
        if ( dd < new_atom.radius ) {
            std::cerr << "Error: Particle Overlap detected" << std::endl;
            return 0;
        }
    }

    // add atom to the vector
    atoms_.push_back( new_atom );
    int last{ size() };
	atoms_[ last-1 ].id = last;

    return 1;
}

void particles::randomAdd( int natoms ) {
    
    double atoms_added {0.0};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution_x(0.0,box.u_[0]);
    std::uniform_real_distribution<double> distribution_y(0.0,box.u_[1]);

    Vector2 tmp_atom;

    while ( atoms_added < natoms) {
        tmp_atom = Vector2(distribution_x(generator), distribution_y(generator));          
        if ( add(tmp_atom) ) atoms_added++;
    }
}

void particles::initGaussianVel( double mean, double var ) {
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution_x(mean,var);
    std::normal_distribution<double> distribution_y(mean,var);

    for ( int i=0; i < size() ; i++ ) {
        atoms_[i].v = Vector2( distribution_x(generator), distribution_y(generator) );
    }
} 

void particles::printOutput( std::ostream& os ) {
    os << "Id x y vx vy fx fy" << std::endl;
    os << std::endl;
	for ( int i=0; i < size() ; i++ ) os << atoms_[i].id << " " << atoms_[i].r << " " << atoms_[i].v << " " << atoms_[i].f << std::endl;
}

double particles::kinE() {
    double totkine{0.0};
    for ( int i = 0; i < this->size() ; i++ ) {
        totkine += 0.5 * atoms_[i].m * ( atoms_[i].v * atoms_[i].v ); 
    }
    return totkine;
}

void particles::checkBoundaries() {
    
    for ( int i = 0; i < this->size() ; i++ ) {
        if (atoms_[i].r.u_[0] > this->box.u_[0] || atoms_[i].r.u_[0] < 0.0 ) {
            std::cerr << "Error. Lost atom from the box." << std::endl;
            std::exit(1);
        }
        if (atoms_[i].r.u_[1] > this->box.u_[1] || atoms_[i].r.u_[1] < 0.0 ) {
            std::cerr << "Error. Lost atom from the box." << std::endl;
            std::exit(1);
        }
    }

}

void readfile(std::string filename, particles& parts) { 

	std::ifstream file(filename, std::ios::in);
	std::string line;
	
	if ( ! (file.is_open()) ) { std::cout << "Error: File does not exist." << std::endl; exit(1); }
	
	while (std::getline(file,line)) {
		double xtemp{0.0},ytemp{0.0},vxtemp{0.0},vytemp{0.0};
		std::istringstream iss(line);
		iss >> xtemp >> ytemp >> vxtemp >> vytemp;
		mdatom temp_atom { Vector2 {xtemp,ytemp}, Vector2 {vxtemp,vytemp} }; 
		parts.add(temp_atom);
	}

}



