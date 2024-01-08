#include "gameManager.hpp"

using namespace sf;

inputManager inp;

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
		window.clear();
		window.display();
	}
}