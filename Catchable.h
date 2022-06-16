#include <SFML/Graphics.hpp>
#include <list>
#include "Range.h"
#include "entity.h"

class Catchable : public Entity {
public:
    Catchable(sf::Texture* texture, Vector2 size, float maxSpeed, float acceleration, int worthPoints, Vector2 bounds);
    void Update(float deltaTime) override;

    //variables
    float worthPoints;

private:
    void RandomSideMovement(float deltaTime);
    Range timebetweenMovements = Range(0.1f, 0.8f);

    int direction = 1;
    float timeToMove = timebetweenMovements.Random();
    float timer;

    sf::Texture texture;
};



