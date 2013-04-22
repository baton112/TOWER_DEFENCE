#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <SFML/Graphics/Rect.hpp>

class pozycja
{
public:
	pozycja(void);
	~pozycja(void);
	int x;
	int y;
	void virtual rysuj_pozycje(); // do napisania 
protected:
	sf::Texture bitmapa;

};

