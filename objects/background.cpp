using namespace sf;

class Background
{

private:

    Texture background;

public:
    const int LEFT_BORDER = 10;
    const int RIGHT_BORDER = 298;
    const int TOP_BORDER = 70;
    const int BOTTOM_BORDER = 328;
    
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

    Sprite getSprite()
    {
        return sprites["background"];
    }

    // int getBorder(string side)
    // {
    //     if (side == "left")
    //     {
    //         return LEFT_BORDER;
    //     }
    //     else if (side == "right")
    //     {
    //         return RIGHT_BORDER;
    //     }
    //     else if (side == "TOP")
    //     {
    //         return TOP_BORDER;
    //     }
    //     else if (side == "bottom")
    //     {
    //         return BOTTOM_BORDER;
    //     }
    // }
};