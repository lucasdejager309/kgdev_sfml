#include "Range.h"

Range::Range(float min, float max) {
    v.setX(min);
    v.setY(max);
}

float RandomRange(float min, float max) {
    return (min + (float) (rand()) / ((float) (RAND_MAX / (max) - min)));
}

int RandomRange(int min, int max) {
    return (rand()&max)+min;
}

float Range::Random() {
    return RandomRange(Min(), Max());
}


