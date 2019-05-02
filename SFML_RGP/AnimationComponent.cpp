#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
    : mSprite(sprite)
    , mTextureSheet(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::addAnimation(std::string key)
{
}

void AnimationComponent::startAnimation(std::string animation)
{
}

void AnimationComponent::pauseAnimation(std::string animation)
{
}

void AnimationComponent::resetAnimation(std::string animation)
{
}

void AnimationComponent::update(const float& deltaTime)
{
}

AnimationComponent::Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
    float animationTimer, int startX, int startY, int endX, int endY,
    int width, int height)
    : mSprite(sprite)
    , mTextureSheet(textureSheet)
    , mAnimationTimer(animationTimer)
    , mWidth(width)
    , mHeight(height)
{
    mStartRect = sf::IntRect(startX, startY, width, height);
    mCurrentRect = mStartRect;
    mEndRect = sf::IntRect(endX, endY, width, height);

    mSprite.setTexture(textureSheet, true);
    mSprite.setTextureRect(mStartRect);
}

void AnimationComponent::Animation::update(const float& deltatime)
{
    mTimer = 10.0f * deltatime;
    if (mTimer >= mAnimationTimer) {
        mTimer = 0.0f;

        if (mCurrentRect != mEndRect) {
            mCurrentRect.left += mWidth;
        } else {
            mCurrentRect.left = mStartRect.left;
        }
    }
}

void AnimationComponent::Animation::pause()
{
}

void AnimationComponent::Animation::reset()
{
}
