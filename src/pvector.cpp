#include "../header/pvector.hpp"
// --
// Constructor.
// --

PVector::PVector(const double x, const double y) {
    this->x = x;
    this->y = y;
    this->z = 0;    // Avoid surprise with magnitude.
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
// mul : Mulitplication between constante and the current Pvector
// --

void PVector::mul(double n) {
    this->x *= n;
    this->y *= n;
    this->z *= n;
}


// --
// div : Division between constante and the current Pvector
// --

void PVector::div(double n) {
    this->x /= n;
    this->y /= n;
    this->z /= n;
}


// --
// mag : Return the length of a vector
// --

double PVector::mag() {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

// --
// setMag : Set the magnitude to the maximun.
// --

void PVector::setMag(double max) {
    this->normalize();
    this->mul(max);
}

// --
// normalize : Normalize each components of a vector.
// --

void PVector::normalize() {
    double magnitude = this->mag();
    if (magnitude != 0) {
        this->div(magnitude);
    }
}

// --
// limit : Limit the magnitude of a vector.
// --

void PVector::limit(double max) {
    if (this->mag() > max) {
        this->normalize();
        this->mul(max);
    }
}

// -- 
// applyForce : Apply a force with a mass
// --

void PVector::applyForce(PVector force, double masse) {
    force.div(masse);
    this->add(force);
}

// --
// dist : Return the distance between two pvector.
// --

double PVector::dist(PVector v1, PVector v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y,2) + pow(v1.z - v2.z,2));
}


// --
// headings2D : Find the angle forr orientation
// --

double PVector::headings2D() {
    return atan2(this->y, this->x) * 180/M_PI;
}

// --
// dotProduct : Return the dot product between two PVector.
// --

double PVector::dotProduct(PVector v1, PVector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// --
// angleBetween : Return the angle between two PVector.
// --

double PVector::angleBetween(PVector v1, PVector v2) {
    return acos(dotProduct(v1, v2) / (v1.mag() * v2.mag())) * 180/M_PI;
}

// --
// scalarProjection.
// --
PVector PVector::scalarProjection(PVector v1, PVector v2) {
    v2.normalize();
    v2.mul(dotProduct(v1, v2));
    return v2;
}

// --
// rotate2D : Return a rotate pvector with that |cos(theta) -sin(theta)|  
//                                              |sin(theta)  cos(theta)|        
// --

PVector PVector::rotate2D(PVector v1, double theta) {
    // Convert degrees to radians.
    theta = theta * M_PI / 180.0;
    
    PVector v;

    v.x = v1.x * cos(theta) + v1.y * sin(theta);
    v.y = v1.x * (-sin(theta)) + v1.y * cos(theta);
    
    return v;
}

// --
// angleWith : Return the angle between the current PVector and another one.
// --

double PVector::angleWith(PVector ref_pos, PVector target, double theta) {

    PVector v;

    // Change the referentiel.
    v = sub(target, ref_pos);

    // Rotate the Pvector.
    v = rotate2D(v, theta);

    return angleBetween(v, PVector(1, 0, 0));
}