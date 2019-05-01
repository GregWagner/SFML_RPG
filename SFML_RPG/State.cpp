// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "State.h"

State::State(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys,
    std::stack<State*>* states)
    : mWindow(window)
    , mSupportedKeys(supportedKeys)
    , mStates(states)
{
}

bool State::getQuit() const
{
    return mQuit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds["CLOSE"]))) {
        mQuit = true;
    }
}

void State::updateMousePosition()
{
    mMousePosScreen = sf::Mouse::getPosition();
    mMousePosWindow = sf::Mouse::getPosition(*mWindow);
    mMousePosView = mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow));
}
