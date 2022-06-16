#pragma once
#include <SFML/Graphics.hpp>
#include "vector2.h"
#include "entity.h"

class Player : public Entity {
public:
    //FUNCTIONS
    Player(sf::Texture* texture, float moveForce, float drag, float maxSpeed, Vector2 bounds);
    void Update(float deltaTime) override;

    void AddPoints(int amountToAdd) {currentPoints += amountToAdd;}
    void SetPoints(int amount) {currentPoints = amount;}
    int GetPoints() {return currentPoints;}

private:
    int currentPoints;
};
