#include "map.h"
#include <fstream>
#include <iostream>
#include <string>

map::map(void)
{
}

map::~map(void)
{
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
				map_tab[i][j] = (char) line.substr(0,1).c_str(); // do tablicy w klasie 
				line.erase(0,1);
			}
		}
        plik.close();
		return 0;
    }
	return 1;
}

void rysuj_plansze()
{
	for(int i =0; i < 29; i++) // po pliniach
	{
		for(int j=0; j< 31; j++) // po kolejnych znakach 
		{
			
		}

	}


}
