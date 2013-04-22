#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"

class game
{
public:
	void start(sf::RenderWindow *oknoAplikacji, map *game_map);
	game(void);
	~game(void);
private:
	void przesun_potworki();
	void rysuj_potworki();
};

