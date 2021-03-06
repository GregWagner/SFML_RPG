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
    mVideoModes = sf::VideoMode::getFullscreenModes();

    std::string title { "None" };
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    bool fullScreen {};
    unsigned framerateLimit { 120 };
    bool verticalSyncEnabled {};
    unsigned antialiasingLevel {};

    std::ifstream ifs("Configs/window.ini");
    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height >> fullScreen
            >> verticalSyncEnabled >> antialiasingLevel;
    } else {
        std::cerr << "Unable to read config file - using defaults\n";
    }
    ifs.close();

    sf::ContextSettings windowSettings;
    windowSettings.antialiasingLevel = antialiasingLevel;
    if (fullScreen) {
        mWindow = std::make_shared<sf::RenderWindow>(windowBounds, title,
            sf::Style::Fullscreen, windowSettings);
    } else {
        mWindow = std::make_shared<sf::RenderWindow>(windowBounds, title,
            sf::Style::Titlebar | sf::Style::Close, windowSettings);
    }
    mWindow->setFramerateLimit(framerateLimit);
    mWindow->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initKeys()
{
    std::ifstream ifs("Configs/supported_keys.ini");
    if (ifs.is_open()) {
        std::string key {};
        int keyValue {};
        while (ifs >> key >> keyValue) {
            mSupportedKeys[key] = keyValue;
        }
    } else {
        std::cerr << "Unable to open support keys configuration file\n";
    }
    ifs.close();
}

void Game::initStates()
{
    mStates.push(new MainMenuState(mWindow, &mSupportedKeys, &mStates));
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
