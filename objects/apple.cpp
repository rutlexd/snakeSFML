#include <random>
#include <iostream>

class Apple
{

private:
    Texture apple;
    int x;
    int y;
    int startX;
    int startY;

    std::random_device rd; 
public:
    void loadAssets()
    {
        apple.loadFromFile("assets/sprites/apple.png");
        assets["apple"] = apple;
    }

    void setSprites()
    {
        sprites["apple"].setTexture(assets["apple"]);
    }

    void getFieldStartPos(int x, int y)
    {
        startX = x;
        startY = y;
    }

    void generatePos()
    {
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distr(1, 9);
        int x = distr(gen);
        std::cout << "x: " << x << std::endl;

        int y = distr(gen);
        std::cout << "y: " << y << std::endl;

        sprites["apple"].setPosition(startX + (32 * x), startY + (32 * y));
    }
};