// Gra TOWER DEFENCE 
// Autorzy: Grzegorz Sychowski, Asia Baj 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "game.h"
#include "menu.h"
#include "pozycja.h"
#include "potworek.h"
#include "wierza.h"
#include "potworki\zolnierz.h"


int main()
{
	map game_map;
	menu game_menu;
	game game_gra;

	//// tu na probe tworzymy potworka 
	potworek test;
	test.zaladuj_teksture("bmp/star.bmp");
	test.zapamietaj_pozycje(0,4);

	int a = game_map.load_map("level/1.txt"); // ladowanie poziomu
	game_menu.stan_gry=ekran_startrowy;
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 1280, 720, 32 ), "TOWER DEFENCE" ); // glowne okno aplikacji 
	oknoAplikacji.setVerticalSyncEnabled(true);
	oknoAplikacji.setFramerateLimit(60);
    while( oknoAplikacji.isOpen() )
    {
		oknoAplikacji.clear( sf::Color( 0, 0, 0 ) );
		sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) ) // obsluga zdarzen 
        {
			if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space ) // zamkniecie okna 
			{
				game_menu.stan_gry = gra;
			}
            if( zdarzenie.type == sf::Event::Closed ) // zamkniecie okna 
			{
				//tu np. zapisanie stanu gry
				oknoAplikacji.close();
			}
			if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
			{
				//obs�uga zaj�cia zdarzenia wci�ni�cia klawisza ESC
				oknoAplikacji.close(); //np. zamkni�cie aplikacji
			}
        }

		// tu wszyto co ma sie wyswietlac 
		//i dzialac w grze
		switch (game_menu.stan_gry)
		{
		case ekran_startrowy:


			break;
		case gra:
			game_gra.start(&oknoAplikacji, &game_map);


			//testowy potworek
			test.przesun(&game_map);
			test.rysuj_pozycje(&oknoAplikacji);

			break;
		case pauza:


			break;
			
		default:
			break;
		}
		
		oknoAplikacji.display(); // wyswietlenie okna 

	}

	return 0;
}