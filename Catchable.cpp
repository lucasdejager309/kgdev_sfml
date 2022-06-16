#include "Catchable.h"
#include <iostream>
#include <list>
#include <random>

Catchable::Catchable(sf::Texture* texture, Vector2 size, float maxSpeed, float moveForce, int worthPoints, Vector2 bounds) {
    body.setTexture(texture);

    this->maxSpeed = maxSpeed;
    this->moveForce = moveForce;
    this->worthPoints = worthPoints;

    this->drag = 20;

    body.setSize(sf::Vector2(size.getX(), size.getY()));
    body.setOrigin(size.getX()/2, size.getY()/2);
    this-> bounds = bounds;

    int directions[2] = {-1, 1};
    direction = directions[RandomRange(0, 1)];
}

void Catchable::Update(float deltaTime) {
    Entity::Update(deltaTime);

    AddForce(VectorDown(), moveForce, deltaTime, false);
    RandomSideMovement(deltaTime);
}

void Catchable::RandomSideMovement(float deltaTime) {
    if (timer < timeToMove) {
        timer += deltaTime;
    } else {
        timer = 0;
        timeToMove = timebetweenMovements.Random();

        //apply force
        int directions[2] = {-1, 1};
        direction = directions[RandomRange(0, 1)];
    }

    AddForce(Vector2(direction, 0), 20, deltaTime, false);

    //MAKE CATCHABLE STAY ON SCREEN
    if (body.getPosition().x < (0 + body.getSize().x/2)) {
        body.setPosition(0+body.getSize().x/2, body.getPosition().y);

        direction = -direction;
        movement = Vector2(0, movement.getY());
    } else
    if (body.getPosition().x > (bounds.getX() - body.getSize().x/2)) {
        body.setPosition(bounds.getX()-body.getSize().x/2, body.getPosition().y);

        direction = -direction;
        movement = Vector2(0, movement.getY());
    }
}


