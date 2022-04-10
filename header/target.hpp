#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "vehicule.hpp"

class Target: public Vehicule {

    public:
        void update();
        void draw(sf::RenderWindow *window);
    
};