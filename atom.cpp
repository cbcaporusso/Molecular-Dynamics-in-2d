#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "atom.h"
#include "types.h"


void particles::add(mdatom atom) {
	atoms_.push_back(atom);
}

void particles::printOutput( std::ostream& os ) {
	for ( int i=0; i < size() ; i++ ) os << atom(i).r << " " << atom(i).v << std::endl;
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

void printToFile( std::string filename, particles& parts ) {

	std::ofstream file;
	file.open(filename);
	parts.printOutput(file);

}


mdatom::mdatom(Vector2 pos, Vector2 vel) {

	r = pos;  
	v = vel;

}

mdatom::mdatom(Vector2 pos) {

	r = pos; 
}