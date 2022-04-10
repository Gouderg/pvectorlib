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

        void update();
        void draw(sf::RenderWindow *window);
        void checkBorders();


    private:
        PVector pos;
        PVector vel;
        double mass;
};