#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window{sf::VideoMode{800, 600}, "Pong"};
    const sf::Color MY_GREEN{0, 128, 0};
    sf::Vertex centerLine[] = {sf::Vertex{sf::Vector2f{400.f, 0.f}},
                               sf::Vertex{sf::Vector2f{400.f, 600.f}}};

    sf::CircleShape centerCircle{60.f};
    centerCircle.setPosition(400.f, 300.f);
    centerCircle.setOrigin(60.f, 60.f);
    centerCircle.setOutlineColor(sf::Color::White);
    centerCircle.setFillColor(MY_GREEN);
    centerCircle.setOutlineThickness(1.f);

    sf::RectangleShape leftPaddle{sf::Vector2f{25.f, 100.f}};
    leftPaddle.setPosition(0.f, 250.f);

    sf::RectangleShape rightPaddle{sf::Vector2f{25.f, 100.f}};
    rightPaddle.setPosition(775.f, 250.f);

    sf::RectangleShape ball{sf::Vector2f{25.f, 25.f}};
    ball.setPosition(250.f, 200.f);

    // When started from Windows Explorer the current directory is where main.exe is located; something like C:\projects\dosheme\output
    // ARCADE.TTF resides near main.exe
    sf::Font font;
    if (!font.loadFromFile("res/ARCADE.TTF"))
    {
        // main.exe was probably launched by VS Code and the current directory is the project directory.
        // We need to add output directory to the path.
        if (!font.loadFromFile("output/res/ARCADE.TTF"))
        {
            std::cout << "Cannot load ARCADE.TTF font file" << std::endl;
        }
    }

    sf::Text leftScore;
    leftScore.setFont(font);
    leftScore.setString("0");
    leftScore.setCharacterSize(48);
    leftScore.setPosition(200.f, 0.f);
    leftScore.setStyle(sf::Text::Bold);

    sf::Text rightScore;
    rightScore.setFont(font);
    rightScore.setString("2");
    rightScore.setCharacterSize(48);
    rightScore.setPosition(600.f, 0.f);
    rightScore.setStyle(sf::Text::Bold);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(MY_GREEN);

        window.draw(centerCircle);
        window.draw(centerLine, 2, sf::Lines);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.draw(leftScore);
        window.draw(rightScore);

        window.display();
    }

    return 0;
}
