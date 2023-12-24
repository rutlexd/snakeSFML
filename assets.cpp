#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

using namespace sf;

struct AssetsHolder
{
    std::map<std::string, Texture> textures;
};

AssetsHolder assets;
std::map<std::string, Sprite> sprites;

