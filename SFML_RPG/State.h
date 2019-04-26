#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class State {
public:
    explicit State(std::shared_ptr<sf::RenderWindow> window);

    bool getQuit() const;

    virtual void checkForQuit();
    virtual void endState() = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
    virtual void updateKeyBinds(const float& deltaTime) = 0;

private:
    std::vector<sf::Texture> mTextures {};
    std::shared_ptr<sf::RenderWindow> mWindow;

    bool mQuit {};
};
