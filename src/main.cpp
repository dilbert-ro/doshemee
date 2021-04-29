#include <iostream>
#include <SFML/Graphics.hpp>

// TODO: this is a way to long main function. We'll split it into pieces later.
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

    // TODO: re-write the main loop to get a constant frame rate.
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

        // Update left paddle position based on keyboard input.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // Prevent the paddle to go down off screen
            if (leftPaddle.getPosition().y < 600 - leftPaddle.getSize().y)
                leftPaddle.move(0.f, 1.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            // Prevent the paddle to go up off screen
            if (leftPaddle.getPosition().y > 0)
                leftPaddle.move(0.f, -1.f);
        }

        // Update right paddle position based on keyboard input.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (rightPaddle.getPosition().y < 600 - rightPaddle.getSize().y)
                rightPaddle.move(0.f, 1.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (rightPaddle.getPosition().y > 0)
                rightPaddle.move(0.f, -1.f);
        }

        // Clear the screen and redraw all graphics.
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
