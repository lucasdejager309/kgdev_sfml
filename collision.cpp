#include "collision.h"
#include "vector2.h"
#include <iostream>

bool CircleCol(sf::CircleShape* shapeA, sf::CircleShape* shapeB) {
      float distanceBetweenCircles = Distance(Vector2(shapeA->getPosition()), Vector2(shapeB->getPosition()));

      std::cout << "col: " << distanceBetweenCircles << " > " << shapeA->getRadius() << " + " << shapeB->getRadius() << std::endl;

      if (distanceBetweenCircles > shapeA->getRadius() + shapeB->getRadius()) {
          return false;
      } else {
          return true;
      }
}

bool RectCol(sf::RectangleShape* shapeA, sf::RectangleShape* shapeB) {
    Vector2 originA = Vector2(shapeA->getOrigin());
    Vector2 sizeA = Vector2(shapeA->getSize());
    Vector2 posA = Vector2(shapeA->getPosition());

    float aLeft = posA.getX()-originA.getX();
    float aRight = posA.getX()+(sizeA.getX()-originA.getX());
    float aTop = posA.getY()-originA.getY();
    float aBottom = posA.getY()+(sizeA.getY()-originA.getY());

    Vector2 originB = Vector2(shapeB->getOrigin());
    Vector2 sizeB = Vector2(shapeB->getSize());
    Vector2 posB = Vector2(shapeB->getPosition());

    float bLeft = posB.getX()-originB.getX();
    float bRight = posB.getX()+(sizeB.getX()-originB.getX());
    float bTop = posB.getY()-originB.getY();
    float bBottom = posB.getY()+(sizeB.getY()-originB.getY());

    if (((aLeft < bRight && aRight > bLeft) || (bLeft < aRight && bRight > aLeft)) && ((aBottom > bTop && aTop < bBottom) || (bBottom > aTop && bTop < aBottom))) {
        return true;
    }

    return false;
}


bool IsInBounds(Vector2 bounds, sf::RectangleShape* shape) {
    Vector2 origin = Vector2(shape->getOrigin());
    Vector2 size = Vector2(shape->getSize());
    Vector2 pos = Vector2(shape->getPosition());

    float left = pos.getX()-origin.getX();
    float right = pos.getX()+(size.getX()-origin.getX());
    float top = pos.getY()-origin.getY();
    float bottom = pos.getY()+(size.getY()-origin.getY());

    if (left < 0 || right > bounds.getX() || top < 0 || bottom > bounds.getY()) {
        return false;
    } else return true;
}