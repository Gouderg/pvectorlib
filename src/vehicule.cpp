#include "../header/vehicule.hpp"

// Constructor.
Vehicule::Vehicule() {
    this->pos = PVector(rand() % SIZE_W, rand() % SIZE_H);
    this->vel = PVector(0,0);
}

void Vehicule::update(sf::RenderWindow *window) {
    PVector acc = PVector(0, 0);


    // Apply seek.
    sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    acc.add(PVector::seek(PVector(mouse.x, mouse.y), this->vel, this->pos));
    // acc.add(PVector::flee(PVector(mouse.x, mouse.y), this->vel, this->pos));

    this->vel.add(acc);
    this->vel.limit(MAX_SPEED);
    this->pos.add(vel);
    checkBorders();

}

// Bounces on border.
void Vehicule::checkBorders() {

    // X.
    if (this->pos.getX() > SIZE_W) {

        this->pos.setX(SIZE_W);
        this->vel.mulX(-1);

    } else if (this->pos.getX() < 0) {
        this->pos.setX(0);
        this->vel.mulX(-1);
    }

    // Y.
    if (this->pos.getY() > SIZE_H) {

        this->pos.setY(SIZE_H);
        this->vel.mulY(-1);

    } else if (this->pos.getY() < 0) {
        this->pos.setY(0);
        this->vel.mulY(-1);
    }

    // Z.
    if (this->pos.getZ() > SIZE_P) {

        this->pos.setZ(SIZE_P);
        this->vel.mulZ(-1);

    } else if (this->pos.getZ() < 0) {
        this->pos.setZ(0);
        this->vel.mulZ(-1);
    }
}

// Go to the other side.
void Vehicule::edges() {
    // X.
    if (this->pos.getX() > SIZE_W) {
        this->pos.setX(0);
    } else if (this->pos.getX() < 0) {
        this->pos.setX(SIZE_W);
    }

    // Y.
    if (this->pos.getY() > SIZE_H) {
        this->pos.setY(0);
    } else if (this->pos.getY() < 0) {
        this->pos.setY(SIZE_H);
    }

    // Z.
    if (this->pos.getZ() > SIZE_P) {
        this->pos.setZ(0);
    } else if (this->pos.getZ() < 0) {
        this->pos.setZ(SIZE_P);
    }
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