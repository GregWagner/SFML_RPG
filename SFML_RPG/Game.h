#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    virtual ~Game();

    void run();

private:
    // functions
    void updateSFMLEvents();
    void update();
    void render();

    // variables
    sf::RenderWindow* mWindow { nullptr };
};
