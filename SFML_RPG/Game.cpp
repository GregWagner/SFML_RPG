// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Game.h"
#include <fstream>
#include <iostream>
#include <sstream>

Game::Game()
{
    initWindow();
    initKeys();
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

void ::Game::initWindow()
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
}

void Game::initKeys()
{
    mSupportedKeys["Escape"] = sf::Keyboard::Escape;
    mSupportedKeys["A"] = sf::Keyboard::A;
    mSupportedKeys["D"] = sf::Keyboard::D;
    mSupportedKeys["W"] = sf::Keyboard::W;
    mSupportedKeys["S"] = sf::Keyboard::S;
}

void Game::initStates()
{
    mStates.push(std::make_shared<GameState>(mWindow, &mSupportedKeys));
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
