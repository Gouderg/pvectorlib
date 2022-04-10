#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "vehicule.hpp"
#include "target.hpp"

class Pursuer: public Vehicule {

    public:
        void update(Vehicule target);
    
    protected:
        const double maxSpeed = 4;
};