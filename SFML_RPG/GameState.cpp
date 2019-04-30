// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "GameState.h"
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    initKeybinds();
}

void GameState::endState()
{
    std::cout << "Ending GameState\n";
}

void GameState::update(const float& deltaTime)
{
    updateInput(deltaTime);
    mPlayer.update(deltaTime);
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{
    if (!target) {
        target = mWindow;
    }
    mPlayer.render(target);
}

void GameState::updateInput(const float& deltaTime)
{
    checkForQuit();

    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("MOVE_LEFT")))) {
        mPlayer.move(deltaTime, -1.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("MOVE_RIGHT")))) {
        mPlayer.move(deltaTime, 1.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("MOVE_UP")))) {
        mPlayer.move(deltaTime, 0.0f, -1.0f);
    }
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("MOVE_DOWN")))) {
        mPlayer.move(deltaTime, 0.0f, 1.0f);
    }
}

void GameState::initKeybinds()
{
    mKeyBinds.emplace("MOVE_LEFT", mSupportedKeys->at("A"));
    mKeyBinds.emplace("MOVE_RIGHT", mSupportedKeys->at("D"));
    mKeyBinds.emplace("MOVE_UP", mSupportedKeys->at("W"));
    mKeyBinds.emplace("MOVE_DOWN", mSupportedKeys->at("S"));
}
