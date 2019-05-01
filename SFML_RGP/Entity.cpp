// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"

void Entity::setTexture(sf::Texture& texture)
{
    mSprite.setTexture(texture);
    mSprite.scale(0.25f, 0.25f); // TODO: Remote this - temporary
}

void Entity::createMovementComponent(const float maxVelocity)
{
    mMovementComponet = new MovementComponent(mSprite, maxVelocity);
}

void Entity::move(const float& deltaTime, const float dirX, const float dirY)
{
    if (mMovementComponet) {
        mMovementComponet->move(dirX, dirY, deltaTime);
    }
}

void Entity::setPosition(float x, float y)
{
    mSprite.setPosition(x, y);
}

void Entity::update(const float& deltaTime)
{
}

void Entity::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(mSprite);
}
