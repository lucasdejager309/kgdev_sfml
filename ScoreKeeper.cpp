#include "ScoreKeeper.h"

ScoreKeeper::ScoreKeeper(Vector2 position, int missedToLose, sf::Font font) {
    this->pos = position;
    this->missedToLose = missedToLose;
    this->font = font;
}

void ScoreKeeper::UpdateScore(int points, int missed) {
    currentPoints = points;
    currentMissed = missed;
}

void ScoreKeeper::Draw(sf::RenderWindow &window) {
    sf::Text scoreText;
    sf::Text missedText;

    scoreText.setFont(font);
    missedText.setFont(font);
    scoreText.setCharacterSize(50);
    missedText.setCharacterSize(50);
    scoreText.setString("points: " + std::to_string(currentPoints));
    missedText.setString("failed: " + std::to_string(currentMissed) + "/" + std::to_string(missedToLose));

    scoreText.setPosition(pos.getX(), pos.getY());
    missedText.setPosition(pos.getX(), pos.getY()+70);

    window.draw(scoreText);
    window.draw(missedText);
}

void ScoreKeeper::DrawFinalScore(sf::RenderWindow &window) {
    sf::Text message;
    message.setFont(font);
    message.setCharacterSize(75);
    message.setString("You Died!\nYour score: " + std::to_string(currentPoints));

    sf::FloatRect textRect = message.getLocalBounds();
    message.setOrigin(textRect.left + textRect.width/2.f, textRect.top + textRect.height/2.f);
    message.setPosition(window.getSize().x/2, window.getSize().y/2);

    window.draw(message);
}