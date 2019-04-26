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
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height >> framerateLimit >> verticalSyncEnabled;
    } else {
        std::cerr << "Unable to read config file - using defaults\n";
    }
    ifs.close();

    mWindow = std::make_shared<sf::RenderWindow>(windowBounds, title, sf::Style::Default);
    mWindow->setFramerateLimit(framerateLimit);
    mWindow->setVerticalSyncEnabled(verticalSyncEnabled);

    initStates();
}

Game::~Game()
{
    while (!mStates.empty()) {
        mStates.pop();
    }
}

void Game::run()
{
    while (mWindow->isOpen()) {
        updateDeltaTime();
        update();
        render();
    }
}

void Game::initStates()
{
    mStates.push(std::make_shared<GameState>(mWindow));
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

    if (!mStates.empty()) {
        mStates.top()->update(mDeltaTime);
        if (mStates.top()->getQuit()) {
            mStates.top()->endState();
            mStates.pop();
        }
    } else {
        // if there are no more states, end the application
        mWindow->close();
    }
}

void Game::render()
{
    mWindow->clear();

    if (!mStates.empty()) {
        mStates.top()->render();
    }
    mWindow->display();
}
