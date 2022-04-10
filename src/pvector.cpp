#include "../header/pvector.hpp"
// --
// Constructor.
// --

PVector::PVector(const double x, const double y) {
    this->x = x;
    this->y = y;
}


PVector::PVector(const double x, const double y, const double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Destructor.
PVector::~PVector() {
    // std::cout << "Call PVector Destructor" << std::endl;
}

// --
// Add function.
// --

void PVector::add(PVector v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void PVector::add(double n) {
    this->x += n;
    this->y += n;
    this->z += n;
}

PVector PVector::add(PVector v1, PVector v2) {
    PVector v;
    
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    
    return v;
}

PVector PVector::add(PVector v1, double n) {
    PVector v;
    
    v.x = v1.x + n;
    v.y = v1.y + n;
    v.z = v1.z + n;
    
    return v;
}

PVector PVector::add(PVector v1, PVector v2, PVector v3) {
    PVector v;
    
    v.x = v1.x + v2.x + v3.x;
    v.y = v1.y + v2.y + v3.y;
    v.z = v1.z + v2.z + v3.z;
    
    return v;
}

// --
// Sub function.
// --

void PVector::sub(PVector v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

void PVector::sub(double n) {
    this->x -= n;
    this->y -= n;
    this->z -= n;
}

PVector PVector::sub(PVector v1, PVector v2) {
    PVector v;
    
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;
    
    return v;
}

PVector PVector::sub(PVector v1, double n) {
    PVector v;
    
    v.x = v1.x - n;
    v.y = v1.y - n;
    v.z = v1.z - n;
    
    return v;
}

PVector PVector::sub(PVector v1, PVector v2, PVector v3) {
    PVector v;
    
    v.x = v1.x - v2.x - v3.x;
    v.y = v1.y - v2.y - v3.y;
    v.z = v1.z - v2.z - v3.z;
    
    return v;
}

// --
// headings2D : Find the angle forr orientation
// --

double PVector::headings2D() {
    return atan2(this->y, this->x) * 180/M_PI;
}