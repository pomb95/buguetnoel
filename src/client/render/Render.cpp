#include "Render.h"
#include "View.h"
#include <iostream>


int window_width = 1000;
int window_heigth = 800;
sf::Vector2i pos_window(0, 0);
int frame_fps_limit = 60;
std::string window_title = "Dofus";
render::View view;

 render::Render::Render (){
  
    
 }
 
 render::Render::~Render (){
     
 }
 
 
 void render::Render::init(state::State& state_game){
     
    window.create(sf::VideoMode(window_width, window_heigth), window_title);
    window.setPosition(pos_window);
    window.setFramerateLimit(frame_fps_limit);
    view.init(state_game);
    view.draw(window);
    window.display();
      
     
}

 
 void render::Render::Update(state::State& state_game){
    
    
     if(state_game.enable_render==1){
    window.clear();
    view.Update(state_game);
    view.draw(window);
    window.display();
    state_game.enable_render=0;
     }
     
 }
 