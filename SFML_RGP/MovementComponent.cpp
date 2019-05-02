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
    if (mVelocity.x > 0.0f) { // player is moving to the right
        if (mVelocity.x > mMaxVelocity) {
            mVelocity.x = mMaxVelocity;
        }
        // deceleration
        mVelocity.x -= mDeceleration;
        if (mVelocity.x < 0.0f) {
            mVelocity.x = 0.0f;
        }
    } else if (mVelocity.x < 0.0f) { // player is moving to the left
        if (mVelocity.x < -mMaxVelocity) {
            mVelocity.x = -mMaxVelocity;
        }
        // deceleration
        mVelocity.x += mDeceleration;
        if (mVelocity.x > 0.0f) {
            mVelocity.x = 0.0f;
        }
    }

    if (mVelocity.y > 0.0f) { // player is moving up
        if (mVelocity.y > mMaxVelocity) {
            mVelocity.y = mMaxVelocity;
        }
        // deceleration
        mVelocity.y -= mDeceleration;
        if (mVelocity.y < 0.0f) {
            mVelocity.y = 0.0f;
        }
    } else if (mVelocity.y < 0.0f) { // player is moving up
        if (mVelocity.y < -mMaxVelocity) {
            mVelocity.y = -mMaxVelocity;
        }
        // deceleration
        mVelocity.y += mDeceleration;
        if (mVelocity.y > 0.0f) {
            mVelocity.y = 0.0f;
        }
    }

    // final move
    mSprite.move(mVelocity * deltaTime);
}

void MovementComponent::move(const float dirX, const float dirY, const float deltaTime)
{
    // acceleration
    mVelocity.x += mAcceleration * dirX;
    mVelocity.y += mAcceleration * dirY;
}

sf::Vector2f MovementComponent::getVelocity() const
{
    return mVelocity;
}

bool MovementComponent::isIdle() const
{
    return mVelocity.x == 0.0f && mVelocity.y == 0.0f;
}
