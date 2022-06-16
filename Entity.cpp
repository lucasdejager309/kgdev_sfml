#include "Entity.h"
#include "collision.h"
#include "math.h"

void Entity::Update(float deltaTime) {

}

void Entity::AddForce(Vector2 direction, float amount, float deltaTime, bool stayInBounds) {
    Vector2 force = direction*((amount)*mass)*deltaTime;
    Vector2 newMovement = movement + force;
    if (-maxSpeed < newMovement.magnitude() && newMovement.magnitude() < maxSpeed) {
        movement = newMovement;
    }

    if (direction == Vector2(0,0)) {
        movement = ApplyDrag(drag, movement);
    }

    //get new pos
    sf::RectangleShape newRect = body;
    newRect.setPosition(newRect.getPosition().x + movement.getX(), newRect.getPosition().y + movement.getY());

    if (!IsInBounds(bounds, &newRect) && stayInBounds) {
        movement = Vector2(0,0);
    }

    Vector2 newPosition = Vector2(body.getPosition()) + movement;
    body.setPosition(newPosition.getX(), newPosition.getY());
}

Vector2 Entity::ApplyDrag(float amount, Vector2 vector) {
    //x
    if (vector.getX() > 0) {
        vector.setX(std::max((vector.getX() - drag), 0.f));
    } else if (vector.getX() < 0) {
        vector.setX(std::min((vector.getX() + drag), 0.f));
    }
    //y
    if (vector.getY() > 0) {
        vector.setY(std::max((vector.getY() - drag), 0.f));
    } else if (vector.getY() < 0) {
        vector.setY(std::min((vector.getY() + drag), 0.f));
    }

    return vector;
}