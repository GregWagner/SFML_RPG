#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
    : mSprite(sprite)
    , mTextureSheet(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{
    for (auto& animation : mAnimations) {
        delete animation.second;
    }
}

void AnimationComponent::addAnimation(const std::string key, float animationTimer,
    int startFrameX, int startFrameY, int framesX, int framesY,
    int width, int height)
{
    mAnimations[key] = new Animation(mSprite, mTextureSheet, animationTimer,
        startFrameX, startFrameY, framesX, framesY, width, height);
}

void AnimationComponent::play(const std::string key, const float& deltaTime)
{
    mAnimations[key]->play(deltaTime);
}

AnimationComponent::Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
    float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY,
    int width, int height)
    : mSprite(sprite)
    , mTextureSheet(textureSheet)
    , mAnimationTimer(animationTimer)
    , mWidth(width)
    , mHeight(height)
{
    mStartRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
    mCurrentRect = mStartRect;
    mEndRect = sf::IntRect(framesX * width, framesY * height, width, height);

    mSprite.setTexture(textureSheet, true);
    mSprite.setTextureRect(mStartRect);
}

void AnimationComponent::Animation::play(const float& deltatime)
{
    mTimer += 100.0f * deltatime;
    if (mTimer >= mAnimationTimer) {
        mTimer = 0.0f;

        if (mCurrentRect != mEndRect) {
            mCurrentRect.left += mWidth;
        } else {
            mCurrentRect.left = mStartRect.left;
        }
        mSprite.setTextureRect(mCurrentRect);
    }
}

void AnimationComponent::Animation::reset()
{
    mTimer = 0.0f;
    mCurrentRect = mStartRect;
}
