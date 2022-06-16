#include "vector2.h"
#include <random>

class Range {
public:
    Range(float min, float max);
    float Min() {v.getX();}
    float Max() {v.getY();}
    float Random();
private:
    Vector2 v;
};

float RandomRange(float min, float max);
int RandomRange(int min, int max);
