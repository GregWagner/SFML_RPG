#include "GameState.h"
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window)
    : State(window)
{
}

void GameState::endState()
{
}

void GameState::update(const float& deltaTime)
{
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{
}
