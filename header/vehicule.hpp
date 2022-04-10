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

        void update(sf::RenderWindow *window);
        void draw(sf::RenderWindow *window);
        void checkBorders();
        void edges();


    protected:
        PVector pos;
        PVector vel;
        double mass;
};