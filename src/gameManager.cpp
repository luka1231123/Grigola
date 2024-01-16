#include "gameManager.hpp"

void gameManager::run()
{
	init(window);
	mainLoop(window);
}

void gameManager::init(RenderWindow &window)
{
	window.create(VideoMode(1920, 1080), "grigola", Style::Fullscreen);
	window.setFramerateLimit(60);
}
void gameManager::mainLoop(RenderWindow &window)
{
	while (window.isOpen())
	{
		inp.processInput(window);
		window.clear(sf::Color::Blue);
		men.update(window, inp);
		window.display();
		if(!men.isOpen) window.close();
	}
}