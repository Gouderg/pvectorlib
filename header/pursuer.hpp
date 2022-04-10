#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "vehicule.hpp"

class Pursuer: public Vehicule {

    public:
        void update(PVector vel, PVector pos);
};