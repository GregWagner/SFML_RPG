#include "GameState.h"
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
    : State(window)
{
}

void GameState::endState()
{
    std::cout << "Ending GameState\n";
}

void GameState::update(const float& deltaTime)
{
    updateKeyBinds(deltaTime);
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{
}

void GameState::updateKeyBinds(const float& deltaTime)
{
    checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "A\n";
    }
}
