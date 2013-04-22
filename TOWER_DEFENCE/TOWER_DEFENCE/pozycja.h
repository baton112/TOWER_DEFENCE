#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window.hpp>
#include "map.h"

class pozycja
{
public:
	pozycja(void);
	~pozycja(void);
	void virtual rysuj_pozycje(sf::RenderWindow *oknoAplikacji); // do napisania 
	void zapamietaj_pozycje(int a, int b);
	void zaladuj_teksture(std::string scierzka); 
protected:
	int x; 
	int y;
	sf::Texture bitmapa;

};

