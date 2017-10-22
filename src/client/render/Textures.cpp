#include <render/Textures.h>
#include <iostream>

render::Textures::Textures() {

};

render::Textures::~Textures() {

};

void render::Textures::load_texture(const state::Element element) {


    std::string path;
    sf::Vector2f scale(1, 1);
    sf::Vector2i dim(0, 0);
    sf::Vector2i selection(0, 0);




    /*if (element.getType() == 1) {
        path = "res/autres/plage_menu.png";
        dim = sf::Vector2i(358, 700);
        selection.x = 1;


    }
    if (element.getType() == 2) {
        path = "res/autres/carte_verso.png";
        scale = sf::Vector2f(0.75f, 0.75f);
        dim = sf::Vector2i(261, 406);

    }
    if (element.getType() == 3) {
        path = "res/mechants/homme.png";
        scale = sf::Vector2f(1.5f, 1.5f);
        dim = sf::Vector2i(80, 80);

    }*/
   

}

