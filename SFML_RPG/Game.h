#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Game {
public:
    Game();
    virtual ~Game() = default;

    void run();

private:
    // functions
    void updateSFMLEvents();
    void updateDeltaTime();
    void update();
    void render();

    // variables
    std::unique_ptr<sf::RenderWindow> mWindow { nullptr };

    sf::Clock mClock;
    float mDeltaTime {};
};
