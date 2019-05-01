#pragma once

#include "Entity.h"
#include "Player.h"
#include "State.h"
#include <map>
#include <stack>

class GameState : public State {
public:
    GameState(std::shared_ptr<sf::RenderWindow> window,
        std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states);
    ~GameState();

    void update(const float& deltaTime) override;
    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
    void updateInput(const float& deltaTime) override;

private:
    Player* mPlayer;

    void initKeybinds() override;
    void initTextures();
    void initPlayers();
};
