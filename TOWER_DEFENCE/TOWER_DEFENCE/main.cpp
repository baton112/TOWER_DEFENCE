// Gra TOWER DEFENCE 
// Autorzy: Grzegorz Sychowski, Asia Baj 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "game.h"
#include "menu.h"


int main()
{
	map game_map;
	menu game_menu;
	game game_gra;
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
				//obs³uga zajœcia zdarzenia wciœniêcia klawisza ESC
				oknoAplikacji.close(); //np. zamkniêcie aplikacji
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