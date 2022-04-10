#include "../header/pursuer.hpp"

void Pursuer::update(Vehicule target) {
    PVector acc = PVector(0, 0);

    // acc.add(PVector::pursue(vel, pos, this->vel, this->pos));
    acc.add(pursue(target));

    this->vel.add(acc);
    this->vel.limit(this->maxSpeed);
    this->pos.add(this->vel);

    edges();

    if (PVector::dist(this->pos, target.getPos()) < SIZE_VEHICULE * 2) {
        this->pos.setX(rand() % SIZE_W);
        this->pos.setY(rand() % SIZE_H);

    }
}