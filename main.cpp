#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "FlappyBird!");
    sf::RectangleShape player(sf::Vector2f(120, 50));
    player.setFillColor(sf::Color::Green);
    player.setSize(sf::Vector2f(100, 100));

    while (window.isOpen())
    {
        sf::Event event;    
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}