#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"

class Vehicule {

    public:
        
        // Constructor;
        Vehicule();

        // Destructor.
        ~Vehicule(){};

        // Getter.
        PVector getPos() const {return this->pos;}
        PVector getVel() const {return this->vel;}
        double getMaxForce() const {return this->maxForce;}
        double getMaxSpeed() const {return this->maxSpeed;}

        // Integration.
        void update(sf::RenderWindow *window);
        void draw(sf::RenderWindow *window);

        // Methode to move.
        PVector seek(PVector target, bool arrival = false);  // Follow a target.
        PVector flee(PVector target);                        // Return the direction to escape the target. 
        PVector pursue(Vehicule target);                     // Predict next move.
        PVector evade(Vehicule target);                      // Predict next move.
        PVector arrive(PVector target);                      // Slow on target.
        PVector wander();                                    // Errer.

        // Deal with borders.
        void checkBorders();
        void edges();


    protected:
        PVector pos;
        PVector vel;
        double mass;
        const double maxSpeed = 3;
        const double maxForce = 0.7;
        double wanderTheta = M_PI/2;
};