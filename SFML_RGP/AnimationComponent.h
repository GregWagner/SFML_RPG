#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AnimationComponent {
public:
    AnimationComponent();
    virtual ~AnimationComponent();

private:
    class Animation {
    public:
        Animation(sf::Texture& textureSheet, float speed, int startX, int startY, int endX, int endY, int width, int height);

        void update(const float& deltatime);
        void pause();
        void reset();

        sf::Texture& mTextureSheet;
        float mSpeed {};
        int mWidth;
        int mHeight;
        sf::IntRect mStartRect {};
        sf::IntRect mEndRect {};
    };

    std::map<std::string, Animation> animations;
};
