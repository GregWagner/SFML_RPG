#pragma once

#include <SFML/Graphics.hpp>

enum class MovementStates {
    IDLE,
    MOVING,
    MOVING_UP,
    MOVING_DOWN,
    MOVING_LEFT,
    MOVING_RIGHT
};

class MovementComponent {

public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity,
        float acceleration, float deceleration);
    virtual ~MovementComponent();

    void update(const float& deltaTime);
    void move(const float dirX, const float dirY, const float deltaTime);

    sf::Vector2f getVelocity() const;

    bool getState(MovementStates state) const;

private:
    sf::Sprite& mSprite;

    float mMaxVelocity {};
    float mAcceleration {};
    float mDeceleration {};

    sf::Vector2f mVelocity {};
};
