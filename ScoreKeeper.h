#include "SFML/Graphics.hpp"
#include "vector2.h"

class ScoreKeeper {
public:
    ScoreKeeper(Vector2 position, int missedToLose, sf::Font font);
    void UpdateScore(int points, int missed);
    void Draw(sf::RenderWindow& window);
    void DrawFinalScore(sf::RenderWindow& window);

    int missedToLose;
private:
    int currentPoints;
    int currentMissed;

    Vector2 pos;

    sf::Font font;
};

