#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
}

AnimationComponent::~AnimationComponent()
{
}

AnimationComponent::Animation::Animation(sf::Texture& textureSheet, float speed, int startX, int startY, int endX, int endY,
    int width, int height)
    : mTextureSheet(textureSheet)
    , mSpeed(speed)
    , mWidth(width)
    , mHeight(height)
{
    mStartRect = sf::IntRect(startX, startY, width, height);
    mEndRect = sf::IntRect(endX, endY, width, height);
}

void AnimationComponent::Animation::update(const float& deltatime)
{
}

void AnimationComponent::Animation::pause()
{
}

void AnimationComponent::Animation::reset()
{
}
