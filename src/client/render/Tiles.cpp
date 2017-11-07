#include "render/Tiles.h"
#include <SFML/Graphics.hpp>
#include <iostream>

render::Tiles::Tiles() {

};

render::Tiles::~Tiles() {

};

void render::Tiles::convert(std::string path) {
    sf::Image image1;

    image1.loadFromFile(path);
    this->image = image1;
    image_dim = image.getSize();


    int* tab = new int[static_cast<int> (image_dim.x)*static_cast<int> (image_dim.y)];
    for (unsigned j = 0; j < image_dim.y; j++)
        for (unsigned i = 0; i < image_dim.x; i++) {
            if (!static_cast<int> (image.getPixel(i, j).r) == 0)
                tab[i + j * static_cast<int> (image_dim.y)] = 4;

            else
                if ((i > 0)&&(i < image_dim.x - 1)&&(j > 0)&&(j < image_dim.y - 1)) {
                if (static_cast<int> (image.getPixel(i, j).r) == 0) {


                    if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(!static_cast<int> (image.getPixel(i, j - 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 7;
                    if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)&&(!static_cast<int> (image.getPixel(i, j + 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 1;
                    if ((static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)&&(static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i - 1, j).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 5;
                    if ((static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)&&(static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i + 1, j).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 3;



                    if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(!static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i, j - 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 8;
                    if ((static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(!static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i, j - 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 6;
                    if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)&&(!static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i, j + 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 2;
                    if ((static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)&&(!static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(!static_cast<int> (image.getPixel(i, j + 1).r) == 0))
                        tab[i + j * static_cast<int> (image_dim.y)] = 0;



                    if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j + 1).r) == 0)&&(static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i, j - 1).r) == 0)) {
                        if (!static_cast<int> (image.getPixel(i + 1, j + 1).r) == 0)
                            tab[i + j * static_cast<int> (image_dim.y)] = 0;

                        if (!static_cast<int> (image.getPixel(i + 1, j - 1).r) == 0)
                            tab[i + j * static_cast<int> (image_dim.y)] = 6;

                        if (!static_cast<int> (image.getPixel(i - 1, j + 1).r) == 0)
                            tab[i + j * static_cast<int> (image_dim.y)] = 2;

                        if (!static_cast<int> (image.getPixel(i - 1, j - 1).r) == 0)
                            tab[i + j * static_cast<int> (image_dim.y)] = 8;
                    }




                }
            } else tab[i + j * static_cast<int> (image_dim.y)] = 4;

            if (static_cast<int> (image.getPixel(i, j).r) == 150) {
                list_pos_hero.push_back(sf::Vector2i(i * 28, j * 28));
                
            }
            
            if (static_cast<int> (image.getPixel(i, j).b) == 150) {
                list_pos_center.push_back(sf::Vector2i(i * 28, j * 28));
                
            }
            
            if (static_cast<int> (image.getPixel(i, j).g) == 150) {
                list_pos_tower.push_back(sf::Vector2i(i * 28, j * 28));
                
            }
            
           

       

        }



    tiles = tab;
}

void render::Tiles::getListPosHero() {
    if (list_pos_hero.size() != 0){
        std::cout << "perso1_x : " <<list_pos_hero[0].x << std::endl;
        std::cout << "perso1_y : "<<list_pos_hero[0].y << std::endl;
        std::cout <<"perso2_x : "<< list_pos_hero[1].x << std::endl;
        std::cout <<"perso2_y : "<< list_pos_hero[1].y << std::endl;
        std::cout <<"perso3_x : "<< list_pos_hero[2].x << std::endl;
        std::cout <<"perso3_y : "<< list_pos_hero[2].y << std::endl;
    }
    else
    {
        std::cout << "list_pos_hero vide" << std::endl;
    }
}
