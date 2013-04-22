#pragma once


#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Rect.hpp>

// wielkosc planszy w kadratach
#define MAP_WYSOKOSC 10
#define MAP_SZEROKOSC 15

//przesuniecie planszy wzgledem lewego gornego rogu
#define MAP_X_OFFSET 20
#define MAP_Y_OFFSET 10

// PIX_UNIT - losc pikseli w boku w kwadracie tekstury
#define PIX_UNIT 60


class map
{
public:
	map(void);
	~map(void);
	bool load_map(std::string poziom_sciezka);
	void rysuj_plansze(sf::RenderWindow *oknoAplikacji);
	bool load_texture();
private:
	std::string map_tab[MAP_SZEROKOSC][MAP_WYSOKOSC]; // x, y -- szerokosc , wysokosc 
	sf::Texture bitmapa;


};

