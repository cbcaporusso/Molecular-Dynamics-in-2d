#include <iostream>
#include <vector>

#include "types.h"

Vector2& Vector2::operator= (const Vector2& rhs)  {
        //Check for self-assignment
        if (this == &rhs) return *this;
        u_[0] = rhs.u_[0];
        u_[1] = rhs.u_[1];
        return *this;
}

Vector2& Vector2::operator+=(const Vector2& right) {
    u_[0] += right.u_[0];
    u_[1] += right.u_[1]; 
    return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs) const {
    return Vector2(u_[0]+rhs.u_[0],u_[1]+rhs.u_[1]);
}

Vector2 Vector2::operator-(const Vector2& rhs) const {
    return Vector2(u_[0]-rhs.u_[0],u_[1]-rhs.u_[1]); 
}

double Vector2::operator*(const Vector2& rhs) const {
    return u_[0]*rhs.u_[0]+u_[1]*rhs.u_[1]; 
}

Vector2 operator*(const double left, Vector2 right) {
        right.u_[0] *= left;
        right.u_[1] *= left;
        return right;
}
Vector2 operator*(Vector2 left, const double right) {
        return right * left;
}
Vector2 operator/(const double left, Vector2 right) {
        right.u_[0] /= left;
        right.u_[1] /= left;
        return right;
}
Vector2 operator/(Vector2 left, const double right) {
        return right * left;
}

// non serve ci sia friend perche tanto i data members sono pubblici 

std::ostream& operator<<( std::ostream& os, const Vector2& vec) {
    os << vec.u_[0] << " " << vec.u_[1];
    return os;
} 

