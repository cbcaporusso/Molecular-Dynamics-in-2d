#include <iostream>
#include <vector>

#ifndef TYPES_H
#define TYPES_H

struct Vector2 {

        Vector2();
        Vector2(double x,double y);

        double x_[2] = {0.0, 0.0};

        friend std::ostream&   operator<<  ( std::ostream& , const Vector2& );
        Vector2&  operator+=  (const Vector2&);

};

Vector2  operator*  (const double, Vector2);
Vector2  operator*  (Vector2, const double);

Vector2  operator/  (const double, Vector2);
Vector2  operator/  (Vector2, const double);

#endif