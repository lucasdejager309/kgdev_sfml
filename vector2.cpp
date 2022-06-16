#include "vector2.h"
#include <iostream>
#include <math.h>

Vector2::Vector2() {
    x_ = 0;
    y_ = 0;
}

Vector2::Vector2(float x, float y) {
    x_ = x;
    y_ = y;
}

Vector2::Vector2(const sf::Vector2<float> sfmlVector) {
    x_ = sfmlVector.x;
    y_ = sfmlVector.y;
}

float Vector2::getX() const {
    return x_;
}

float Vector2::getY() const {
    return y_;
}

void Vector2::setX(const float x) {
    x_ = x;
}

void Vector2::setY(const float y) {
    y_ = y;
}

void Vector2::set(const float x, const float y) {
    x_ = x;
    y_ = y;
}

float Vector2::magnitude() const{    
    return sqrt((pow(x_, 2) + pow(y_, 2)));
}

float Vector2::sqrMagnitude() const{
    return (pow(x_, 2) + pow(y_, 2));
}

Vector2 Vector2::normalize() {
    Vector2 vector = *this;
    return vector/(vector.magnitude());
}

Vector2 Vector2::reverse() {
    return Vector2(-x_, -y_);
}

bool Vector2::equals(const Vector2 vectorB) {
    if (Vector2(x_, y_) == vectorB) {
        return true;
    } else {
        return false;
    }
}

Vector2 Vector2::operator+(const Vector2 vectorB) const {
    return Vector2(x_ + vectorB.getX(), y_ + vectorB.getY());
}

Vector2 Vector2::operator-(const Vector2 vectorB) const {
    return Vector2(x_ - vectorB.getX(), y_ - vectorB.getY());
}

Vector2 Vector2::operator*(const float factor) const {
    return Vector2(x_ * factor, y_ * factor);
}

Vector2 Vector2::operator/(const float factor) const {
    return Vector2(x_ / factor, y_ / factor);
}

Vector2& Vector2::operator+=(const Vector2 vectorB) {
    x_ += vectorB.getX();
    y_ += vectorB.getY();

    return *this;
}

Vector2& Vector2::operator-=(const Vector2 vectorB) {
    x_ -= vectorB.getX();
    y_ -= vectorB.getY();

    return *this;
}

Vector2& Vector2::operator*=(const float factor) {
    x_ *= factor;
    y_ *= factor;

    return *this;
}

Vector2& Vector2::operator/=(const float factor) {
    x_ /= factor;
    y_ /= factor;

    return *this;
}

bool Vector2::operator==(const Vector2 vectorB) {
    if (x_ == vectorB.getX() && y_ == vectorB.getY()) {
        return true;
    } else return false;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
    os << "(" << vector.getX() << ", " << vector.getY() << ")";
    return os;
}

float Dot(const Vector2 vectorA, const Vector2 vectorB) {
    return vectorA.getX() * vectorB.getX() + vectorA.getY() * vectorB.getY();
}

float Distance(const Vector2 vectorA, const Vector2 vectorB) {
    Vector2 vectorC = vectorA - vectorB;
    return sqrt(pow(vectorC.getX(), 2) + pow(vectorC.getY(), 2));
}

//returns angle in degrees
float Angle(const Vector2 from, const Vector2 to) {
    return acos(Dot(from, to) / (from.magnitude() * to.magnitude())) * (180/3.141); //replace 3.141 with actual pi constant
}

Vector2 VectorLeft() {
    return Vector2(-1, 0);
}

Vector2 VectorRight() {
    return Vector2(1, 0);
}

Vector2 VectorUp() {
    return Vector2(0, -1);
}

Vector2 VectorDown() {
    return Vector2(0, 1);
}