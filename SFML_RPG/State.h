#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class State {
public:
    State();
    ~State();

    virtual void update() = 0;
    virtual void render() = 0;

private:
    std::vector<sf::Texture> mTextures {};
};
