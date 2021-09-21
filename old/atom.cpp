#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "atom.h"

/*void atom::addAtom(double xin, double yin, double vxin, double vyin) {
//mo qua serve che pusha 
this->
}*/ 

atom::atom(double inx, double iny) {

	vx_ = 0.0; vy_ = 0.0;
	u_ = inx;
	y_ = iny;

}

int readDataFromFile(std::string filename, std::vector<atom> * particles) {
    
 	std::ifstream file(filename, std::ios::in);
	std::string line;

	if ( ! (file.is_open()) ) { std::cout << "Error: File does not exist." << std::endl; return 0; }

	while (std::getline(file,line)) {

		double xtemp{0.0},ytemp{0.0},vxtemp{0.0},vytemp{0.0};
		
		std::istringstream iss(line);
		iss >> xtemp >> ytemp;

		atom temp(xtemp,ytemp);
		particles->push_back(temp);


	}

    return 1;

}

void atom::print() {

	//std::cout << "# x\t y \t vx \t vy \t fx \t fy" << std::endl;
	std::cout << u_ << " " << y_ << " " << vx_ << " " << vy_ << std::endl;

}