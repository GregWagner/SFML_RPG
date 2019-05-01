#pragma once

#include "MovementComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity);
    virtual void move(const float& deltaTime, const float x, const float y);
    virtual void setPosition(float x, float y);

    virtual void update(const float& deltaTime);
    virtual void render(std::shared_ptr<sf::RenderTarget> target);

protected:
    sf::Sprite mSprite {};

    MovementComponent* mMovementComponet { nullptr };

private:
};
