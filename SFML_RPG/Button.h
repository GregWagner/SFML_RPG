#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class ButtonState {
    IDLE,
    HOVER,
    ACTIVE,
};

class Button {
public:
    Button(float x, float y, float width, float height,
        sf::Font* font, const std::string& text, sf::Color idleColor,
        sf::Color hoverColer, sf::Color activeColor);

    void render(std::shared_ptr<sf::RenderTarget> target);
    void update(sf::Vector2f mousePosition);

    bool isPressed() const;

private:
    ButtonState mButtonState { ButtonState::IDLE };

    sf::RectangleShape mShape;
    sf::Font* mFont;
    sf::Text mText;

    sf::Color mIdleColor;
    sf::Color mHoverColor;
    sf::Color mActiveColor;
};
