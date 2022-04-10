#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <string> 

#include "../header/vehicule.hpp"
#include "../header/target.hpp"
#include "../header/pursuer.hpp"


int main(int argc, char const *argv[]) {	

	srand(time(NULL));	

    // Initialise un vehicule
    // Vehicule v = Vehicule();

	Target t = Target();
	Pursuer p = Pursuer();


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
		
		// 1.

        // v.update(&window);
        // v.draw(&window);

		// // Draw mouse.
	    // sf::Vector2i mouse = sf::Mouse::getPosition(window);
		// sf::CircleShape circle(20.f);
		// circle.setPosition(mouse.x - 20, mouse.y - 20);
		// window.draw(circle);

		// 2.
		t.update();
		p.update(t);

		t.draw(&window);
		p.draw(&window);


		window.display();
	}


	return 0;
}