#pragma once

#include <string>

#define MAP_WYSOKOSC 30 
#define MAP_SZEROKOSC 50 

class map
{
public:
	map(void);
	~map(void);
	bool load_map(std::string poziom_sciezka);
	void rysuj_plansze();
private:
	char map_tab[MAP_SZEROKOSC][MAP_WYSOKOSC]; // x, y -- szerokosc , wysokosc 



};

