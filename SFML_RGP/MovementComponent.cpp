#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity)
    : mMaxVelocity(maxVelocity)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(const float& dt)
{
}

void MovementComponent::move(const float dirX, const float dirY)
{
    mVelocity.x = mMaxVelocity * dirX;
    mVelocity.y = mMaxVelocity * dirY;
}

sf::Vector2f MovementComponent::getVelocity() const
{
    return mVelocity;
}
