#include "gameManager.hpp"

void gameManager::run()
{
	init(window);
	mainLoop(window);
}

void gameManager::init(RenderWindow &window)
{
	gmMan.init();
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
		gmMan.updateTileMap();
		gmMan.checks();
		winMan.drawAndUpdate(window, inp);
		framerate.contents = to_wstring((int)inp.fps);
		framerate.update(Vector2i(0,0),window,inp,window.isOpen());
		window.display();
		inp.updateTime();
	}
}