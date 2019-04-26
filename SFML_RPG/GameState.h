#pragma once

#include "State.h"

class GameState : public State {
public:
    explicit GameState(std::shared_ptr<sf::RenderWindow> window);
    virtual ~GameState() = default;

    void endState() override;
    void update(const float& deltaTime) override;
    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
};
