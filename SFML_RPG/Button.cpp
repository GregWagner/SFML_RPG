#include "Button.h"

Button::Button(float x, float y, float width, float height,
    sf::Font* font, const std::string& text, sf::Color idleColor,
    sf::Color hoverColer, sf::Color activeColor)
    : mFont(font)
    , mIdleColor(idleColor)
    , mHoverColor(hoverColer)
    , mActiveColor(activeColor)
{
    mShape.setPosition(sf::Vector2f(x, y));
    mShape.setSize(sf::Vector2f(width, height));
    mShape.setFillColor(mIdleColor);

    mText.setFont(*mFont);
    mText.setString(text);
    mText.setFillColor(sf::Color::White);
    //mText.setColor(sf::Color::White);
    mText.setCharacterSize(12);
    mText.setPosition(
        mShape.getPosition().x + (mShape.getGlobalBounds().width / 2.0f) - (mText.getGlobalBounds().width / 2.0f),
        mShape.getPosition().y + (mShape.getGlobalBounds().height / 2.0f) - (mText.getGlobalBounds().height / 2.0f));
}

void Button::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(mShape);
    target->draw(mText);
}

void Button::update(const sf::Vector2f mousePosition)
{
    mButtonState = ButtonState::IDLE;
    mShape.setFillColor(mIdleColor);
    // update the booleans for hover and pressed
    if (mShape.getGlobalBounds().contains(mousePosition)) {
        mButtonState = ButtonState::HOVER;
        mShape.setFillColor(mHoverColor);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mButtonState = ButtonState::ACTIVE;
            mShape.setFillColor(mActiveColor);
        }
    }
}

bool Button::isPressed() const
{
    return mButtonState == ButtonState::ACTIVE;
}
