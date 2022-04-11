#pragma once

#include <iostream>
#include <cmath>

class PVector {
    public:
        // Constructor.
        PVector(){};
        PVector(const double x, const double y);                    // 2D.
        PVector(const double x, const double y, const double z);    // 3D.

        // Destructor.
        ~PVector();

        // Getter.
        double getX() const {return this->x;}
        double getY() const {return this->y;}
        double getZ() const {return this->z;}

        // Setter.
        void setX(const double x) {this->x = x;}
        void setY(const double y) {this->y = y;}
        void setZ(const double z) {this->z = z;}

        // Add.
        void add(PVector v);                                            // Add one Pvector to the current Pvector.
        void add(double n);                                             // Add constante to the current Pvector.
        static PVector add(PVector v1, PVector v2);                     // Return the Pvector addition between two Pvector.
        static PVector add(PVector v, double n);                        // Return the Pvector addition between Pvector and constante.
        static PVector add(PVector v1, PVector v2, PVector v3);         // Return the Pvector addition between three Pvector.

        // Sub.
        void sub(PVector v);                                            // Sub one Pvector to the current Pvector.
        void sub(double n);                                             // Sub constante to the current Pvector.
        static PVector sub(PVector v1, PVector v2);                     // Return the Pvector substraction between two Pvector.
        static PVector sub(PVector v, double n);                        // Return the Pvector substraction between Pvector and constante.
        static PVector sub(PVector v1, PVector v2, PVector v3);         // Return the Pvector substraction between three Pvector.

        // Mul.
        void mulX(double n) {this->x *= n;}                             // Multiply x by constante.
        void mulY(double n) {this->y *= n;}                             // Multiply y by constante.
        void mulZ(double n) {this->z *= n;}                             // Multiply z by constante.

        void mul(double n);

        // Div.
        void div(double n);

        // Others.
        double mag();                                                               // Return the length of a vector (magnitude).
        void setMag(double max);                                                    // Set the magnitude to the maximun.
        void normalize();                                                           // Normalize each components of a vector.
        void limit(double max);                                                     // Limit vector.
        void applyForce(PVector force, double masse);                               // Apply a force with the mass.
        double headings2D();                                                        // Find the angle between the velocity and the position.
        static double dist(PVector v1, PVector v2);                                 // Return the distance between two Pvector.
        static double dotProduct(PVector v1, PVector v2);                           // Return the dot product between two PVector.
        static double angleBetween(PVector v1, PVector v2);                         // Return the angle between two PVector.
        static PVector scalarProjection(PVector v1, PVector v2);                    // Return the scalar Projection.
        static PVector rotate2D(PVector v1, double theta);                          // Return the rotate Pvector.
        static double angleWith(PVector ref_pos, PVector target, double theta);   // Return the angle between the current PVector and another one.

    private:
        double x, y, z;
};