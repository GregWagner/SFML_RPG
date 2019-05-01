#include "Player.h"

Player::Player(float x, float y, sf::Texture* texture)
{
    createSprite(texture);
    setPosition(x, y);
    createMovementComponent(100.0f);
}

Player::~Player()
{
}
