#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();

    void createSprite(sf::Texture* texture);
    virtual void move(const float& deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime);
    virtual void render(std::shared_ptr<sf::RenderTarget> target);

protected:
    sf::Texture* mTexture { nullptr };
    sf::Sprite* mSprite { nullptr };

    float mMovementSpeed { 100.0f };

private:
};
