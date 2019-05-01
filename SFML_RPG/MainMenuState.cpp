// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "MainMenuState.h"
#include "GameState.h"
#include <fstream>
#include <iostream>

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    initKeybinds();
    initFonts();
    initButtons();

    mBackground.setSize(sf::Vector2f(static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));
    mBackground.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    for (auto& button : mButtons) {
        delete button.second;
    }
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState\n";
}

void MainMenuState::update(const float& deltaTime)
{
    updateMousePosition();
    updateInput(deltaTime);
    updateButtons();
}

void MainMenuState::updateInput(const float& deltaTime)
{
    checkForQuit();
}

void MainMenuState::updateButtons()
{
    for (auto button : mButtons) {
        button.second->update(mMousePosView);
    }
    if (mButtons["GAME_STATE"]->isPressed()) {
        mStates->push(new GameState(mWindow, mSupportedKeys, mStates));
    }
    if (mButtons["EXIT_STATE"]->isPressed()) {
        endState();
        mQuit = true;
    }
}

void MainMenuState::render(std::shared_ptr<sf::RenderTarget> target)
{
    if (!target) {
        target = mWindow;
    }
    target->draw(mBackground);

    renderButtons(target);
}

void MainMenuState::renderButtons(std::shared_ptr<sf::RenderTarget> target)
{
    for (auto button : mButtons) {
        button.second->render(target);
    }
}

void MainMenuState::initFonts()
{
    if (!mFont.loadFromFile("Resources/Fonts/Dosis-Light.ttf")) {
        throw("ERROR - MainMenuState Could not load font");
    }
}

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("Configs/mainmenustate_keybinds.ini");
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

void MainMenuState::initButtons()
{
    mButtons["GAME_STATE"] = new Button(100, 100, 150, 50, &mFont,
        "New Game", sf::Color(70, 70, 70, 200),
        sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    mButtons["EXIT_STATE"] = new Button(100, 300, 150, 50, &mFont,
        "Quit", sf::Color(100, 100, 100, 200),
        sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}
