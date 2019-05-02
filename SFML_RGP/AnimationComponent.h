#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AnimationComponent {
public:
    AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~AnimationComponent();

    void addAnimation(std::string key);

    void startAnimation(std::string animation);
    void pauseAnimation(std::string animation);
    void resetAnimation(std::string animation);

    void update(const float& deltaTime);

private:
    class Animation {
    public:
        Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int startX, int startY, int endX, int endY, int width, int height);

        void update(const float& deltatime);
        void pause();
        void reset();

        sf::Sprite& mSprite;
        sf::Texture& mTextureSheet;
        float mAnimationTimer {};
        float mTimer {};
        int mWidth;
        int mHeight;

        sf::IntRect mStartRect {};
        sf::IntRect mCurrentRect {};
        sf::IntRect mEndRect {};
    };

    sf::Sprite& mSprite;
    sf::Texture& mTextureSheet;

    std::map<std::string, Animation> animations;
};
