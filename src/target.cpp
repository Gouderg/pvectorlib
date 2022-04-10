#include "../header/target.hpp"

void Target::update() {
    PVector acc = PVector(2, 1);

    this->vel.add(acc);
    this->vel.limit(MAX_SPEED_TARGET);
    this->pos.add(vel);
    edges();

}


void Target::draw(sf::RenderWindow *window) {

    sf::CircleShape circle(20.f);
    circle.setPosition(pos.getX(), pos.getY());
    circle.setFillColor(sf::Color::Red);
    window->draw(circle);
}