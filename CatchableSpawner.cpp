#include "CatchableSpawner.h"
#include "collision.h"
#include <list>
#include <iostream>

static const float CATCHABLE_SIZE = 80;
static const float MAX_SPEED = 4;
static const float MOVE_FORCE = 2;
static const int WORTH_POINTS = 10;

CatchableSpawner::CatchableSpawner(std::list<sf::Texture*>* textures, float spawnRate, Player* player, Vector2 bounds) {
    this->player = player;
    this->bounds = bounds;
    this->spawnRate = spawnRate;
    this->textures = textures;
}

CatchableSpawner::~CatchableSpawner() {
    delete player;
}

void CatchableSpawner::Update(float deltaTime) {
    //spawn new catchables
    if (timer < spawnRate) {
        timer += deltaTime;
    } else {
        timer = 0;
        SpawnCatchable(CATCHABLE_SIZE, MAX_SPEED, MOVE_FORCE, WORTH_POINTS);
    }

    std::list<Catchable>::iterator it;
    for (it = currentCatchables.begin(); it != currentCatchables.end(); it++) {
        bool deleteCatchable = false;

        it->Update(deltaTime);

        //the player catches it
        if (RectCol(it->GetRect(), player->GetRect())) {
            player->AddPoints(it->worthPoints);
            deleteCatchable = true;
        }

        //it goes out of bounds
        if (it->GetPosition().getY() > bounds.getY()) {
            missed++;
            deleteCatchable = true;
        }

        if (deleteCatchable) {
            currentCatchables.erase(it--);
        }
    }
}

void CatchableSpawner::SpawnCatchable(float size, float maxSpeed, float moveForce, float worthPoints) {

    //get random texture from list
    int random = rand()%textures->size();
    std::list<sf::Texture*>::iterator it = textures->begin();
    std::advance(it, random);

    Catchable catchable = Catchable(*it, sf::Vector2f(size, size), maxSpeed, moveForce, worthPoints, bounds);
    catchable.SetPosition(rand() % static_cast<int>(bounds.getX()), 80);
    currentCatchables.push_back(catchable);
}

void CatchableSpawner::Draw(sf::RenderWindow &window) {
    std::list<Catchable>::iterator it = currentCatchables.begin();
    for (int i=0; i < currentCatchables.size(); i++) {
        it->Draw(window);

        ++it;
    }
}
