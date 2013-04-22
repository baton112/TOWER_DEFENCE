#include "pozycja.h"


pozycja::pozycja(void)
{
}


pozycja::~pozycja(void)
{
}

void pozycja::zapamietaj_pozycje(int a, int b)
{
	x=a;
	y=b;
}

void pozycja::zaladuj_teksture(std::string sciezka)
{
	bitmapa.loadFromFile(sciezka);
}
	
void pozycja::rysuj_pozycje(sf::RenderWindow *oknoAplikacji)
{
		sf::Sprite kwadrat; 
		kwadrat.setTexture(bitmapa);
		kwadrat.setTextureRect(sf::IntRect(0,0,PIX_UNIT,PIX_UNIT));
		kwadrat.setPosition(x*PIX_UNIT+MAP_X_OFFSET,y*PIX_UNIT+MAP_Y_OFFSET);
		oknoAplikacji->draw(kwadrat);
}