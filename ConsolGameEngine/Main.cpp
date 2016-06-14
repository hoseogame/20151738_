#include <iostream>

#include "ConsolGameEngine.h"

int main()
 {
	ConsolGameEngine engine;

	engine.MakeGame();

	while (engine.SelectGame())
	{
		engine.Init();

		while (engine.Input())
		{
			engine.Update();
			engine.Render();
		}

		engine.Release();
	}

	engine.DeleteGame();

	return 0;
}