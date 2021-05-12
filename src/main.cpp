#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

    sf::RectangleShape line(sf::Vector2f(3.f, 600.f));
    sf::CircleShape circle(60.f);
    circle.setFillColor(sf::Color(46, 184, 46));
    circle.setOutlineThickness(3.f);
    circle.setOrigin(60, 60);
    circle.setPosition(400, 300);

    line.setPosition(399, 0);

    sf::RectangleShape leftPaddle(sf::Vector2f(25.f, 100.f));
    sf::RectangleShape rightPaddle(sf::Vector2f(25.f, 100.f));
    leftPaddle.setPosition(0, 250);
    rightPaddle.setPosition(775, 250);

    float x = rand() % 400 + 200;
    float y = rand() % 400 + 100;
    float dx = 0.1, dy = 0.1;

    sf::RectangleShape ball(sf::Vector2f(25.f, 25.f));
    ball.setPosition(x, y);

    sf::Font font;
    if (!font.loadFromFile("fonts/Minecraft.ttf"))
    {
        if (!font.loadFromFile("output/fonts/Minecraft.ttf"))
        {
            std::cout << "Cannot load ARCADE.TTF font file" << std::endl;
        }
    }

    sf::Text scoreLeft;
    sf::Text scoreRight;
    scoreLeft.setFont(font);
    scoreLeft.setCharacterSize(34);
    scoreLeft.setPosition(350, 25);
    scoreRight.setFont(font);
    scoreRight.setCharacterSize(34);
    scoreRight.setPosition(425, 25);

    int counter1 = 0, counter2 = 0;

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        if (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            /*
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                leftPaddle.move(0.f, -3.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                leftPaddle.move(0.f, 3.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
            {
                rightPaddle.move(0.f, -3.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            {
                rightPaddle.move(0.f, 3.f);
            }
*/
        }

        window.clear(sf::Color(46, 184, 46));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            if (leftPaddle.getPosition().y > 0)

                leftPaddle.move(0.f, -0.1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (leftPaddle.getPosition().y < 600 - leftPaddle.getSize().y)
                leftPaddle.move(0.f, 0.1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (rightPaddle.getPosition().y > 0)
                rightPaddle.move(0.f, -0.1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (rightPaddle.getPosition().y < 600 - rightPaddle.getSize().y)
                rightPaddle.move(0.f, 0.1);
        }

        if (x <= 0)
        {
            sf::sleep(sf::seconds(0.3f));
            dx = -dx;
            x = 0;
            counter1++;
            std::stringstream ss;
            ss << counter1;

            scoreRight.setString(ss.str());
        }

        if (x >= 800 - 25)
        {
            sf::sleep(sf::seconds(0.3f));
            dx = -dx;
            x = 800 - 25;
            counter2++;
            std::stringstream ss;
            ss << counter2;

            scoreLeft.setString(ss.str());
        }

        if (y >= 600 || y <= 0)
            dy = -dy;

        if (ball.getPosition().x <= 25)
        {
            if (ball.getPosition().y > leftPaddle.getPosition().y && ball.getPosition().y < leftPaddle.getPosition().y + 99)
            {
                dx = -dx;
                x = 25;
            }
        }

        if (ball.getPosition().x >= 800 - 50)
        {
            if (ball.getPosition().y > rightPaddle.getPosition().y && ball.getPosition().y < rightPaddle.getPosition().y + 99)
            {
                dx = -dx;
                x = 800 - 50;
            }
        }

        y = y + dy;
        x = x + dx;
        ball.setPosition(x, y);

        window.clear(sf::Color(46, 184, 46));
        window.draw(circle);
        window.draw(line);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.draw(scoreLeft);
        window.draw(scoreRight);

        window.display();
    }

    return 0;
}