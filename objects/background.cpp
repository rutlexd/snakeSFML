using namespace sf;

class Background
{

private:

    Texture background;

public:
    const int LEFT_BORDER = 0;
    const int RIGHT_BORDER = 320;
    const int TOP_BORDER = 40;
    const int BOTTOM_BORDER = 320;
    
    void loadAssets()
    {
        background.loadFromFile("asssets/sprites/gameField.png");
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