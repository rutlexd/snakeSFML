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
    
    Texture redSq;
    redSq.loadFromFile("/home/rutle/progs/snake/asssets/sprites/red32x32.png");

    Sprite red;
    red.setTexture(redSq);

    Texture greenSq;
    greenSq.loadFromFile("/home/rutle/progs/snake/asssets/sprites/green32x32.png");

    Sprite snake;
    snake.setTexture(greenSq);


    Texture backgroundSq;
    backgroundSq.loadFromFile("/home/rutle/progs/snake/asssets/sprites/background.png");

    Sprite background;

    background.setTexture(backgroundSq);

    background.setPosition(Vector2f(50, 200));

    int moveSide, preMoveSide;

    Position snakePos[100];

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        
        }

        if (event.type == Event::KeyPressed){
        
            if (event.key.code == Keyboard::Right && moveSide != 1){
                preMoveSide = 0; 
            }
            else if (event.key.code == Keyboard::Left && moveSide != 0){
                preMoveSide = 1;
            }
            else if (event.key.code == Keyboard::Up && moveSide != 3){
                preMoveSide = 2;
            }
            else if (event.key.code == Keyboard::Down && moveSide != 2){
                preMoveSide = 3;
            }
        }
        

    
        window.clear(sf::Color::White);

        window.draw(background);
        if(game == 1){
            if (clock.getElapsedTime().asMilliseconds() >= SPEED)
            {   
                clock.restart();
                
                moveSide = preMoveSide;

                for (int i = size; i > 0; i--){
                    snakePos[i].x = snakePos[i - 1].x;
                    snakePos[i].y = snakePos[i - 1].y;
                }
                snakePos[0] = getSnakePos(moveSide);
            }
        
            for (int i = 0; i < size; i++){
                snake.setPosition(snakePos[i].x, snakePos[i].y);
                red.setPosition(snakePos[0].x, snakePos[0].y);
                window.draw(red);
                window.draw(snake);
            }
        
            
            window.display();
        }
    }
    return 0;
}