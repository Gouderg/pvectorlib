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
        PVector seek(PVector target);  // Follow a target.
        PVector flee(PVector target);  // Return the direction to escape the target. 
        PVector pursue(Vehicule target);  // Predict next move.
        PVector evade(Vehicule target);  // Predict next move.

        // Deal with borders.
        void checkBorders();
        void edges();


    protected:
        PVector pos;
        PVector vel;
        double mass;
        const double maxSpeed = 10;
        const double maxForce = 0.3;
};