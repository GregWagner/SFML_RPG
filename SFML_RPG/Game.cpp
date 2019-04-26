#include "Game.h"

Game::Game()
{
    mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "C++ SFML RPG", sf::Style::Default);
    mWindow->setFramerateLimit(60);
}

void Game::run()
{
    while (mWindow->isOpen()) {
        update();
        render();
    }
}

void Game::updateSFMLEvents()
{
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow->close();
        }
    }
}

void Game::update()
{
    updateSFMLEvents();
}

void Game::render()
{
    mWindow->clear();

    mWindow->display();
}

// Functions
