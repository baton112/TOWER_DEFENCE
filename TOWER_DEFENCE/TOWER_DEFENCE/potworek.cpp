#include "potworek.h"

potworek::potworek(void)
{
	wychylenie_x=0;
	wychylenie_y=0;
	kierunek = right;
}


potworek::~potworek(void)
{
}

void potworek::rysuj_pozycje(sf::RenderWindow *oknoAplikacji)
{
		sf::Sprite kwadrat; 
		kwadrat.setTexture(bitmapa);
		kwadrat.setTextureRect(sf::IntRect(0,0,PIX_UNIT,PIX_UNIT));
		kwadrat.setPosition(x*PIX_UNIT+MAP_X_OFFSET+wychylenie_x,y*PIX_UNIT+MAP_Y_OFFSET+wychylenie_y);
		oknoAplikacji->draw(kwadrat);
}

void potworek::przesun(map *mapa) // jesli duszek true
{
	/*
	if( wychylenie_x==0 && wychylenie_y==0 && )
	{
			int losowanie = 1 + rand()%4;
			if (losowanie-2==kierunek || losowanie +2== kierunek) 
			if(losowanie == up && map::czy_mozna_ruszyc_na_pozycje(x, y))
			{
				kierunek = up;
			}
			else if(losowanie == right && czy_mozna_ruszyc(pozy, pozx+1))
			{
				kierunek = right;
			}
			else if(losowanie == left && czy_mozna_ruszyc(pozy,pozx-1))
			{
				kierunek = left;
			}
			else if(losowanie == down && czy_mozna_ruszyc(pozy+1,pozx))
			{
				kierunek = down;
			}
	}*/
	double speed=0.2;

	if(kierunek == up && mapa->czy_mozna_ruszyc_na_pozycje(x, y-1))
		wychylenie_y-=speed;
	else if(kierunek == right && mapa->czy_mozna_ruszyc_na_pozycje(x+1, y))
		wychylenie_x+=speed;
	else if(kierunek == left &&  mapa->czy_mozna_ruszyc_na_pozycje(x-1,y))
		wychylenie_x-=speed;
	else if(kierunek == down &&  mapa->czy_mozna_ruszyc_na_pozycje(x,y+1))
		wychylenie_y+=speed;      
	///////////jesli nie mozna dalej isc 
	else if(kierunek == up && !mapa->czy_mozna_ruszyc_na_pozycje(x, y-1))
	{
		if( mapa->czy_mozna_ruszyc_na_pozycje(x-1,y)) kierunek=left;
		else if(mapa->czy_mozna_ruszyc_na_pozycje(x+1, y)) kierunek=right;
	}
	else if(kierunek == right && !mapa->czy_mozna_ruszyc_na_pozycje(x+1, y))
	{
		if(mapa->czy_mozna_ruszyc_na_pozycje(x, y-1)) kierunek=up;
		else if(mapa->czy_mozna_ruszyc_na_pozycje(x,y+1)) kierunek=down;
	}
	else if(kierunek == left &&  !mapa->czy_mozna_ruszyc_na_pozycje(x-1,y))
	{
		if(mapa->czy_mozna_ruszyc_na_pozycje(x, y-1)) kierunek=up;
		else if(mapa->czy_mozna_ruszyc_na_pozycje(x,y+1)) kierunek=down;
	}
	else if(kierunek == down &&  !mapa->czy_mozna_ruszyc_na_pozycje(x,y+1))
	{
		if( mapa->czy_mozna_ruszyc_na_pozycje(x-1,y)) kierunek=left;
		else if(mapa->czy_mozna_ruszyc_na_pozycje(x+1, y)) kierunek=right;
	}

	// przesuniecie do nastepnej kratki
	if(wychylenie_x>=PIX_UNIT || wychylenie_x<=-PIX_UNIT)
	{
		if(wychylenie_x>0) x++;
		else x--;
		wychylenie_x=0;
	}else if(wychylenie_y>=PIX_UNIT || wychylenie_y<=-PIX_UNIT)
	{
		if(wychylenie_y>0) y++;
		else y--;
		wychylenie_y=0;
	}
	
}