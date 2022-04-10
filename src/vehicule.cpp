#include "../header/vehicule.hpp"

// Constructor.
Vehicule::Vehicule() {
    this->pos = PVector(SIZE_W/2, SIZE_H/2);
    this->vel = PVector(0,0);
}

void Vehicule::update() {
    PVector acc = PVector(0, 0);
    PVector gravity = PVector(0, 9.81);
    PVector wind = PVector(-2, -0.1);

    acc.applyForce(gravity);
    acc.applyForce(wind);

    this->vel.add(acc);
    this->vel.limit(MAX_SPEED);
    checkBorders();
    this->pos.add(vel);

}

void Vehicule::checkBorders() {
    if ((this->pos.getX() > SIZE_W) || (this->pos.getX() < 0)) {this->vel.mulX(-1);}
    if ((this->pos.getY() > SIZE_H) || (this->pos.getY() < 0)) {this->vel.mulY(-1);}

}

void Vehicule::draw(sf::RenderWindow *window) {

    sf::ConvexShape convex;

    convex.setPointCount(3);
    convex.setPoint(0, sf::Vector2f(SIZE_VEHICULE, 0.f));
    convex.setPoint(1, sf::Vector2f(-SIZE_VEHICULE, -SIZE_VEHICULE/2));
    convex.setPoint(2, sf::Vector2f(-SIZE_VEHICULE, SIZE_VEHICULE/2));

    convex.setPosition(pos.getX(), pos.getY());
    convex.setRotation(vel.headings2D());
    convex.setFillColor(sf::Color::Yellow);
    window->draw(convex);
}