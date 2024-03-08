#ifndef _gameManager_
#define _gameManager_

#include "relWindows/windowManager.hpp"
#include "gameWorld/gameWorldManager.hpp"
#include "includes.hpp"
#include "ui/text.hpp"

class gameManager
{
public:
	void run();

	string gameState;

	RenderWindow window;

private:
	void init(RenderWindow &Window);

	void mainLoop(RenderWindow &Window);

	inputManager inp;

	windowManager winMan;

	text framerate;
};

#endif