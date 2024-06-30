using namespace sf;

class Background
{

private:

    Texture background;

public:
    const int LEFT_BORDER = 10;
    const int RIGHT_BORDER = 298;
    const int TOP_BORDER = 60;
    const int BOTTOM_BORDER = 348;
    
    void loadAssets()
    {
        background.loadFromFile("assets/sprites/gameField.png");
        assets["background"] = background;
    }

    void setSprite()
    {
        sprites["background"].setTexture(assets["background"]);
        sprites["background"].setPosition(LEFT_BORDER, TOP_BORDER);
    }

};