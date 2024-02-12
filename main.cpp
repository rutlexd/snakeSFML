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
    backgroundSq.loadFromFile("asssets/sprites/gameField.png");

    Sprite background;

    background.setTexture(backgroundSq);

    background.setPosition(Vector2f(50, 200));

    Keyboard::Key moveSide = Keyboard::Unknown;
    Keyboard::Key preMoveSide = Keyboard::Unknown;

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

            Keyboard::Key key = event.key.code;
            if (key == Keyboard::Right && moveSide != Keyboard::Left || key == Keyboard::Left && moveSide != Keyboard::Right ||
                key == Keyboard::Up && moveSide != Keyboard::Down || key == Keyboard::Down && moveSide != Keyboard::Up)
            {
                preMoveSide = key;
            }
        }

        window.clear(sf::Color::Magenta);

        window.draw(background);
        if (game == 1)
        {
            if (clock.getElapsedTime().asMilliseconds() >= SPEED)
            {
                clock.restart();
                moveSide = preMoveSide;
                snake.move(moveSide);
            }
            
             snake.render(window);
            window.display();
        }
    }
    return 0;
}