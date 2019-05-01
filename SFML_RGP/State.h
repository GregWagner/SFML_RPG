#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <stack>

class State {
public:
    State(std::shared_ptr<sf::RenderWindow> window,
        std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states);
    bool getQuit() const;

    void endState();
    virtual void update(const float& deltaTime) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
    virtual void updateInput(const float& deltaTime) = 0;
    virtual void updateMousePosition();

protected:
    std::shared_ptr<sf::RenderWindow> mWindow;
    std::map<std::string, int>* mSupportedKeys;
    std::stack<State*>* mStates;
    std::map<std::string, int> mKeyBinds;
    std::map<std::string, sf::Texture> mTextures {};

    bool mQuit {};

    virtual void initKeybinds() = 0;

    sf::Vector2i mMousePosScreen;
    sf::Vector2i mMousePosWindow;
    sf::Vector2f mMousePosView;
};
