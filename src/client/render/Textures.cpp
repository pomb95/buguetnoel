#include <render/Textures.h>
#include <iostream>

render::Textures::Textures() {

};

render::Textures::~Textures() {

};

void render::Textures::load_texture(const state::Element element) {


    std::string path;
    sf::Vector2f scale(0.1,0.1);
    sf::Vector2i dim(650, 900);
    texture.loadFromFile("res/iop.png");
    
    sprite.setTexture(texture);
    sprite.setPosition(element.getPosX(),element.getPosY());
    sprite.setScale(scale);
           


    
   

}

