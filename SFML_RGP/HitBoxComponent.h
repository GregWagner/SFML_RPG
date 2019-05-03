#pragma once

#include <SFML/Graphics.hpp>

class HitBoxComponent {
public:
    HitBoxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height);
    virtual ~HitBoxComponent();

    bool checkIntersect(const sf::FloatRect& rect);

    void update();
    void render(sf::RenderTarget& target);

private:
    sf::Sprite& mSprite;
    sf::RectangleShape mHitBox {};

    float mOffsetX {};
    float mOffsetY {};
};
