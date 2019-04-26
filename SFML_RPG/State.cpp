#include "State.h"

State::State(std::shared_ptr<sf::RenderWindow> window)
    : mWindow(window)
{
}

bool State::getQuit() const
{
    return mQuit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mQuit = true;
    }
}
