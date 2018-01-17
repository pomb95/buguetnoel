#include "Render.h"
#include "View.h"
#include <iostream>
#include <unistd.h>

//Variables globales//

int window_width = 672;
int window_heigth = 672;
sf::Vector2i pos_window(0, 0);
int frame_fps_limit = 60;
std::string window_title = "Dofus";
render::View view;

//méthodes

 render::Render::Render (){

 }

 render::Render::~Render (){

 }


 void render::Render::init(state::State& state_game){

      window.create(sf::VideoMode(window_width, window_heigth), window_title);
      window.setPosition(pos_window);
      window.setFramerateLimit(frame_fps_limit);
      window.setVerticalSyncEnabled(false);	
      view.init(state_game);
      view.draw(window,state_game);
      window.display();


}


 void render::Render::Update(state::State& state_game){

      //if(state_game.enable_render==1){
      window.clear();
      view.Update(state_game);
      view.draw(window,state_game);
      window.display();
      state_game.enable_render=0;
      usleep(10);
   // std::cout <<" Render ::: On a notifié que le rendu a été fait de l'état"<<std::endl;

     //}


    // }
     
 }
