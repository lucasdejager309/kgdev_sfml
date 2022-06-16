#include <SFML/Graphics.hpp>
#include "Player.h"
#include "CatchableSpawner.h"
#include "ScoreKeeper.h"
#include <list>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include<iostream>

static const sf::Vector2f VIEW_SIZE = sf::Vector2f(1280, 720);

static const float SPAWN_RATE = 0.75f;
static const float MAX_PLAYER_SPEED = 6.f;
static const float PLAYER_MOVE_FORCE = 40.f;
static const float PLAYER_DRAG = 0.03f;
static const int MISSABLE = 10;

bool alive = true;

void ResizeView(sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_SIZE.y * aspectRatio, VIEW_SIZE.y);
    view.setCenter(VIEW_SIZE.x/2, VIEW_SIZE.y/2);
}

//used to get textures/font with relative path https://www.tutorialspoint.com/find-out-the-current-working-directory-in-c-cplusplus
std::string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}

int main() {

    std::cout << get_current_dir() << std::endl;

    //SETUP WINDOW
    sf::RenderWindow window(sf::VideoMode(VIEW_SIZE.x, VIEW_SIZE.y), "SFML works!");
    sf::View view(sf::Vector2f(0,0), sf::Vector2f(VIEW_SIZE.x, VIEW_SIZE.y));
    view.setCenter(VIEW_SIZE.x/2, VIEW_SIZE.y/2);

    //SETUP TEXT
    sf::Font font;
    font.loadFromFile(get_current_dir() + "\\data\\arialbd.ttf");
    ScoreKeeper scoreKeeper = ScoreKeeper(Vector2(20,10), MISSABLE, font);

    //SETUP PLAYER
    sf::Texture playerTexture;
    playerTexture.loadFromFile(get_current_dir() + "\\data\\basket.png");
    Player player(&playerTexture, PLAYER_MOVE_FORCE, PLAYER_DRAG, MAX_PLAYER_SPEED, Vector2(static_cast<sf::Vector2f>(window.getSize())));
    player.SetPosition(VIEW_SIZE.x/2, VIEW_SIZE.y*0.85);

    //SETUP SPAWNER
    sf::Texture cTexture0;
    cTexture0.loadFromFile(get_current_dir() + "\\data\\grapes.png");
    sf::Texture cTexture1;
    cTexture1.loadFromFile(get_current_dir() + "\\data\\orange.png");
    sf::Texture cTexture2;
    cTexture2.loadFromFile(get_current_dir() + "\\data\\banana.png");
    sf::Texture cTexture3;
    cTexture3.loadFromFile(get_current_dir() + "\\data\\tomato.png");
    std::list<sf::Texture*> cTextures = {&cTexture0, &cTexture1, &cTexture2, &cTexture3};

    CatchableSpawner cSpawner = CatchableSpawner(&cTextures, SPAWN_RATE, &player, Vector2(static_cast<sf::Vector2f>(window.getSize())));

    //SETUP CLOCK
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("\nwidth: %i height: %i\n", event.size.width, event.size.height);
                    ResizeView(window, view);
                    break;
            }
        }

        if (cSpawner.missed >= scoreKeeper.missedToLose) {
            alive = false;
        }

        if (!alive && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            alive = true;
            player.SetPoints(0);
            cSpawner.missed = 0;
        }

        //UPDATE OBJECTS
        if (alive) {
            player.Update(deltaTime);
            cSpawner.Update(deltaTime);
            scoreKeeper.UpdateScore(player.GetPoints(), cSpawner.missed);
        }

        //CLEAR SCREEN
        window.clear(sf::Color::Blue);
        window.setView(view);

        //DRAW OBJECTS
        if (alive) {
            cSpawner.Draw(window);
            player.Draw(window);
            scoreKeeper.Draw(window);
        } else {
            scoreKeeper.DrawFinalScore(window);
        }

        //DISPLAY WINDOW
        window.display();

    }


    return 0;
}
