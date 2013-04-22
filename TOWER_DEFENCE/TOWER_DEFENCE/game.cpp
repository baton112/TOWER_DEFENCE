#include "game.h"
#include "map.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


game::game(void)
{
}


game::~game(void)
{
}

void game::start(sf::RenderWindow *oknoAplikacji, map *game_map)
{
	game_map->load_texture();
	game_map->rysuj_plansze(oknoAplikacji);
	//game_map->bitmapa.setPosition( 10, 40 ); 
	//oknoAplikacji->draw( game_map->bitmapa );
}