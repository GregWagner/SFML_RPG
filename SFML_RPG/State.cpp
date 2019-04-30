// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "State.h"

State::State(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys)
    : mWindow(window)
    , mSupportedKeys(supportedKeys)
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
