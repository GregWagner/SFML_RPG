#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AnimationComponent {
public:
    AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~AnimationComponent();

    void addAnimation(const std::string key,
        float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY,
        int width, int height);

    void play(const std::string key, const float& deltaTime);

private:
    class Animation {
    public:
        Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer,
            int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);

        void play(const float& deltatime);
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

    std::map<std::string, Animation*> mAnimations {};
    Animation* mLastAnimation { nullptr };
};
