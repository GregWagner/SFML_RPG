// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Entity.h"

Entity::Entity()
{
    mShape.setSize(sf::Vector2f(50.0f, 50.0f));
    mShape.setFillColor(sf::Color::White);
}

Entity::~Entity()
{
}

void Entity::move(const float& deltaTime, const float dirX, const float dirY)
{
    mShape.move(dirX * mMovementSpeed * deltaTime, dirY * mMovementSpeed * deltaTime);
}

void Entity::update(const float& deltaTime)
{
}

void Entity::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(mShape);
}
