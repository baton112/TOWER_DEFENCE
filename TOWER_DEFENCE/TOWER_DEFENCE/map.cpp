#include "map.h"


map::map(void)
{
}

map::~map(void)
{
}


bool map::load_texture()
{
	if(bitmapa.loadFromFile("bmp/map_road.bmp")) 	return 0;
	else return 1; /// blad
	
	
}

bool map::load_map(std::string poziom_sciezka) // 1 - mapa nie zaladowana 
{
	std::fstream plik;
	std::string line;
	plik.open(poziom_sciezka, std::ios::in );
	if( plik.good() == 1)
    {
		for(int i = 0;i<MAP_WYSOKOSC;i++)// po y - liniach w pliku
		{
			getline(plik,line);
			for(int j =0; j<MAP_SZEROKOSC;j++)// po x - znakach w linii 
			{
				map_tab[j][i] = line.substr(0,1); // do tablicy w klasie 
				line.erase(0,1);
			}
		}
        plik.close();
		return 0;
    } 
	return 1;
}

void map::rysuj_plansze(sf::RenderWindow *oknoAplikacji)
{

	// y = i , x = j
	for(int i =0; i < MAP_WYSOKOSC; i++) // po liniach
	{
		for(int j=0; j< MAP_SZEROKOSC; j++) // po kolejnych znakach 
		{
			sf::Sprite kwadrat; 
			kwadrat.setTexture(bitmapa);
			int x, y;
			if(map_tab[j][i]=="1")
			{
				x=0; y = 0;
			}
			else if(map_tab[j][i]=="2")
			{
				x = 1;
				y = 0;
			}
			else if(map_tab[j][i]=="3")
			{
				x = 2;
				y = 0;
			}
			else if(map_tab[j][i]=="4")
			{
				x = 3;
				y = 0;
			}
			else if(map_tab[j][i]=="-" || map_tab[j][i]=="P")
			{
				x = 0;
				y = 1;
			}
			else if(map_tab[j][i]=="|")
			{
				x = 1;
				y = 1;
			}
			else 
			{
				x = 3;
				y = 1;
			}

			kwadrat.setTextureRect(sf::IntRect(x*PIX_UNIT,y*PIX_UNIT,PIX_UNIT,PIX_UNIT));
			kwadrat.setPosition(j*PIX_UNIT+MAP_X_OFFSET,i*PIX_UNIT+MAP_Y_OFFSET);
			oknoAplikacji->draw(kwadrat);
			/*
			obrazek.setTextureRect(IntRect(kolumna*bokpola,rzad*bokpola,bokpola,bokpola));
			obrazek.setPosition(x,y);
			okno.Okno->draw(obrazek);*/
			
		}

	}


}


