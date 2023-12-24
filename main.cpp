#include "assets.cpp"
#include "config.cpp"
#include "objects/snake.cpp"
#include <iostream>
#include <unistd.h>

int game = 1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGH), "Snake", sf::Style::Close);

    sf::Clock clock;
    window.setFramerateLimit(FPS);

    Texture backgroundSq;
    backgroundSq.loadFromFile("asssets/sprites/background.png");

    Sprite background;

    background.setTexture(backgroundSq);

    background.setPosition(Vector2f(50, 200));

    int moveSide, preMoveSide = -1;

    Snake snake;

    snake.loadAssets();
    snake.setSprites();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == Event::KeyPressed)
        {

            if (event.key.code == Keyboard::Right && moveSide != 1)
            {
                preMoveSide = 0;
            }
            else if (event.key.code == Keyboard::Left && moveSide != 0)
            {
                preMoveSide = 1;
            }
            else if (event.key.code == Keyboard::Up && moveSide != 3)
            {
                preMoveSide = 2;
            }
            else if (event.key.code == Keyboard::Down && moveSide != 2)
            {
                preMoveSide = 3;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(background);
        if (game == 1)
        {
            if (clock.getElapsedTime().asMilliseconds() >= SPEED)
            {
                clock.restart();

                moveSide = preMoveSide;

                if (moveSide == 0)
                {
                    snake.moveRight();
                }
                else if (moveSide == 1)
                {
                    snake.moveLeft();
                }
                else if (moveSide == 2)
                {
                    snake.moveUp();
                }
                else if (moveSide == 3)
                {
                    snake.moveDown();
                }
            }

            snake.render(window);
            window.display();
        }
    }
    return 0;
}