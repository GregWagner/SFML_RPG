#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML RPG", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(50.0f);
    circle.setPosition(sf::Vector2f(0.0f, 0.0f));
    circle.setFillColor(sf::Color(255, 100, 200, 200));

    sf::RectangleShape rect(sf::Vector2f(50.0f, 100.0f));
    rect.setPosition(sf::Vector2f(400.0f, 200.0f));
    rect.setFillColor(sf::Color(255, 255, 200, 100));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // update
        circle.move(0.5f, 0.1f);
        circle.rotate(2.0f);
        rect.move(-0.5f, -0.1f);
        rect.rotate(25.0f);
        window.clear();

        window.draw(circle);
        window.draw(rect);

        window.display();
    }
}
