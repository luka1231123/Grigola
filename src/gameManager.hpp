#ifndef _gameManager_
#define _gameManager_

#include "inputManager.hpp"
#include "relWindows/mainMenu.hpp"
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

	mainMenu men;

	text framerate;
};

#endif