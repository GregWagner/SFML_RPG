#pragma once

#include <SFML/Graphics.hpp>

class MovementComponent {

public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity);
    virtual ~MovementComponent();

    void update(const float& dt);
    void move(const float dirX, const float dirY, const float deltaTime);

    sf::Vector2f getVelocity() const;

private:
    sf::Sprite& mSprite;

    float mMaxVelocity {};

    sf::Vector2f mVelocity {};
    sf::Vector2f mAcceleration {};
    sf::Vector2f mDeceleration {};
};
