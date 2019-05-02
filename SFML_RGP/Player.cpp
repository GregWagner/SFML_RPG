#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
    setPosition(x, y);

    createMovementComponent(300.0f, 15.0f, 5.0f);
    createAnimationComponent(textureSheet);

    mAnimationComponent->addAnimation("IDLE_LEFT", 10.0f, 0, 0, 13, 0,
        192, 192);
}

Player::~Player()
{
}

void Player::update(const float& deltaTime)
{
    mMovementComponet->update(deltaTime);

    mAnimationComponent->play("IDLE_LEFT", deltaTime);
}
