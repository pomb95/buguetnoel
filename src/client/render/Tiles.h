// Generated by dia2code
#ifndef RENDER__TILES__H
#define RENDER__TILES__H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace render {

  /// class Tiles - 
  class Tiles {
    // Attributes
  public:
    const int* tiles;
    int size;
    std::vector<sf::Vector2i> list_pos_hero;
    const int* tiles_territory;
    sf::Image image;
    std::vector<sf::Vector2i> list_pos_decor;
    std::vector<sf::Vector2i> list_pos_tower;
    std::vector<sf::Vector2i> list_pos_center;
    sf::Vector2u image_dim;
    // Operations
  public:
    void convert (std::string path);
    Tiles ();
    ~Tiles ();
    void getListPosHero ();
    // Setters and Getters
  };

};

#endif
