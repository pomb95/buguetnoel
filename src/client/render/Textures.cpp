#include <render/Textures.h>
#include <iostream>

render::Textures::Textures() {

};

render::Textures::~Textures() {

};

void render::Textures::load_texture(const state::Element element) {

    
    std::string path;
    sf::Vector2f scale(0.4,0.4);
    sf::Vector2i dim(650, 900);
    
    if(element.getTypeId()==6){
        
        path="res/eni.png";
        scale=sf::Vector2f(0.2,0.2);
          std::cout<<"eni"<<std::endl;      
        
    }
    
    if(element.getTypeId()==7){
        
        path="res/sram.png";
        scale=sf::Vector2f(0.2,0.2);
           std::cout<<"sram"<<std::endl;      
        
    }
    
    if(element.getTypeId()==8){
        
        path="res/iop.png";
        scale=sf::Vector2f(0.050,0.05);
                std::cout<<"iop"<<std::endl; 
        
    }
    
    if(element.getTypeId()==9){
        
        path="res/enu.png";
        scale=sf::Vector2f(0.2,0.2);
                std::cout<<"enu"<<std::endl; 
        
    }
    if(element.getTypeId()==10){
        
        path="res/sacri.png";
        scale=sf::Vector2f(0.2,0.2);
                std::cout<<"sacri"<<std::endl; 
        
    }
    
    if(element.getTypeId()==3){
        
        path="res/tower.png";
        scale=sf::Vector2f(0.28,0.28);
                std::cout<<"tower"<<std::endl; 
        
    }
     if(element.getTypeId()==4){
        
        path="res/center.png";
        scale=sf::Vector2f(0.28,0.28);
                std::cout<<"center"<<std::endl; 
        
    }
        
 
    texture.loadFromFile(path);
    
    sprite.setTexture(texture);
    sprite.setPosition(element.getPosX(),element.getPosY());
    sprite.setScale(scale);
           


    
   

}
