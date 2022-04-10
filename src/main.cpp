#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <string> 

#include "../header/vehicule.hpp"



int main(int argc, char const *argv[]) {	

	srand(time(NULL));	

    // Initialise un vehicule
    Vehicule v = Vehicule();

	// Initialisation de l'antialiasing et de la fenêtre.
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(SIZE_W,SIZE_H), "PVector test", sf::Style::Default, settings);
	window.setFramerateLimit(60);


	// Main loop.
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Wait event.
			if(event.type == sf::Event::Closed) window.close();		// Close window.
		}
		
		// Clean screen.
		window.clear(sf::Color(25,25,100,80));
		
        v.update();
        v.draw(&window);


		window.display();
	}


	return 0;
}