#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void move(const float& deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime);
    virtual void render(std::shared_ptr<sf::RenderTarget> target);

protected:
    sf::RectangleShape mShape;
    float mMovementSpeed { 100.0f };

private:
};
