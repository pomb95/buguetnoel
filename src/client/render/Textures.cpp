#include <render/Textures.h>
#include <iostream>
#include "state.h"
#include "SFML/Graphics.hpp"

render::Textures::Textures() {

};

render::Textures::~Textures() {

};

void render::Textures::load_texture( state::Element& element) {

     std::string path;
     sf::Vector2f scale(0.4,0.4);
     sf::Vector2i dim(650, 900);
    
     if(element.getTypeId()==6){
        path="res/sprite_eni.png";
        scale=sf::Vector2f(0.2,0.2);
        // std::cout<<"eni"<<std::endl;
        sprite.setTextureRect(sf::IntRect(element.getDirection()*225, 0, 225, 225));
     }
    
     if(element.getTypeId()==7){
        path="res/sprite_sram.png";
        scale=sf::Vector2f(0.2,0.2);
        //  std::cout<<"sram"<<std::endl;
        sprite.setTextureRect(sf::IntRect(element.getDirection()*250, 0, 250, 250));
     }
    
     if(element.getTypeId()==8){
        path="res/iop.png";
        scale=sf::Vector2f(0.2,0.2);
     }
    
     if(element.getTypeId()==9){
        path="res/sprite_enu.png";
        scale=sf::Vector2f(0.2,0.2);
        sprite.setTextureRect(sf::IntRect(element.getDirection()*248, 0, 248, 248));
     }

     if(element.getTypeId()==10){  
        path="res/sacri.png";
        scale=sf::Vector2f(0.2,0.2);
        // std::cout<<"sacri"<<std::endl; 
     }
    
     if(element.getTypeId()==3){ 
        path="res/tower.png";
        scale=sf::Vector2f(0.28,0.28);
        // std::cout<<"tower"<<std::endl;        
     }

     if(element.getTypeId()==4){ 
        path="res/center.png";
        scale=sf::Vector2f(0.28,0.28);
        //std::cout<<"center"<<std::endl; 
     }
    
     if(element.getTypeId()==11){
        path="res/coeur.png";
        scale=sf::Vector2f(0.25,0.25);
        //std::cout<<"center"<<std::endl; 
     }

     if(element.getTypeId()==12){  
        path="res/sel-perso.png";
        scale=sf::Vector2f(0.25,0.25);
        //std::cout<<"center"<<std::endl;         
     }
  
     if(element.getTypeId()==13){
	path="res/portee.png";
	scale=sf::Vector2f(0.5,0.5);
	std::cout<<"portee"<<std::endl;
     }
    
     if(!texture.loadFromFile(path)) {
        std::cout << "Erreur de chargement du sprite" << path << std::endl;
     }
    
    
     sprite.setTexture(texture);
     //Mise en place des couleur pour différencier les équipes
     if(element.getTeam()==1){
    	sprite.setColor(sf::Color(150,150,255)); // couleur bleu
     }
     else{ 
	  sprite.setColor(sf::Color(205,90,80)); //couleur rouge
     }
     sprite.setPosition(element.getPosX(),element.getPosY());
     sprite.setScale(scale);
           


    
   

}
