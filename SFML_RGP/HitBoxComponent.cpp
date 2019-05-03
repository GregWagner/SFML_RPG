#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height)
    : mSprite(sprite)
    , mOffsetX(offsetX)
    , mOffsetY(offsetY)
{
    mHitBox.setPosition(mSprite.getPosition().x + offsetX, mSprite.getPosition().y + offsetY);
    mHitBox.setSize(sf::Vector2f(width, height));
    mHitBox.setFillColor(sf::Color::Transparent);
    mHitBox.setOutlineThickness(1.0f);
    mHitBox.setOutlineColor(sf::Color::Green);
}

HitBoxComponent::~HitBoxComponent()
{
}

bool HitBoxComponent::checkIntersect(const sf::FloatRect& rect)
{
    return mHitBox.getGlobalBounds().intersects(rect);
}

void HitBoxComponent::update()
{
    mHitBox.setPosition(mSprite.getPosition().x + mOffsetX, mSprite.getPosition().y + mOffsetY);
}

void HitBoxComponent::render(sf::RenderTarget& target)
{
    target.draw(mHitBox);
}
