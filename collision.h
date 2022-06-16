#pragma once
#include "SFML/Graphics.hpp"
#include "vector2.h"

class Collision {

};

bool CircleCol(sf::CircleShape* shapeA, sf::CircleShape* shapeB);
bool RectCol(sf::RectangleShape* shapeA, sf::RectangleShape* shapeB);
bool IsInBounds(Vector2 bounds, sf::RectangleShape* shape);
