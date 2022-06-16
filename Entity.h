#pragma once
#include <SFML/Graphics.hpp>
#include "vector2.h"

class Entity {
public:
    //FUNCTIONS
    virtual void Update(float deltaTime);
    void Draw(sf::RenderWindow& window) {window.draw(body);}
    void AddForce(Vector2 direction, float amount, float deltaTime, bool stayInBounds);
    void SetPosition(float newX, float newY) {body.setPosition(newX, newY);}
    Vector2 GetPosition() { return Vector2(body.getPosition());}
    sf::RectangleShape* GetRect() {return &body;}

    //VARIABLES
    Vector2 movement;
    Vector2 bounds;
    sf::RectangleShape body;
    float moveForce;
    float maxSpeed;
    float mass = 1;
    float drag;
private:
    //FUNCTIONS
    Vector2 ApplyDrag(float amount, Vector2 vector);
};
