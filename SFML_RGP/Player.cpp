#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
    setPosition(x, y);

    createMovementComponent(300.0f, 15.0f, 5.0f);
    createAnimationComponent(textureSheet);
    createHitBoxComponent(mSprite, 0.0f, 0.0f, 192.0f, 192.0f);

    mAnimationComponent->addAnimation("IDLE_LEFT", 10.0f, 0, 0, 13, 0, 192, 192);
    mAnimationComponent->addAnimation("WALK_LEFT", 10.0f, 0, 1, 11, 1, 192, 192);
}

Player::~Player()
{
}

void Player::update(const float& deltaTime)
{
    mMovementComponet->update(deltaTime);
    if (mMovementComponet->getState(MovementStates::IDLE)) {
        mAnimationComponent->play("IDLE_LEFT", deltaTime);
    } else if (mMovementComponet->getState(MovementStates::MOVING_LEFT)) {
        mAnimationComponent->play("WALK_LEFT", deltaTime);
    }
    mHixBoxComponent->update();
}
