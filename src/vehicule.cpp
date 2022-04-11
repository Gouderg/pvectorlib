#include "../header/vehicule.hpp"

// Constructor.
Vehicule::Vehicule() {
    this->pos = PVector(rand() % SIZE_W, rand() % SIZE_H);
    this->vel = PVector(0,0);
}

void Vehicule::update(sf::RenderWindow *window) {
    PVector acc = PVector(0, 0);


    // Apply seek.
    // sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    // acc.add(this->arrive(PVector(mouse.x, mouse.y)));

    acc.add(this->wander());

    this->vel.add(acc);
    this->vel.limit(this->maxSpeed);
    this->pos.add(vel);
    edges();

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

// --
// seek : Return the direction to go to the target.
// --

PVector Vehicule::seek(PVector target, bool arrival) {
    PVector force = PVector::sub(target, this->pos);

    double desiredSpeed = this->maxSpeed;

    if (arrival) {
        double slowRadius = this->maxSpeed * (this->maxSpeed / this->maxForce + 1) / 2;
        // double slowRadius = 100;
        double distance  = force.mag();
        if (distance < slowRadius) {
            // map(value, start1, stop1, start2, stop2)
            // start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
            desiredSpeed =  this->maxSpeed * (distance / slowRadius);
        }
    }

    force.setMag(desiredSpeed);
    force.sub(this->vel);
    force.limit(this->maxForce);
    return force;
}

// -- 
// flee : Return the direction to escape the target.
// --

PVector Vehicule::flee(PVector target) {
    PVector force = this->seek(target);
    force.mul(-1);
    return force;
}

// --
// pursue : Predict next move.
// --
PVector Vehicule::pursue(Vehicule target) {
    PVector vel = target.getVel();
    vel.mul(10);
    return this->seek(PVector::add(target.getPos(), vel));
}

// --
// evade : Evade from the target.
// --

PVector Vehicule::evade(Vehicule target) {
    PVector pursuit = this->pursue(target);
    pursuit.mul(-1);
    return pursuit;
}

// --
// arrive : Slow on target
// --

PVector Vehicule::arrive(PVector target) {
    return this->seek(target, true);
}

// -- 
// wander : permet de errer.
// --

PVector Vehicule::wander() {
    PVector wanderPoint = this->getVel();
    wanderPoint.setMag(100);
    wanderPoint.add(this->getPos());

    int wanderRadius = 50;
    double theta = this->wanderTheta + this->vel.headings2D();
    wanderPoint.add(PVector(wanderRadius * cos(theta * M_PI / 180.0), wanderRadius * sin(theta * M_PI / 180.0)));
    PVector steer = PVector::sub(wanderPoint, this->pos);
    steer.setMag(this->maxForce);

    this->wanderTheta += (rand() % 7 + (- 3.0)) / 10.0;

    return steer;
}