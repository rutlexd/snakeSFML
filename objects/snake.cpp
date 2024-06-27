#include <iostream>

struct Position
{
    int x = 0;
    int y = 40;
};

class Snake
{

private:
    const int DEF_SIZE = 3;
    int size = 3;
    Position snakePos[100];

    Texture snakeHead;
    Texture snakeBody;

    bool isMoveUp;
    bool isMoveDown;
    bool isMoveLeft;
    bool isMoveRight;

    bool wasMoveDown;
    bool wasMoveUp;
    bool wasMoveRight;
    bool wasMoveLeft;

    int leftBord;
    int rightBord;
    int topBord;
    int bottomBord;

    void moveBody()
    {
        for (int i = size; i > 0; i--)
        {
            snakePos[i].x = snakePos[i - 1].x;
            snakePos[i].y = snakePos[i - 1].y;
        }
    }

    void moveUp()
    {
        snakePos[0].y -= MOVE_STEP;
        sprites["snakeHead"].setTexture(assets["snakeHead_Forward"]);
    }

    void moveDown()
    {
        snakePos[0].y += MOVE_STEP;
        sprites["snakeHead"].setTexture(assets["snakeHead_Down"]);
    }

    void moveRight()
    {
        snakePos[0].x += MOVE_STEP;
        sprites["snakeHead"].setTexture(assets["snakeHead_Right"]);
    }

    void moveLeft()
    {
        snakePos[0].x -= MOVE_STEP;
        sprites["snakeHead"].setTexture(assets["snakeHead_Left"]);
    }

public:
    const int MOVE_STEP = 32;

    void increase()
    {
        size++;
    }

    void setStartPos(int x, int y)
    {
        snakePos[0] = {x, y};
    }

    void restart()
    {
        setStartPos(leftBord, topBord);
        setSprites();
        size = DEF_SIZE;
        // score = 0;
    }

    void loadAssets()
    {
        snakeHead.loadFromFile("assets/sprites/snakeHead_Forward.png");
        assets["snakeHead_Forward"] = snakeHead;

        snakeHead.loadFromFile("assets/sprites/snakeHead_Down.png");
        assets["snakeHead_Down"] = snakeHead;

        snakeHead.loadFromFile("assets/sprites/snakeHead_Right.png");
        assets["snakeHead_Right"] = snakeHead;

        snakeHead.loadFromFile("assets/sprites/snakeHead_Left.png");
        assets["snakeHead_Left"] = snakeHead;

        snakeBody.loadFromFile("assets/sprites/snakeBody_Vertical.png");
        assets["snakeBody_Vertical"] = snakeBody;

        snakeBody.loadFromFile("assets/sprites/snakeBody_Horizontal.png");
        assets["snakeBody_Horizontal"] = snakeBody;

        snakeBody.loadFromFile("assets/sprites/snakeBody_UpLeft.png");
        assets["snakeBody_UpLeft"] = snakeBody;

        snakeBody.loadFromFile("assets/sprites/snakeBody_DownLeft.png");
        assets["snakeBody_DownLeft"] = snakeBody;

        snakeBody.loadFromFile("assets/sprites/snakeBody_UpRight.png");
        assets["snakeBody_UpRight"] = snakeBody;

        snakeBody.loadFromFile("assets/sprites/snakeBody_DownRight.png");
        assets["snakeBody_DownRight"] = snakeBody;
    }

    void setSprites()
    {
        sprites["snakeHead"].setTexture(assets["snakeHead_Forward"]);
    }

    void setBodyMoveSide(int indexBody)
    {
        isMoveDown = false;
        isMoveUp = false;
        isMoveRight = false;
        isMoveLeft = false;

        wasMoveDown = false;
        wasMoveUp = false;
        wasMoveRight = false;
        wasMoveLeft = false;

        if (snakePos[indexBody].x > snakePos[indexBody - 1].x)
        {
            isMoveLeft = true;
        }
        else if (snakePos[indexBody].x < snakePos[indexBody - 1].x)
        {
            isMoveRight = true;
        }
        else if (snakePos[indexBody].y < snakePos[indexBody - 1].y)
        {
            isMoveDown = true;
        }
        else if (snakePos[indexBody].y > snakePos[indexBody - 1].y)
        {
            isMoveUp = true;
        }

        if (snakePos[indexBody].x > snakePos[indexBody + 1].x)
        {
            wasMoveRight = true;
        }
        else if (snakePos[indexBody].x < snakePos[indexBody + 1].x)
        {
            wasMoveLeft = true;
        }
        else if (snakePos[indexBody].y < snakePos[indexBody + 1].y)
        {
            wasMoveUp = true;
        }
        else if (snakePos[indexBody].y > snakePos[indexBody + 1].y)
        {
            wasMoveDown = true;
        }
    }

    void render(RenderWindow &window)
    {
        for (int indexBody = 1; indexBody < size; indexBody++)
        {
            setBodyMoveSide(indexBody);

            if (isMoveRight)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Horizontal"]);

                if (wasMoveDown)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_DownRight"]);
                }
                else if (wasMoveUp)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_UpRight"]);
                }
            }
            else if (isMoveLeft)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Horizontal"]);

                if (wasMoveDown)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_DownLeft"]);
                }
                else if (wasMoveUp)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_UpLeft"]);
                }
            }

            else if (isMoveDown)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Vertical"]);

                if (wasMoveLeft)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_UpRight"]);
                }
                else if (wasMoveRight)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_UpLeft"]);
                }
            }
            else if (isMoveUp)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Vertical"]);

                if (wasMoveLeft)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_DownRight"]);
                }
                else if (wasMoveRight)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_DownLeft"]);
                }
            }

            sprites["snakeBody"].setPosition(snakePos[indexBody].x, snakePos[indexBody].y);
            window.draw(sprites["snakeBody"]);
        }

        sprites["snakeHead"].setPosition(snakePos[0].x, snakePos[0].y);
        window.draw(sprites["snakeHead"]);
    }

    void move(Keyboard::Key moveSide)
    {
        moveBody();
        switch (moveSide)
        {
        case Keyboard::Up:
            moveUp();
            break;
        case Keyboard::Down:
            moveDown();
            break;
        case Keyboard::Left:
            moveLeft();
            break;
        case Keyboard::Right:
            moveRight();
            break;

        default:
            break;
        }
    }

    void sentBorders(int left, int right, int top, int bottom)
    {
        leftBord = left;
        rightBord = right;
        topBord = top;
        bottomBord = bottom;
    }

    bool isPosValid()
    {
        if (snakePos[0].x < leftBord || snakePos[0].x > rightBord || snakePos[0].y < topBord || snakePos[0].y > bottomBord)
        {
            return false;
        }
        for (int i = 1; i < size; i++)
        {
            if (snakePos[0].x == snakePos[i].x && snakePos[0].y == snakePos[i].y && size > DEF_SIZE)
            {
                return false;
            }
        }
        return true;
    }

    bool inApple()
    {
        for (int i = 1; i < size; i++)
        {
            if (sprites["apple"].getPosition().x == snakePos[i].x && sprites["apple"].getPosition().y == snakePos[i].y)
            {
                return true;
            }
        }
        return false;
    }
};
