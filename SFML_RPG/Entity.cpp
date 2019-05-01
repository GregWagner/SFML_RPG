// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
    delete mSprite;
    mSprite = nullptr;
}

void Entity::createSprite(sf::Texture* texture)
{
    mTexture = texture;
    mSprite->setTexture(*mTexture);
}

void Entity::move(const float& deltaTime, const float dirX, const float dirY)
{
    if (mSprite) {
        mSprite->move(dirX * mMovementSpeed * deltaTime, dirY * mMovementSpeed * deltaTime);
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
