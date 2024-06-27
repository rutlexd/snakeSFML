#include "assets.cpp"
#include "config.cpp"
#include "objects/snake.cpp"
#include "objects/background.cpp"
#include "objects/Buttons.cpp"
#include <iostream>
#include <unistd.h>

int game = 1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGH), "Snake", sf::Style::Close);

    sf::Clock clock;
    window.setFramerateLimit(FPS);

    Keyboard::Key moveSide = Keyboard::Unknown;
    Keyboard::Key preMoveSide = Keyboard::Unknown;

    Background background;

    background.loadAssets();
    background.setSprite();

    Snake snake;
    snake.setStartPos(background.LEFT_BORDER, background.TOP_BORDER);
    snake.loadAssets();
    snake.setSprites();
    snake.sentBorders(background.LEFT_BORDER, background.RIGHT_BORDER, background.TOP_BORDER, background.BOTTOM_BORDER);

    RebootButton rebootButton;

    rebootButton.loadAssets();
    rebootButton.setSprites();

    QuitButton quitButton;

    quitButton.loadAssets();
    quitButton.setSprites();

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

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);

            if (sprites["RebootButton"].getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                snake.restart();
                game = 1;
                preMoveSide = Keyboard::Unknown;
            }
            
            if (sprites["QuitButton"].getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                break;
            }
        }

        window.clear(sf::Color::White);

        window.draw(sprites["background"]);
        if (game == 1)
        {
            if (clock.getElapsedTime().asMilliseconds() >= SPEED)
            {
                clock.restart();
                moveSide = preMoveSide;
                snake.move(moveSide);
                if (!snake.inField())
                {
                    game = 0;
                }
            }
        }
        snake.render(window);
        window.draw(sprites["RebootButton"]);
        window.draw(sprites["QuitButton"]);
        window.display();
    }
    return 0;
}