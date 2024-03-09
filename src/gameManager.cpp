#include "gameManager.hpp"

void gameManager::run()
{
	init(window);
	mainLoop(window);
}

void gameManager::init(RenderWindow &window)
{
	window.create(VideoMode(1920, 1080), "grigola", Style::Fullscreen);
	//window.setVerticalSyncEnabled(true);
	framerate.init(25,to_wstring((int) inp.fps),Vector2i(0,0),Vector2i(0,0));
}
void gameManager::mainLoop(RenderWindow &window)
{
	while (window.isOpen())
	{
		inp.processInput(window);
		window.clear(sf::Color::Blue);
		winMan.drawAndUpdate(window);
		framerate.contents = to_wstring((int)inp.fps);
		framerate.update(Vector2i(0,0),window,window.isOpen());
		window.display();
		inp.updateTime();
		if(inp.isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
}