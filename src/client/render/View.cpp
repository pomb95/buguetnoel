
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
<<<<<<< HEAD
sf::Vector2u tile_dim(28, 28);


=======
sf::Vector2u tile_dim(50, 28);
render::Textures texture1;
render::Textures texture2;
render::Textures texture3;
render::Textures texture4;
render::Textures texture5;
render::Textures texture6;
render::Textures texture7;
render::Textures texture8;
render::Textures texture9;
render::Textures texture10;
render::Textures texture11;
render::Textures texture12;
render::Textures texture13;
render::Textures texture14;
render::Textures texture15;
render::Textures texture16;
>>>>>>> 07717267373da672ce6434b69cf43e6ec8e2b378









render::View::View() {
    this->type = type;

}

render::View::~View() {

}

void render::View::init(state::State& state_game) {

        
        tile.convert(level_1_path);
        Background.load(tile_texture_path, tile_dim, tile.tiles, tile.image_dim.x, tile.image_dim.y);
        
        
<<<<<<< HEAD
        //initialisation de la liste textures
        for (unsigned j = 0; j < state_game.list_element.size(); j++) {
                render::Textures texture;
                list_texture.push_back(texture);
            }
         int nb_hero=0;
            int nb_tower=0;
            int nb_center=0;
        // on donne les positions 
        for (unsigned i = 0; i<state_game.list_element.size(); i++) {
           
            
            if((state_game.list_element[i].getTypeId()==7)||(state_game.list_element[i].getTypeId()==6)||
                    (state_game.list_element[i].getTypeId()==8)||(state_game.list_element[i].getTypeId()==9)||(state_game.list_element[i].getTypeId()==10)){
                
                state_game.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[nb_hero].x));
            state_game.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[nb_hero].y));
            list_texture[i].load_texture(state_game.list_element[i]);
            this->add_Sprite(list_texture[i].sprite);
               nb_hero++;
            }
           
           if(state_game.list_element[i].getTypeId()==3){
                 state_game.list_element[i].setPosX(static_cast<int> (tile.list_pos_tower[nb_tower].x));
            state_game.list_element[i].setPosY(static_cast<int> (tile.list_pos_tower[nb_tower].y));
            list_texture[i].load_texture(state_game.list_element[i]);
            this->add_Sprite(list_texture[i].sprite);
               nb_tower++; 
            }
            
            if(state_game.list_element[i].getTypeId()==4){
                 state_game.list_element[i].setPosX(static_cast<int> (tile.list_pos_center[nb_center].x));
            state_game.list_element[i].setPosY(static_cast<int> (tile.list_pos_center[nb_center].y));
            list_texture[i].load_texture(state_game.list_element[i]);
            this->add_Sprite(list_texture[i].sprite);
            nb_center++;
            }
            
            
            
            }
=======
        state_game.list_eniripsa[0].setPosX(static_cast<int> (tile.list_pos_hero[0].x));
        state_game.list_eniripsa[0].setPosY(static_cast<int> (tile.list_pos_hero[0].y));
        texture1.load_texture(state_game.list_eniripsa[0]);
        list_sprite.push_back(texture1.sprite);
        
        state_game.list_iop[0].setPosX(static_cast<int> (tile.list_pos_hero[1].x));
        state_game.list_iop[0].setPosY(static_cast<int> (tile.list_pos_hero[1].y));
        texture2.load_texture(state_game.list_iop[0]);
        list_sprite.push_back(texture2.sprite);
        
        state_game.list_sram[0].setPosX(static_cast<int> (tile.list_pos_hero[2].x));
        state_game.list_sram[0].setPosY(static_cast<int> (tile.list_pos_hero[2].y));
        texture3.load_texture(state_game.list_sram[0]);
        list_sprite.push_back(texture3.sprite);
        
        state_game.list_enutrof[0].setPosX(static_cast<int> (tile.list_pos_hero[3].x));
        state_game.list_enutrof[0].setPosY(static_cast<int> (tile.list_pos_hero[3].y));
        texture4.load_texture(state_game.list_enutrof[0]);
        list_sprite.push_back(texture4.sprite);

	state_game.list_sacrieur[0].setPosX(static_cast<int> (tile.list_pos_hero[4].x));
        state_game.list_sacrieur[0].setPosY(static_cast<int> (tile.list_pos_hero[4].y));
        texture5.load_texture(state_game.list_sacrieur[0]);
        list_sprite.push_back(texture5.sprite);
	
	state_game.list_sram[1].setPosX(static_cast<int> (tile.list_pos_hero[5].x));
        state_game.list_sram[1].setPosY(static_cast<int> (tile.list_pos_hero[5].y));
        texture6.load_texture(state_game.list_sram[1]);
        list_sprite.push_back(texture6.sprite);

	state_game.list_CommandCenter[0].setPosX(static_cast<int> (tile.list_pos_center[0].x));
        state_game.list_CommandCenter[0].setPosY(static_cast<int> (tile.list_pos_center[0].y));
        texture7.load_texture(state_game.list_CommandCenter[0]);
        list_sprite.push_back(texture7.sprite);

	state_game.list_CommandCenter[1].setPosX(static_cast<int> (tile.list_pos_center[1].x));
        state_game.list_CommandCenter[1].setPosY(static_cast<int> (tile.list_pos_center[1].y));
        texture8.load_texture(state_game.list_CommandCenter[1]);
        list_sprite.push_back(texture8.sprite);

	state_game.list_CommandTower[0].setPosX(static_cast<int> (tile.list_pos_tower[0].x));
        state_game.list_CommandTower[0].setPosY(static_cast<int> (tile.list_pos_tower[0].y));
        texture9.load_texture(state_game.list_CommandTower[0]);
        list_sprite.push_back(texture9.sprite);

	state_game.list_CommandTower[1].setPosX(static_cast<int> (tile.list_pos_tower[1].x));
        state_game.list_CommandTower[1].setPosY(static_cast<int> (tile.list_pos_tower[1].y));
        texture10.load_texture(state_game.list_CommandTower[1]);
        list_sprite.push_back(texture10.sprite);

        

>>>>>>> 07717267373da672ce6434b69cf43e6ec8e2b378
        
        
       
        
        
}

void render::View::add_Sprite(sf::Sprite sprite) {
    list_sprite.push_back(sprite);
}


void render::View::draw(sf::RenderWindow& window) {
    window.draw(Background);
      for (unsigned i = 0; i<list_sprite.size(); i++) {
                window.draw(list_sprite[i]);
                
            }
                
 

}
