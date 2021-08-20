#include <iostream>
#include <vector>

#include "types.h"

std::ostream& operator<<( std::ostream& os, const Vector2& vec) {
    os << vec.x_[0] << " " << vec.x_[1];
    return os;
} 

/* std::istream& operator>>( std::istream& is, const Vector2& vec) {
    is >> vec.x_ >> vec.y_;
    return is;
} */

Vector2::Vector2() { x_[0] = 0.0, x_[1] = 0.0; };
Vector2::Vector2(double x, double y) {
    x_[0] = x;
    x_[1] = y;
};


Vector2& Vector2::operator+=(const Vector2& right) {
    x_[0] += right.x_[0];
    x_[1] += right.x_[1]; 
    return *this;
}


Vector2 operator*(const double left, Vector2 right) {
        right.x_[0] *= left;
        right.x_[1] *= left;
        return right;
}

Vector2 operator*(Vector2 left, const double right) {
        left.x_[0] *= right;
        left.x_[1] *= right;
        return left;
}

Vector2 operator/(const double left, Vector2 right) {
        right.x_[0] /= left;
        right.x_[1] /= left;
        return right;
}

Vector2 operator/(Vector2 left, const double right) {
        left.x_[0] /= right;
        left.x_[1] /= right;
        return left;
}
