#include <random>

class Apple
{

private:
    Texture apple;
    int x;
    int y;
    int startX;
    int startY;
    int moveStep;
    std::random_device rd;

public:
    void sentMoveStep(int moveSt)
    {
        moveStep = moveSt;
    }
    void loadAssets()
    {
        apple.loadFromFile("assets/sprites/apple.png");
        assets["apple"] = apple;
    }

    void setSprites()
    {
        sprites["apple"].setTexture(assets["apple"]);
    }

    void sentFieldStartPos(int x, int y)
    {
        startX = x;
        startY = y;
    }

    void generatePos()
    {
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 9);
        int num;

        num = distr(gen);

        x = startX + (moveStep * num);

        num = distr(gen);

        y = startY + (moveStep * num);
    }

    void create()
    {
        generatePos();
        sprites["apple"].setPosition(x, y);
    }

    bool inSnake(Snake snake)
    {
        for (int i = 1; i < snake.getSize(); i++)
        {
            if (sprites["apple"].getPosition().x == snake.snakePos[i].x && sprites["apple"].getPosition().y == snake.snakePos[i].y)
            {
                return true;
            }
        }
        return false;
    }
};