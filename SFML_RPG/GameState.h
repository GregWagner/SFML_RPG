#pragma once

#include "Entity.h"
#include "State.h"
#include <map>

class GameState : public State {
public:
    GameState(std::shared_ptr<sf::RenderWindow> window,
        std::map<std::string, int>* supportedKeys);

    void endState() override;
    void update(const float& deltaTime) override;
    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
    void updateInput(const float& deltaTime) override;

private:
    Entity mPlayer;

    void initKeybinds() override;
};
