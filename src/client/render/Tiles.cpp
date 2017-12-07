#include "render/Tiles.h"
#include <SFML/Graphics.hpp>
#include <iostream>

render::Tiles::Tiles() {

};

render::Tiles::~Tiles() {

};

void render::Tiles::convert(const state::State state_game) {
     sf::Image image1;
     image1.loadFromFile(state_game.path);
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
 			
			   if ((static_cast<int> (image.getPixel(i + 1, j).r) == 0)&&(static_cast<int> (image.getPixel(i - 1, j).r) == 0)&&(static_cast<int>(image.getPixel(i, j + 1).r) == 0)&&(!static_cast<int> (image.getPixel(i, j - 1).r) == 0))
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

                   }
    
                   else tab[i + j * static_cast<int> (image_dim.y)] = 4;

               if (static_cast<int> (image.getPixel(i, j).r) == 150) {
                   list_pos_hero.push_back(sf::Vector2i(i * 28, j * 28));                
               }
            
               if (static_cast<int> (image.getPixel(i, j).b) == 150) {
                   list_pos_center.push_back(sf::Vector2i(i * 28, j * 28));    
               }
            
               if (static_cast<int> (image.getPixel(i, j).b) == 100) {
                   list_pos_tower.push_back(sf::Vector2i(i * 28, j * 28));
                   tab[i + j * static_cast<int> (image_dim.y)] = 4;    
               }
            
          }

    tiles = tab;
}

//L'image est taillée 24 pixels sur 24 

void render::Tiles::getListPosHero() const {
     if (list_pos_hero.size() != 0){                 // Si la liste des positions des héros n'est pas vide, on affiche leur position. 
         std::cout <<"perso 1 : "<< list_pos_hero[0].x<<","<<list_pos_hero[0].y<< std::endl;
         std::cout <<"perso 2 : "<< list_pos_hero[1].x <<","<< list_pos_hero[1].y << std::endl;
         std::cout <<"perso 3 : "<< list_pos_hero[2].x <<","<< list_pos_hero[2].y << std::endl;
  	 std::cout <<"perso 4 : "<< list_pos_hero[3].x<<","<< list_pos_hero[3].y << std::endl;
         std::cout <<"perso 5 : "<< list_pos_hero[4].x<<","<< list_pos_hero[4].y << std::endl;
         std::cout <<"perso 6 : "<< list_pos_hero[5].x<<","<< list_pos_hero[5].y << std::endl;
     }
     else {
           std::cout << "La liste de Hero est vide" << std::endl;
     }

}

// On recupere la position des Tower
void render::Tiles::getListPosTower() const {
     if (list_pos_tower.size() != 0){

        /*for(int i=0;i=sizeof(list_pos_tower) ;i++){   
	      std::cout <<"Tour1 : " << i <<list_pos_tower[i].x <<","<< list_pos_tower[i].y<< std::endl;}}*/

	std::cout <<"Tour1 : " << list_pos_tower[0].x <<","<< list_pos_tower[0].y<< std::endl;  //Il n'y a que 2 Tower dans la partie, (fixé).
        std::cout <<"Tour2 : " << list_pos_tower[1].x<<","<< list_pos_tower[1].y << std::endl;
     }
     else{
          std::cout << "La liste de Tower est vide" << std::endl;
     }

}
//On reucpere la position de chaque QG.
void render::Tiles::getListPosCenter() const {
     if (list_pos_center.size() != 0){
         std::cout <<"Center1_x : "<< list_pos_center[0].x<<","<< list_pos_center[0].y << std::endl; // Le nombre de QG est fixé à 2
	 std::cout <<"Center2_x : "<< list_pos_center[1].x<<","<< list_pos_center[1].y << std::endl;
     }
     else{
          std::cout << "list_pos_hero vide" << std::endl;
     }
}
    
