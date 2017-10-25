
#include <render/View.h>
#include <iostream>
#include "state/State.h"
#include "Render.h"
#include "Tiles.h"
#include "Textures.h"


class TileMap : public sf::Drawable, public sf::Transformable {
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j) {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * height];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

TileMap Background;
render::Tiles tile;
std::string level_1_path = "res/level3.png";
std::string tile_texture_path = "res/terre_herbe.png";
sf::Vector2u tile_dim(28, 28);
render::Textures texture;









render::View::View() {
    this->type = type;

}

render::View::~View() {

}

void render::View::init(state::State& state_game) {


        tile.convert(level_1_path);
        std::cout<<  *tile.tiles <<"   "<<tile.tiles[1]<<"   "<<tile.tiles[2]<<"   "<<tile.tiles[3]<<"   "<<tile.tiles[4] << std::endl;
        Background.load(tile_texture_path, tile_dim, tile.tiles, tile.image_dim.x, tile.image_dim.y);
        state_game.iop.setPosX(static_cast<int> (tile.pos_iop.x));
        state_game.iop.setPosY(static_cast<int> (tile.pos_iop.y));
        texture.load_texture(state_game.iop);
        
}

void render::View::add_Sprite(sf::Sprite sprite) {
    list_sprite.push_back(sprite);
}


void render::View::draw(sf::RenderWindow& window) {
       tile.convert(level_1_path);
        std::cout<<  *tile.tiles <<"   "<<tile.tiles[1]<<"   "<<tile.tiles[2]<<"   "<<tile.tiles[3]<<"   "<<tile.tiles[4] << std::endl;
        Background.load(tile_texture_path, tile_dim, tile.tiles, tile.image_dim.x, tile.image_dim.y);
        window.draw(Background);
        window.draw(texture.spritef);
                
 

}