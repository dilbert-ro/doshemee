#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong clone");
    sf::RectangleShape leftPaddleen(sf::Vector2f(20.f, 100.f));
    sf::RectangleShape rightPaddleen(sf::Vector2f(20.f, 100.f));
    sf::RectangleShape ball(sf::Vector2f(30.f, 30.f));
    sf::Vertex fileu[] =
        {
            sf::Vertex(sf::Vector2f(400.f, 0.f)),
            sf::Vertex(sf::Vector2f(400.f, 600.f)),
        };
    sf::CircleShape cerc_mijloc(100.f);
    const sf::Color MY_GREEN{0, 128, 0};
    sf::Font font;
    if (!font.loadFromFile("/res/ARCADE.TTF"))
    {
        if (!font.loadFromFile("output/res/ARCADE.TTF"))
        {
            std::cout << "Cannot load ARCADE.TTF from file" << std::endl;
        }
    };
    sf::Text scor_stanga;
    sf::Text scor_dreapta;
    scor_stanga.setFont(font);
    scor_dreapta.setFont(font);
    scor_stanga.setString("0");
    scor_stanga.setCharacterSize(48);
    scor_stanga.setPosition(200.f, 0.f);
    scor_stanga.setStyle(sf::Text::Bold);
    scor_dreapta.setString("0");
    scor_dreapta.setCharacterSize(48);
    scor_dreapta.setPosition(600.f, 0.f);
    scor_dreapta.setStyle(sf::Text::Bold);
    leftPaddleen.setPosition(0.f, 250.f);
    rightPaddleen.setPosition(780.f, 250.f);
    ball.setPosition(200.f, 150.f);
    cerc_mijloc.setPosition(300, 200);
    cerc_mijloc.setFillColor(MY_GREEN);
    cerc_mijloc.setOutlineThickness(1);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //miscarea paleta stanga cu tastele A si Q

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (leftPaddleen.getPosition().y < 600 - leftPaddleen.getSize().y)
                leftPaddleen.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            if (leftPaddleen.getPosition().y > 0)
                leftPaddleen.move(0.f, -0.1f);
        }
        //miscarea paleta dreapta cu tastele P si L

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (rightPaddleen.getPosition().y < 600 - rightPaddleen.getSize().y)
                rightPaddleen.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (rightPaddleen.getPosition().y > 0)
                rightPaddleen.move(0.f, -0.1f);
        }
        window.clear(MY_GREEN);
        window.draw(leftPaddleen);
        window.draw(rightPaddleen);
        window.draw(ball);
        window.draw(cerc_mijloc);
        window.draw(fileu, 2, sf::Lines);
        window.draw(scor_dreapta);
        window.draw(scor_stanga);
        window.display();
    }

    return 0;
}
