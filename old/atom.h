#include <iostream>
#include <vector>

#ifndef ATOM_H
#define ATOM_H

class atom {
    public:
        //Constructor
        atom(); //standard
        atom(double, double);
   
        void print();
        void addAtom(double, double, double, double);    

    private:
 
           double u_;
           double y_;

           double vx_;
           double vy_;

           double fx;
           double fy;
    //private: 


};

int readDataFromFile(std::string, std::vector<atom> * );



#endif