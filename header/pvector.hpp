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
        void add(PVector v);                                    // Add one Pvector to the current Pvector.
        void add(double n);                                     // Add constante to the current Pvector.
        static PVector add(PVector v1, PVector v2);             // Return the Pvector addition between two Pvector.
        static PVector add(PVector v, double n);                // Return the Pvector addition between Pvector and constante.
        static PVector add(PVector v1, PVector v2, PVector v3); // Return the Pvector addition between three Pvector.

        // Sub.
        void sub(PVector v);                                    // Sub one Pvector to the current Pvector.
        void sub(double n);                                     // Sub constante to the current Pvector.
        static PVector sub(PVector v1, PVector v2);             // Return the Pvector substraction between two Pvector.
        static PVector sub(PVector v, double n);                // Return the Pvector substraction between Pvector and constante.
        static PVector sub(PVector v1, PVector v2, PVector v3); // Return the Pvector substraction between three Pvector.


        double headings2D();                                    // Find the angle between the velocity and the position.

    private:
        double x, y, z;
};