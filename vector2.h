#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector2 {
    private:
        float x_;
        float y_;
    public:
        Vector2();
        Vector2(float x, float y);
        Vector2(const sf::Vector2<float> sfmlVector);

        float getX() const;
        float getY() const;

        void setX(const float x);
        void setY(const float y);
        void set(const float x, const float y);
        float magnitude() const;
        float sqrMagnitude() const;
        Vector2 normalize();
        Vector2 reverse();
        bool equals(const Vector2 vectorB);

        Vector2 operator+(const Vector2 vectorB) const;
        Vector2 operator-(const Vector2 vectorB) const;
        Vector2 operator*(const float factor) const;
        Vector2 operator/(const float factor) const;

        Vector2& operator+=(const Vector2 vectorB);
        Vector2& operator-=(const Vector2 vectorB);
        Vector2& operator*=(const float factor);
        Vector2& operator/=(const float factor);
        bool operator==(const Vector2 vectorB);

        friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);
};

float Dot(const Vector2 vectorA, const Vector2 vectorB);
float Angle(const Vector2 from, const Vector2 to);
float Distance(const Vector2 point1, const Vector2 point2);

Vector2 VectorLeft();

Vector2 VectorRight();

Vector2 VectorUp();

Vector2 VectorDown();

