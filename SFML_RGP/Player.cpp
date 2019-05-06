#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
    setPosition(x, y);

    createMovementComponent(300.0f, 15.0f, 5.0f);
    createAnimationComponent(textureSheet);
    createHitBoxComponent(mSprite, 86.0f, 70.0f, 86.0f, 111.0f);

    mAnimationComponent->addAnimation("IDLE", 10.0f, 0, 0, 13, 0, 192, 192);
    mAnimationComponent->addAnimation("WALK", 10.0f, 0, 1, 11, 1, 192, 192);
}

Player::~Player()
{
}

void Player::update(const float& deltaTime)
{
    mMovementComponet->update(deltaTime);
    if (mMovementComponet->getState(MovementStates::IDLE)) {
        mAnimationComponent->play("IDLE", deltaTime);
    } else if (mMovementComponet->getState(MovementStates::MOVING_LEFT)) {
        mSprite.setOrigin(0.0f, 0.0f);
        mSprite.setScale(1.0f, 1.0f);
        mAnimationComponent->play("WALK", deltaTime);
    } else if (mMovementComponet->getState(MovementStates::MOVING_RIGHT)) {
        mSprite.setOrigin(258.0f, 0.0f);
        mSprite.setScale(-1.0f, 1.0f);
        mAnimationComponent->play("WALK", deltaTime);
    } else if (mMovementComponet->getState(MovementStates::MOVING_UP)) {
        mAnimationComponent->play("WALK", deltaTime);
    } else if (mMovementComponet->getState(MovementStates::MOVING_DOWN)) {
        mAnimationComponent->play("WALK", deltaTime);
    }
    mHixBoxComponent->update();
}
