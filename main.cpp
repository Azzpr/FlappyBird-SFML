#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Other important things
    sf::RenderWindow window(sf::VideoMode(1280, 720), "FlappyBird!");
    int groundHeight = 710;
    //Setting the player
    sf::RectangleShape player(sf::Vector2f(120, 50));
    player.setFillColor(sf::Color::Green);
    player.setSize(sf::Vector2f(20, 20));
    player.setPosition(sf::Vector2f(640, 360));
    float moveSpeed = 0.5f;
    float jumpSpeed = 0.2f;

    //Setting the font and text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        ;
    {
        std::cout << "error";
    }
    //Creating the text
    sf::Text welcomeMsg;
    welcomeMsg.setFont(font);
    welcomeMsg.setCharacterSize(20);
    welcomeMsg.setString("Bootleg Flappy Bird!");
    welcomeMsg.setFillColor(sf::Color::White);
    welcomeMsg.setPosition(540, 0);
    //Setting the gravity and velocity
    const float gravity = 0.0001f;
    sf::Vector2f velocity(sf::Vector2f(0, 0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Making the movement Up and down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            velocity.y = -jumpSpeed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            velocity.y = jumpSpeed;
        }

        if (player.getPosition().y + player.getSize().y < groundHeight || velocity.y < 0)
        {
            velocity.y += gravity;
        }
        else
        {
            player.setPosition(player.getPosition().x, groundHeight - player.getSize().y);
            velocity.y = 0;
        }
        player.move(velocity.x, velocity.y);
        window.clear();
        window.draw(player);

        window.draw(welcomeMsg);
        window.display();
    }

    return 0;
}