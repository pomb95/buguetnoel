#include "Render.h"
#include <iostream>

int window_width = 1200;
int window_heigth = 700;
sf::Vector2i pos_window(0, 0);
int frame_fps_limit = 60;
std::string window_title = "Dofus";

 render::Render::Render (){
      window.create(sf::VideoMode(window_width, window_heigth), window_title);
    window.setPosition(pos_window);
    window.setFramerateLimit(frame_fps_limit);
 }
 
 render::Render::~Render (){
     
 }