// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"

void Entity::createSprite(sf::Texture* texture)
{
    mTexture = texture;
    mSprite = std::make_unique<sf::Sprite>(*mTexture);
    mSprite->scale(0.25f, 0.25f); // TODO: Remote this - temporary
}

void Entity::createMovementComponent(const float maxVelocity)
{
    mMovementComponet = new MovementComponent(maxVelocity);
}

void Entity::move(const float& deltaTime, const float dirX, const float dirY)
{
    if (mSprite && mMovementComponet) {
        mMovementComponet->move(dirX, dirY);
        mSprite->move(mMovementComponet->getVelocity() * deltaTime);
    }
}

void Entity::setPosition(float x, float y)
{
    if (mSprite) {
        mSprite->setPosition(x, y);
    }
}

void Entity::update(const float& deltaTime)
{
}

void Entity::render(std::shared_ptr<sf::RenderTarget> target)
{
    if (mSprite) {
        target->draw(*mSprite);
    }
}
