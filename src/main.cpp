#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

const float BALL_SIZE = 30.f;
const float BALL_START_POSITION_X = 200.f;
const float BALL_START_POSITION_Y = 150.f;
float BALL_POSITION_X;
float BALL_POSITION_Y;
float dx = 0.1; //ball movement increment on X axis
float dy = 0.1; //ball movement increment on Y axis
const float PADDLE_SIZE_X = 20.f;
const float PADDLE_SIZE_Y = 100.f;
const float LEFT_PADDLE_START_POSITION_X = 0.f;
const float LEFT_PADDLE_START_POSITION_Y = 250.f;
const float RIGHT_PADDLE_START_POSITION_X = 780.f;
const float RIGHT_PADDLE_START_POSITION_Y = 250.f;
//HERE WE CAN SET THE PADDLES POSITION RELATIVE TO WINDOW SIZE - TO BE DISCUSSED

const float MIDDLE_CIRCLE_DIAMETER = 100.f;
const float LEFT_SCORE_POSITION_X = 200.f;
const float LEFT_SCORE_POSITION_Y = 0.f;
const float RIGHT_SCORE_POSITION_X = 600.f;
const float RIGHT_SCORE_POSITION_Y = 0.f;
const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 600;
const int SCORE_CHARACTER_SIZE = 48;
const sf::Color MY_GREEN{0, 128, 0};

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Pong clone");
    sf::RectangleShape LEFT_PADDLE(sf::Vector2f(PADDLE_SIZE_X, PADDLE_SIZE_Y));
    sf::RectangleShape RIGHT_PADDLE(sf::Vector2f(PADDLE_SIZE_X, PADDLE_SIZE_Y));
    sf::RectangleShape BALL(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    sf::Vertex MIDDLE_NET[] =
        {
            sf::Vertex(sf::Vector2f(400.f, 0.f)),
            sf::Vertex(sf::Vector2f(400.f, 600.f)),
        };
    sf::CircleShape MIDDLE_CIRCLE(MIDDLE_CIRCLE_DIAMETER);

    sf::Font font;
    if (!font.loadFromFile("/res/ARCADE.TTF"))
    {
        if (!font.loadFromFile("output/res/ARCADE.TTF"))
        {
            std::cout << "Cannot load ARCADE.TTF from file" << std::endl;
        }
    };
    sf::Text LEFT_SCORE;
    sf::Text RIGHT_SCORE;
    LEFT_SCORE.setFont(font);
    RIGHT_SCORE.setFont(font);
    LEFT_SCORE.setString("0");
    LEFT_SCORE.setCharacterSize(SCORE_CHARACTER_SIZE);
    LEFT_SCORE.setPosition(LEFT_SCORE_POSITION_X, LEFT_SCORE_POSITION_Y);
    LEFT_SCORE.setStyle(sf::Text::Bold);
    RIGHT_SCORE.setString("0");
    RIGHT_SCORE.setCharacterSize(SCORE_CHARACTER_SIZE);
    RIGHT_SCORE.setPosition(RIGHT_SCORE_POSITION_X, RIGHT_SCORE_POSITION_Y);
    RIGHT_SCORE.setStyle(sf::Text::Bold);
    LEFT_PADDLE.setPosition(LEFT_PADDLE_START_POSITION_X, LEFT_PADDLE_START_POSITION_Y);
    RIGHT_PADDLE.setPosition(RIGHT_PADDLE_START_POSITION_X, RIGHT_PADDLE_START_POSITION_Y);
    BALL.setPosition(BALL_START_POSITION_X, BALL_START_POSITION_Y);
    MIDDLE_CIRCLE.setPosition(300, 200);
    MIDDLE_CIRCLE.setFillColor(MY_GREEN);
    MIDDLE_CIRCLE.setOutlineThickness(1);

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
        //move left paddle with keys A and Q

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (LEFT_PADDLE.getPosition().y < WINDOW_SIZE_Y - LEFT_PADDLE.getSize().y)
                LEFT_PADDLE.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            if (LEFT_PADDLE.getPosition().y > 0)
                LEFT_PADDLE.move(0.f, -0.1f);
        }
        //move right paddle with keys P and L

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (RIGHT_PADDLE.getPosition().y < WINDOW_SIZE_Y - RIGHT_PADDLE.getSize().y)
                RIGHT_PADDLE.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (RIGHT_PADDLE.getPosition().y > 0)
                RIGHT_PADDLE.move(0.f, -0.1f);
        }
        //ball movement

        BALL_POSITION_X = BALL_START_POSITION_X;
        BALL_POSITION_Y = BALL_START_POSITION_Y;

        if (BALL_POSITION_Y >= WINDOW_SIZE_Y - BALL_SIZE)
        {
            dy = -dy;
        }
        else if (BALL_POSITION_Y <= 0)
        {
            dy = -dy;
            BALL_POSITION_Y = 0;
        }

        if (BALL_POSITION_X <= 0)
        {
            sf::sleep(sf::seconds(0.5f));
            dx = -dx;
            BALL_POSITION_X = 0;
        }
        else if (BALL_POSITION_X >= WINDOW_SIZE_X - BALL_SIZE)
        {
            sf::sleep(sf::seconds(0.5f));
            dx = -dx;
        }
        BALL_POSITION_X = BALL_POSITION_X + dx;
        BALL_POSITION_Y = BALL_POSITION_Y + dy;
        BALL.setPosition(BALL_POSITION_X, BALL_POSITION_Y);
        if (BALL_POSITION_X <= PADDLE_SIZE_X)
        {
            if (BALL_POSITION_Y > LEFT_PADDLE.getPosition().y - BALL_SIZE && BALL_POSITION_Y < LEFT_PADDLE.getPosition().y + PADDLE_SIZE_Y)
            {
                dx = -dx;
                BALL_POSITION_X = PADDLE_SIZE_X;
            }
        }

        if (BALL_POSITION_X >= WINDOW_SIZE_X - BALL_SIZE - PADDLE_SIZE_X)
        {
            if (BALL_POSITION_Y > RIGHT_PADDLE.getPosition().y - BALL_SIZE && BALL_POSITION_Y < RIGHT_PADDLE.getPosition().y + PADDLE_SIZE_Y)
            {
                dx = -dx;
                BALL_POSITION_X = WINDOW_SIZE_X - BALL_SIZE - PADDLE_SIZE_X;
            }
        }
        window.clear(MY_GREEN);
        window.draw(LEFT_PADDLE);
        window.draw(RIGHT_PADDLE);
        window.draw(MIDDLE_CIRCLE);
        window.draw(MIDDLE_NET, 2, sf::Lines);
        window.draw(RIGHT_SCORE);
        window.draw(LEFT_SCORE);
        window.draw(BALL);
        window.display();
    }

    return 0;
}