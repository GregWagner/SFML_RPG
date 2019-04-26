#pragma once

#include "GameState.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

class Game {
public:
    Game();
    virtual ~Game();

    void run();

private:
    // functions
    void initStates();
    void updateSFMLEvents();
    void updateDeltaTime();
    void update();
    void render();

    // variables
    std::shared_ptr<sf::RenderWindow> mWindow { nullptr };

    sf::Clock mClock;
    float mDeltaTime {};

    std::stack<std::shared_ptr<State>> mStates;
};
