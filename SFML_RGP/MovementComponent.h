#pragma once

#include <SFML/Graphics.hpp>

class MovementComponent {

public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity,
        float acceleration, float deceleration);
    virtual ~MovementComponent();

    void update(const float& deltaTime);
    void move(const float dirX, const float dirY, const float deltaTime);

    sf::Vector2f getVelocity() const;

    bool isIdle() const;

private:
    sf::Sprite& mSprite;

    float mMaxVelocity {};
    float mAcceleration {};
    float mDeceleration {};

    sf::Vector2f mVelocity {};
};
