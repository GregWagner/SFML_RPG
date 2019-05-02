// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"
Entity::~Entity()
{
    delete mMovementComponet;
    mMovementComponet = nullptr;
}

void Entity::setTexture(sf::Texture& texture)
{
    mSprite.setTexture(texture);
    mSprite.scale(0.25f, 0.25f); // TODO: Remote this - temporary
}

void Entity::createMovementComponent(const float maxVelocity,
    float acceleration, float deceleration)
{
    mMovementComponet = new MovementComponent(mSprite, maxVelocity,
        acceleration, deceleration);
}

void Entity::move(const float dirX, const float dirY, const float& deltaTime)
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
    if (mMovementComponet) {
        mMovementComponet->update(deltaTime);
    }
}

void Entity::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(mSprite);
}
