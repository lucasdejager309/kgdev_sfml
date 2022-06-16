#include "collision.h"
#include "Player.h"

Player::Player(sf::Texture* texture, float moveForce, float drag, float maxSpeed, Vector2 bounds) {
    this->moveForce = moveForce;
    this->drag = drag;
    this->maxSpeed = maxSpeed;
    this->bounds = bounds;
    this->drag = drag;

    body.setSize(sf::Vector2f(200.f, 150.f));
    body.setOrigin(50, 50);
    body.setTexture(texture);
}

void Player::Update(float deltaTime) {
    Entity::Update(deltaTime);

    Vector2 moveInput = Vector2();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveInput.setX((moveInput.getX()-1.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveInput.setX((moveInput.getX()+1.f));

    //MOVE!!
    AddForce(moveInput, moveForce, deltaTime, true);
}