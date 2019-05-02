#pragma once

#include "MovementComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
public:
    Entity() = default;
    virtual ~Entity();

    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity, float acceleration, float deceleration);
    virtual void move(const float x, const float y, const float& deltaTime);
    virtual void setPosition(float x, float y);

    virtual void update(const float& deltaTime);
    virtual void render(std::shared_ptr<sf::RenderTarget> target);

protected:
    sf::Sprite mSprite {};

    MovementComponent* mMovementComponet { nullptr };

private:
};
