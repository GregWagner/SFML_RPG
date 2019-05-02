#pragma once

#include "Button.h"
#include "State.h"

class EditorState : public State {
public:
    EditorState(std::shared_ptr<sf::RenderWindow> window,
        std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states);
    virtual ~EditorState();

    void update(const float& deltaTime) override;
    void updateInput(const float& deltaTime) override;
    void updateButtons();

    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
    void renderButtons(std::shared_ptr<sf::RenderTarget> target = nullptr);

private:
    sf::Font mFont;

    std::map<std::string, Button*> mButtons;

    void initFonts();
    void initKeybinds() override;
    void initButtons();
};
