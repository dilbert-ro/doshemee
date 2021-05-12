#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "pong");
    sf::CircleShape cerc(60.f);
    cerc.setFillColor(sf::Color::Black);
    cerc.setOutlineColor(sf::Color::White);
    cerc.setOutlineThickness(2.f);
    cerc.setOrigin(60, 60);
    cerc.setPosition(400, 300);

    sf::CircleShape minge(20.f);
    minge.setFillColor(sf::Color::White);
    minge.setOrigin(60, 60);
    minge.setPosition(250, 250);

    sf::RectangleShape patrat(sf::Vector2f(25.f, 25.f));
    float x = rand() % 201 + 300;
    float y = rand() % 201 + 200;
    patrat.setPosition(x, y);
    float dx = 0.08;
    float dy = 0.08;

    sf::RectangleShape drtunghi1(sf::Vector2f(25.f, 100.f));
    drtunghi1.setFillColor(sf::Color::White);
    drtunghi1.setOutlineColor(sf::Color::White);
    drtunghi1.setOutlineThickness(2.f);
    drtunghi1.setPosition(0, 175);

    sf::RectangleShape drtunghi2(sf::Vector2f(25.f, 100.f));
    drtunghi2.setFillColor(sf::Color::White);
    drtunghi2.setOutlineColor(sf::Color::White);
    drtunghi2.setOutlineThickness(2.f);
    drtunghi2.setPosition(775, 175);

    sf::RectangleShape linie(sf::Vector2f(1.f, 600.f));
    linie.setFillColor(sf::Color::White);
    linie.setOutlineColor(sf::Color::White);
    linie.setOutlineThickness(1.f);
    linie.setPosition(400, 0);

    /* sf::ConvexShape minge;                                        
        minge.setPointCount(12);
        minge.setPoint(0, sf::Vector2f(0.f, 0.f));
        minge.setPoint(1, sf::Vector2f(10.f, 0.f));
        minge.setPoint(2, sf::Vector2f(10.f, 10.f));
        minge.setPoint(3, sf::Vector2f(20.f, 10.f));
        minge.setPoint(4, sf::Vector2f(20.f, 20.f));
        minge.setPoint(5, sf::Vector2f(10.f, 20.f));
        minge.setPoint(6, sf::Vector2f(10.f, 30.f));
        minge.setPoint(7, sf::Vector2f(0.f, 30.f));
        minge.setPoint(8, sf::Vector2f(0.f, 20.f));
        minge.setPoint(9, sf::Vector2f(-10.f, 20.f));
        minge.setPoint(10, sf::Vector2f(-10.f, 10.f));
        minge.setPoint(11, sf::Vector2f(0.f, 10.f) );
        
        minge.setPosition(250,100);
        minge.setFillColor(sf::Color::White);   */

    sf::Font font;
    font.loadFromFile("output/resources/fonts/Minecraft.ttf");

    sf::Text scors;
    scors.setFont(font);
    scors.setCharacterSize(24);
    scors.setPosition(350, 25);
    int scorstanga = 0;
    scors.setString("0");
    ;

    sf::Text scord;
    scord.setFont(font);
    scord.setCharacterSize(24);
    scord.setPosition(432, 25);
    int scordreapta = 0;
    scord.setString("0");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // paddle movement
        {
            if (drtunghi1.getPosition().y > 0)
                drtunghi1.move(0.f, -0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (drtunghi1.getPosition().y < 500)
                drtunghi1.move(0.f, 0.1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (drtunghi2.getPosition().y > 0)
                drtunghi2.move(0.f, -0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (drtunghi2.getPosition().y < 500)
                drtunghi2.move(0.f, 0.1);
        }

        if (patrat.getPosition().x >= 800 - 20) // ball hit dedection
        {
            dx = -dx;
            x = 800 - 20;
            sf::sleep(sf::seconds(0.3f));
            scorstanga = scorstanga + 1;
            std::stringstream ss;
            ss << scorstanga;
            scors.setString(ss.str());
        }

        if (patrat.getPosition().x <= 0)
        {
            dx = -dx;
            x = 0;
            sf::sleep(sf::seconds(0.3f));
            scordreapta = scordreapta + 1;
            std::stringstream ss;
            ss << scordreapta;
            scord.setString(ss.str());
        }

        if (patrat.getPosition().y >= 600 - 20)
            dy = -dy;

        if (patrat.getPosition().y <= 0)
            dy = -dy;

        if (patrat.getPosition().x <= 20)
        {
            if (patrat.getPosition().y >= drtunghi1.getPosition().y - 20 && patrat.getPosition().y <= drtunghi1.getPosition().y + 100)
            {
                dx = -dx;
                x = 20;
            }
        }

        if (patrat.getPosition().x >= 760)
        {
            if (patrat.getPosition().y >= drtunghi2.getPosition().y - 20 && patrat.getPosition().y <= drtunghi2.getPosition().y + 100)
            {
                dx = -dx;
                x = 760;
            }
        }

        x = x + dx;
        y = y + dy;
        patrat.setPosition(x, y);

        window.clear(sf::Color::Black);

        window.draw(scors);
        window.draw(cerc);
        window.draw(drtunghi1);
        window.draw(drtunghi2);
        window.draw(linie);
        window.draw(patrat);
        //window.draw(minge);
        window.draw(scord);

        window.display();
    }

    return 0;
}
