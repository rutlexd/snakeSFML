struct Position
{
    int x;
    int y;
};

class Snake
{

private:
    const int MOVE_STEP = 32;
    int size = 3;
    Position snakePos[100] = {50, 200};
    Texture snakeHead;
    Texture snakeBody;

    bool isMoveUp;
    bool isMoveDown;
    bool isMoveLeft;
    bool isMoveRight;

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
    void loadAssets()
    {
        snakeHead.loadFromFile("asssets/sprites/snakeHead_Forward.png");
        assets["snakeHead_Forward"] = snakeHead;

        snakeHead.loadFromFile("asssets/sprites/snakeHead_Down.png");
        assets["snakeHead_Down"] = snakeHead;

        snakeHead.loadFromFile("asssets/sprites/snakeHead_Right.png");
        assets["snakeHead_Right"] = snakeHead;

        snakeHead.loadFromFile("asssets/sprites/snakeHead_Left.png");
        assets["snakeHead_Left"] = snakeHead;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_Vertical.png");
        assets["snakeBody_Vertical"] = snakeBody;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_Horizontal.png");
        assets["snakeBody_Horizontal"] = snakeBody;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_RightDown.png");
        assets["snakeBody_RightDown"] = snakeBody;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_RightUp.png");
        assets["snakeBody_RightUp"] = snakeBody;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_LeftDown.png");
        assets["snakeBody_LeftDown"] = snakeBody;

        snakeBody.loadFromFile("asssets/sprites/snakeBody_LeftUp.png");
        assets["snakeBody_LeftUp"] = snakeBody;
    }

    void setSprites()
    {
        sprites["snakeHead"].setTexture(assets["snakeHead_Forward"]);
        sprites["snakeBody"].setTexture(assets["snakeBody_Horizontal"]);
    }

    void setBodyMoveSide(int indexBody)
    {
        isMoveDown = false;
        isMoveUp = false;
        isMoveRight = false;
        isMoveLeft = false;

        if (snakePos[indexBody].x > snakePos[indexBody + 1].x)
        {
            isMoveRight = true;
        }
        if (snakePos[indexBody].x < snakePos[indexBody + 1].x)
        {
            isMoveLeft = true;
        }
        if (snakePos[indexBody].y < snakePos[indexBody - 1].y)
        {
            isMoveDown = true;
        }
        if (snakePos[indexBody].y > snakePos[indexBody - 1].y)
        {
            isMoveUp = true;
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

                if (isMoveDown)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_RightDown"]);
                }
                else if (isMoveUp)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_RightUp"]);
                }
            }
            else if (isMoveLeft)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Horizontal"]);
                if (isMoveDown)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_LeftDown"]);
                }
                else if (isMoveUp)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_LeftUp"]);
                }
            }
            else if (isMoveDown)
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Vertical"]);
                if (isMoveLeft)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_LeftDown"]);
                }
                else if (isMoveRight)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_RightDown"]);
                }
            }
            else
            {
                sprites["snakeBody"].setTexture(assets["snakeBody_Vertical"]);
                if (isMoveLeft)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_LeftUp"]);
                }
                else if (isMoveRight)
                {
                    sprites["snakeBody"].setTexture(assets["snakeBody_RightUp"]);
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
};
