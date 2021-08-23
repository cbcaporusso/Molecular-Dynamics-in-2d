#include <iostream>
#include <vector>

#ifndef TYPES_H
#define TYPES_H

struct Vector2 {
        
        double u_[2] = {0.0, 0.0};      // data member array
        
        // constructor
        Vector2() { u_[0] = 0.0, u_[1] = 0.0; };
        Vector2 (double x, double y) { u_[0] = x; u_[1] = y;};

        // stream operator        
        //friend std::ostream&  operator<<  ( std::ostream& , const Vector2& );
        
        // assignment operator
        Vector2&  operator=   (const Vector2&);
        Vector2&  operator+=  (const Vector2&); // perche qui passiamo il riferimento ? 
        
        // binary operators
        Vector2 operator+ (const Vector2&) const; // e qui no ?
        Vector2 operator- (const Vector2&) const; 
        double  operator* (const Vector2&) const; 

};

// global non-member functions for commutative operators

Vector2 operator*(const double , Vector2 );
Vector2 operator*(Vector2 , const double );
Vector2 operator/(const double , Vector2 );
Vector2 operator/(Vector2 , const double );

// global non-member stream function
std::ostream& operator<<( std::ostream& , const Vector2& );

#endif