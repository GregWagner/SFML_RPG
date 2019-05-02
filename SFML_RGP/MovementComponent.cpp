#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
    float acceleration, float deceleration)
    : mSprite(sprite)
    , mMaxVelocity(maxVelocity)
    , mDeceleration(deceleration)
    , mAcceleration(acceleration)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(const float& deltaTime)
{
    // deceleration
    if (mVelocity.x > 0.0f) {
        // going to the right
        mVelocity.x -= mDeceleration;
        if (mVelocity.x < 0.0f) {
            mVelocity.x = 0.0f;
        }
    } else {
        // going to the left
        mVelocity.x += mDeceleration;
        if (mVelocity.x > 0.0f) {
            mVelocity.x = 0;
        }
    }

    // final move
    mSprite.move(mVelocity * deltaTime);
}

void MovementComponent::move(const float dirX, const float dirY, const float deltaTime)
{
    // accelerating the sprite until it reaches max velocity
    mVelocity.x += mAcceleration * dirX;
    if (mVelocity.x > 0.0f) {
        // going to the right
        if (mVelocity.x > mMaxVelocity) {
            mVelocity.x = mMaxVelocity;
        }
    } else {
        // going to the left
        if (mVelocity.x < -mMaxVelocity) {
            mVelocity.x = -mMaxVelocity;
        }
    }

    mVelocity.y += mAcceleration * dirY;
    if (mVelocity.y > mMaxVelocity) {
        mVelocity.y = mMaxVelocity;
    }
}

sf::Vector2f MovementComponent::getVelocity() const
{
    return mVelocity;
}
