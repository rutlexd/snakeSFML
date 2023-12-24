struct Position
{
    int x = 50;
    int y = 200;
};

class Snake
{

private:
    int size = 3;
    Position snakePos[100];

    void updateBody()
    {
        for (int i = size; i > 0; i--)
        {
            snakePos[i].x = snakePos[i - 1].x;
            snakePos[i].y = snakePos[i - 1].y;
        }
    }

public:
    void moveUp()
    {
        updateBody();
        snakePos[0].y -= 32;
    }

    void moveDown()
    {
        updateBody();
        snakePos[0].y += 32;
    }

    void moveRight()
    {
        updateBody();
        snakePos[0].x += 32;
    }

    void moveLeft()
    {
        updateBody();
        snakePos[0].x -= 32;
    }

    void loadAssets()
    {
        Texture snakeHead;
        snakeHead.loadFromFile("asssets/sprites/snakeHead_Forward.png");
        assets.textures["snakeHead"] = snakeHead;

        Texture snakeBody;
        snakeBody.loadFromFile("asssets/sprites/snakeBody.png");
        assets.textures["snakeBody"] = snakeBody;
    }

    void setSprites()
    {
        sprites["snakeHead"].setTexture(assets.textures["snakeHead"]);
        sprites["snakeBody"].setTexture(assets.textures["snakeBody"]);
    }

    void render(RenderWindow &window)
    {
        for (int i = 1; i < size; i++)
        {
            sprites["snakeBody"].setPosition(snakePos[i].x, snakePos[i].y);
            window.draw(sprites["snakeBody"]);
        }

        sprites["snakeHead"].setPosition(snakePos[0].x, snakePos[0].y);
        window.draw(sprites["snakeHead"]);
    }
};
