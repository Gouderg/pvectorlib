#include "../header/vehicule.hpp"

// Constructor.
Vehicule::Vehicule() {
    this->pos = PVector(SIZE_W/2, SIZE_H/2);
    this->vel = PVector(1,1);
}

void Vehicule::update() {
    PVector acc = PVector(0,1);

    this->vel.add(acc);
    this->pos.add(vel);
}

void Vehicule::draw(sf::RenderWindow *window) {

    // create an empty shape
    sf::ConvexShape convex;

    // resize it to 5 points
    convex.setPointCount(3);

    convex.setPoint(0, sf::Vector2f(SIZE_VEHICULE, 0.f));
    convex.setPoint(1, sf::Vector2f(-SIZE_VEHICULE, -SIZE_VEHICULE/2));
    convex.setPoint(2, sf::Vector2f(-SIZE_VEHICULE, SIZE_VEHICULE/2));

    convex.setPosition(pos.getX(), pos.getY());
    convex.setRotation(vel.headings2D());
    convex.setFillColor(sf::Color::Yellow);
    window->draw(convex);
}