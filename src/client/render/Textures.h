// Generated by dia2code
#ifndef RENDER__TEXTURES__H
#define RENDER__TEXTURES__H

#include <SFML/Graphics.hpp>
#include <state/Element.h>

namespace render {

  /// class Textures - 
  class Textures {
    // Attributes
  public:
    sf::Sprite sprite;
    sf::Texture texture;
    // Operations
  public:
    Textures ();
    ~Textures ();
    void load_texture (state::Element& element);
    // Setters and Getters
  };

};

#endif
