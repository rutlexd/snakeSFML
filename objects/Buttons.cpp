class RebootButton
{
private:
    Texture rebootButton;

public:
    void loadAssets()
    {
        rebootButton.loadFromFile("assets/sprites/rebootBtn.png");
        assets["RebootButton"] = rebootButton;
    }

    void setSprites()
    {
        sprites["RebootButton"].setTexture(assets["RebootButton"]);
        sprites["RebootButton"].setPosition(261, 1);
    }
};

class QuitButton
{
private:
    Texture quitButton;

public:
    void loadAssets()
    {
        quitButton.loadFromFile("assets/sprites/quitBtn.png");
        assets["QuitButton"] = quitButton;
    }

    void setSprites()
    {
        sprites["QuitButton"].setTexture(assets["QuitButton"]);
        sprites["QuitButton"].setPosition(298, 1);
    }
};