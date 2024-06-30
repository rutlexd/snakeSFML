#include "assets.cpp"
#include "config.cpp"
#include "objects/snake.cpp"
#include "objects/background.cpp"
#include "objects/buttons.cpp"
#include "objects/apple.cpp"
#include <iostream>
#include <unistd.h>

bool game = true;

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

    Apple apple;

    apple.loadAssets();
    apple.setSprites();
    apple.sentFieldStartPos(background.LEFT_BORDER, background.TOP_BORDER);
    apple.sentMoveStep(snake.MOVE_STEP);
    apple.create();

    RebootButton rebootButton;
    rebootButton.loadAssets();
    rebootButton.setSprites();

    QuitButton quitButton;
    quitButton.loadAssets();
    quitButton.setSprites();

    sf::Music lootApple;
    sf::Music looseGame;

    lootApple.openFromFile("assets/sounds/eatingApple.ogg");
    looseGame.openFromFile("assets/sounds/loose.ogg");

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

            if (sprites["rebootButton"].getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                snake.restart();
                apple.create();
                game = true;
                preMoveSide = Keyboard::Unknown;
            }

            if (sprites["quitButton"].getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                break;
            }
        }

        window.clear(sf::Color::White);

        window.draw(sprites["background"]);
        if (game)
        {
            if (!snake.isPosValid())
            {
                looseGame.stop();
                looseGame.play();
                game = false;
                continue;
            }

            if (clock.getElapsedTime().asMilliseconds() >= SPEED)
            {
                clock.restart();
                moveSide = preMoveSide;
                snake.move(moveSide);
            }
        }
        if (sprites["snakeHead"].getGlobalBounds() == sprites["apple"].getGlobalBounds())
        {
            lootApple.stop();
            lootApple.play();
            snake.increase();
            do
            {
                apple.create();
            } while (apple.inSnake(snake));
                }

        snake.render(window);
        window.draw(sprites["apple"]);
        window.draw(sprites["rebootButton"]);
        window.draw(sprites["quitButton"]);
        window.display();
    }
    return 0;
}