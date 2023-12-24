#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

using namespace sf;

struct AssetsHolder{
    std::map<std::string, Texture*> textures;
};

std::map<std::string, Sprite> sprites;  

void load(AssetsHolder &assets){
    sprites["background"].setTexture(*assets.textures["background"]);
}


