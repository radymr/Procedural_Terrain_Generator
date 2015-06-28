#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ProceduralGenerator.h"
#include "RandomNumberGenerator.h"
#include <iostream>

using namespace std;

void BuildTerrain() {
	//tiles
	sf::Texture T01;
	sf::Texture T02;
	T01.loadFromFile("Tiles/Tiles_0.png");
	T02.loadFromFile("Tiles/Tiles_9.png");

	// define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };


}

int main() {

	// Declare and create a new window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//BACKGROUND
	sf::Texture BG_TX1;
	sf::Sprite BG_SP1;
	BG_TX1.loadFromFile("Tiles/Background_172.png");
	BG_SP1.setTexture(BG_TX1);
	BG_SP1.setPosition(sf::Vector2f(0, 0));
	sf::Texture BG_TX2;
	sf::Sprite BG_SP2;
	BG_TX2.loadFromFile("Tiles/Background_60.png");
	BG_SP2.setTexture(BG_TX2);
	BG_SP2.setPosition(sf::Vector2f(0, 65));

	// The main loop - ends as soon as the window is closed
	while (window.isOpen())
	{
	   // Event processing
	   sf::Event event;
	   while (window.pollEvent(event))
	   {
		   // Request for closing the window
		   if (event.type == sf::Event::Closed)
			   window.close();
	   }

	   // Activate the window for OpenGL rendering
	   window.setActive();

	   // OpenGL drawing commands go here...
	   window.clear(sf::Color::White);

	   // BACKGROUND.
	   window.draw(BG_SP1);
	   window.draw(BG_SP2);

	   //Terrain Generation.
	   BuildTerrain();

	   //Character Generation.

	   
	   // End the current frame and display its contents on screen
	   window.display();
	}
}