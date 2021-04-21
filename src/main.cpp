#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong clone");
    const sf::Color MY_GREEN{0,128,0};
    sf::RectangleShape teren(sf::Vector2f(800.f, 600.f));
    sf::RectangleShape paleta1(sf::Vector2f(20.f, 100.f));
    sf::RectangleShape paleta2(sf::Vector2f(20.f, 100.f));
    sf::RectangleShape minge(sf::Vector2f(30.f, 30.f));
    sf::Vertex fileu[] = 
    {
        sf::Vertex(sf::Vector2f(400.f, 0.f)),
        sf::Vertex(sf::Vector2f(400.f, 600.f)),
    };
    sf::CircleShape cerc_mijloc(100.f);
    sf::Font font;
    if (!font.loadFromFile("/es/ARCADE.TTF"))
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
    scor_dreapta.setString("2");
    scor_dreapta.setCharacterSize(48);
    scor_dreapta.setPosition(600.f, 0.f);
    scor_dreapta.setStyle(sf::Text::Bold);
    paleta1.setPosition(0,250);
    paleta2.setPosition(780,250);
    minge.setPosition(200,200);
    cerc_mijloc.setOrigin(-300,-200);
    teren.setFillColor(MY_GREEN);
    paleta1.setFillColor(sf::Color::White);
    paleta2.setFillColor(sf::Color::White);
    minge.setFillColor(sf::Color::White);
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
     
        window.clear();
        window.draw(teren);
        window.draw(paleta1);
        window.draw(paleta2);
        window.draw(minge);
        window.draw(cerc_mijloc);
        window.draw(fileu, 2, sf::Lines);
        window.draw(scor_stanga);
        window.draw(scor_dreapta);
        
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
