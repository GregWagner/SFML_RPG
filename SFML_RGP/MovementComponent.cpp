#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity)
    : mSprite(sprite)
    , mMaxVelocity(maxVelocity)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(const float& dt)
{
}

void MovementComponent::move(const float dirX, const float dirY, const float deltaTime)
{
    mVelocity.x = mMaxVelocity * dirX;
    mVelocity.y = mMaxVelocity * dirY;

     mSprite.move(mVelocity * deltaTime);
}

sf::Vector2f MovementComponent::getVelocity() const
{
    return mVelocity;
}
