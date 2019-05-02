#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
    setTexture(texture);
    setPosition(x, y);
    createMovementComponent(300.0f, 15.0f, 5.0f);
}

Player::~Player()
{
}
