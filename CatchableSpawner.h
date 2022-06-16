#pragma once
#include <list>
#include "Catchable.h"
#include "Player.h"

class CatchableSpawner {
public:
    CatchableSpawner(std::list<sf::Texture*>* textures, float spawnRate, Player* player, Vector2 bounds);
    ~CatchableSpawner();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    void SpawnCatchable(float size, float maxSpeed, float acceleration, float worthPoints);

    int missed = 0;
private:
    std::list<sf::Texture*>* textures;
    float spawnRate;
    std::list<Catchable> currentCatchables;

    Player* player;
    Vector2 bounds;
    float timer;
};

//Catchable* GetCatchableFromList(std::list<Catchable*> list, int index);
