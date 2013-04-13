// Gra TOWER DEFENCE 
// Autorzy: Grzegorz Sychowski, Asia Baj 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"

int main()
{
	map game_map;
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "TOWER DEFENCE" ); // glowne okno aplikacji 
    while( oknoAplikacji.isOpen() )
    {
		oknoAplikacji.clear( sf::Color( 0, 0, 0 ) );
		sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) ) // obsluga zdarzen 
        {
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

			
		
		
		oknoAplikacji.display(); // wyswietlenie okna 
    }
    return 0;
}