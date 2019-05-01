#pragma once

#include <SFML/Graphics.hpp>

class MovementComponent {

public:
    MovementComponent(float maxVelocity);
    virtual ~MovementComponent();

    void update(const float& dt);
    void move(const float dirX, const float dirY);

    sf::Vector2f getVelocity() const;

private:
    float mMaxVelocity {};
    sf::Vector2f mVelocity {};
    sf::Vector2f mAcceleration {};
    sf::Vector2f mDeceleration {};
};
