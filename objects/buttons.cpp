class RebootButton
{
private:
    Texture rebootButton;

public:
    void loadAssets()
    {
        rebootButton.loadFromFile("assets/sprites/rebootBtn.png");
        assets["rebootButton"] = rebootButton;
    }

    void setSprites()
    {
        sprites["rebootButton"].setTexture(assets["rebootButton"]);
        sprites["rebootButton"].setPosition(261, 1);
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
        assets["quitButton"] = quitButton;
    }

    void setSprites()
    {
        sprites["quitButton"].setTexture(assets["quitButton"]);
        sprites["quitButton"].setPosition(298, 1);
    }
};