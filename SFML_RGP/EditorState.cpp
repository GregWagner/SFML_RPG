// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "EditorState.h"
#include "GameState.h"
#include <fstream>
#include <iostream>
#include <sstream>

EditorState::EditorState(std::shared_ptr<sf::RenderWindow> window,
    std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    initKeybinds();
    initFonts();
    initButtons();
}

EditorState::~EditorState()
{
    for (auto& button : mButtons) {
        delete button.second;
    }
}

void EditorState::update(const float& deltaTime)
{
    updateMousePosition();
    updateInput(deltaTime);
    updateButtons();
}

void EditorState::updateInput(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(mKeyBinds.at("CLOSE")))) {
        endState();
    }
}

void EditorState::updateButtons()
{
    for (auto button : mButtons) {
        button.second->update(mMousePosView);
    }
}

void EditorState::render(std::shared_ptr<sf::RenderTarget> target)
{
    if (!target) {
        target = mWindow;
    }

    renderButtons(*target);

    /*
    sf::Text mousePos;
    mousePos.setPosition(mMousePosView.x, mMousePosView.y - 50);
    mousePos.setFont(mFont);
    mousePos.setCharacterSize(14);
    std::stringstream ss;
    ss << mMousePosView.x << ", " << mMousePosView.y;
    mousePos.setString(ss.str());

    target->draw(mousePos);
    */
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
    for (auto button : mButtons) {
        button.second->render(target);
    }
}

void EditorState::initFonts()
{
    if (!mFont.loadFromFile("Resources/Fonts/Dosis-Light.ttf")) {
        throw("ERROR - EditorState Could not load font");
    }
}

void EditorState::initKeybinds()
{
    std::ifstream ifs("Configs/editstate_keybinds.ini");
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

void EditorState::initButtons()
{
}
