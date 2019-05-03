#pragma once

#include "AnimationComponent.h"
#include "HitBoxComponent.h"
#include "MovementComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
public:
    Entity() = default;
    virtual ~Entity();

    void setTexture(sf::Texture& texture);

    void createMovementComponent(const float maxVelocity, float acceleration, float deceleration);
    void createAnimationComponent(sf::Texture& textureSheet);
    void createHitBoxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height);

    virtual void move(const float x, const float y, const float& deltaTime);
    virtual void setPosition(float x, float y);

    virtual void update(const float& deltaTime);
    virtual void render(std::shared_ptr<sf::RenderTarget> target);

protected:
    sf::Sprite mSprite {};

    HitBoxComponent* mHixBoxComponent { nullptr };
    MovementComponent* mMovementComponet { nullptr };
    AnimationComponent* mAnimationComponent { nullptr };

private:
};
