// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "GameState.h"
#include <fstream>
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys,
    std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    initKeybinds();
}

void GameState::update(const float& deltaTime)
{
    updateMousePosition();
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
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("CLOSE")))) {
        endState();
    }
}

void GameState::initKeybinds()
{
    std::ifstream ifs("Configs/gamestate_keybinds.ini");
    if (ifs.is_open()) {
        std::string key {};
        std::string keyValue {};
        while (ifs >> key >> keyValue) {
            mKeyBinds[key] = mSupportedKeys->at(keyValue);
        }

    } else {
        std::cerr << "Unable to open support keys configuration file\n";
    }
    ifs.close();
}
