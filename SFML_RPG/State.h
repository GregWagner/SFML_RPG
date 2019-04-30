#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class State {
public:
    State(std::shared_ptr<sf::RenderWindow> window,
        std::map<std::string, int>* supportedKeys);
    bool getQuit() const;

    virtual void checkForQuit();
    virtual void endState() = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
    virtual void updateInput(const float& deltaTime) = 0;

protected:
    std::shared_ptr<sf::RenderWindow> mWindow;
    std::map<std::string, int>* mSupportedKeys;
    std::map<std::string, int> mKeyBinds;

    bool mQuit {};

    std::vector<sf::Texture> mTextures {};

    virtual void initKeybinds() = 0;
};
