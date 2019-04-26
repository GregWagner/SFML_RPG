#include "Game.h"
#include <fstream>
#include <iostream>
#include <sstream>

Game::Game()
{
    std::string title { "None" };
    sf::VideoMode windowBounds(800, 600);
    unsigned framerateLimit { 120 };
    bool verticalSyncEnabled {};

    std::ifstream ifs("Configs/window.ini");
    if (ifs.is_open()) {
        std::cout << "Config file opened\n";
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height >> framerateLimit >> verticalSyncEnabled;
    }
    mWindow = std::make_unique<sf::RenderWindow>(windowBounds, title, sf::Style::Default);
    mWindow->setFramerateLimit(framerateLimit);
    mWindow->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::run()
{
    while (mWindow->isOpen()) {
        updateDeltaTime();
        update();
        render();
    }
}

void Game::updateSFMLEvents()
{
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow->close();
        }
    }
}

void Game::updateDeltaTime()
{
    mDeltaTime = mClock.restart().asSeconds();
}

void Game::update()
{
    updateSFMLEvents();
}

void Game::render()
{
    mWindow->clear();

    mWindow->display();
}
