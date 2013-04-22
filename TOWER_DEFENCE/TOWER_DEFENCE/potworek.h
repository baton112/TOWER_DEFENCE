#pragma once
#include "pozycja.h"
#include "map.h"

class potworek : public pozycja
{
public:
	int zycie;
	int damage;
	int predkosc;
	int zasieg;
	enum direction
	{
		none, 
		up, 
		right, 
		down, 
		left
	} kierunek;
	void przesun(map *mapa);
	//void virtual atakuj();
	potworek(void);
	~potworek(void);
	void rysuj_pozycje(sf::RenderWindow *oknoAplikacji);
protected:
	double wychylenie_x;
	double wychylenie_y;
};

