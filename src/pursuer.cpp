#include "../header/pursuer.hpp"

void Pursuer::update(PVector vel, PVector pos) {
    PVector acc = PVector(0, 0);

    // acc.add(PVector::pursue(vel, pos, this->vel, this->pos));
    acc.add(PVector::pursue(vel, pos, this->vel, this->pos));

    this->vel.add(acc);
    this->vel.limit(MAX_SPEED);
    this->pos.add(this->vel);

    edges();

    if (PVector::dist(this->pos, pos) < SIZE_VEHICULE * 2) {
        this->pos.setX(rand() % SIZE_W);
        this->pos.setY(rand() % SIZE_H);

    }
}