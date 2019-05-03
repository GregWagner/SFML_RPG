// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"

Entity::~Entity()
{
    delete mMovementComponet;
    mMovementComponet = nullptr;
    delete mAnimationComponent;
    mAnimationComponent = nullptr;
    delete mHixBoxComponent;
    mHixBoxComponent = nullptr;
}

void Entity::setTexture(sf::Texture& texture)
{
    mSprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity,
    float acceleration, float deceleration)
{
    mMovementComponet = new MovementComponent(mSprite, maxVelocity,
        acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
    mAnimationComponent = new AnimationComponent(mSprite, textureSheet);
}

void Entity::createHitBoxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height)
{
    mHixBoxComponent = new HitBoxComponent(sprite, offsetX, offsetY, width, height);
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
}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(mSprite);

    if (mHixBoxComponent) {
        mHixBoxComponent->render(target);
    }
}
